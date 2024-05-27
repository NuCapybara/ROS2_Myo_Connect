#!/usr/bin/env python3

from __future__ import print_function
from struct import pack, unpack

import argparse
import enum
import re
import struct
import sys
import threading
import time
import math
import serial
from serial.tools.list_ports import comports
from common import *
import rclpy
import rclpy.callback_groups
import rclpy.exceptions
from rclpy.node import Node
from std_msgs.msg import (
    String,
    UInt8,
    Header,
    MultiArrayLayout,
    MultiArrayDimension,
    Float64MultiArray,
)
from geometry_msgs.msg import Quaternion, Vector3
from sensor_msgs.msg import Imu
from myo_interfaces.msg import MyoArm, EmgArray
import os


def multichr(ords):
    if sys.version_info[0] >= 3:
        return bytes(ords)
    else:
        return "".join(map(chr, ords))


def multiord(b):
    if sys.version_info[0] >= 3:
        return list(b)
    else:
        return map(ord, b)


class Arm(enum.Enum):
    UNKNOWN = 0
    RIGHT = 1
    LEFT = 2


class XDirection(enum.Enum):
    UNKNOWN = 0
    X_TOWARD_WRIST = 1
    X_TOWARD_ELBOW = 2


class Pose(enum.Enum):
    REST = 0
    FIST = 1
    WAVE_IN = 2
    WAVE_OUT = 3
    FINGERS_SPREAD = 4
    THUMB_TO_PINKY = 5
    UNKNOWN = 255


class Packet(object):
    def __init__(self, ords):
        self.typ = ords[0]
        self.cls = ords[2]
        self.cmd = ords[3]
        self.payload = multichr(ords[4:])

    def __repr__(self):
        return "Packet(%02X, %02X, %02X, [%s])" % (
            self.typ,
            self.cls,
            self.cmd,
            " ".join("%02X" % b for b in multiord(self.payload)),
        )


class BT(object):
    """Implements the non-Myo-specific details of the Bluetooth protocol."""

    def __init__(self, tty):
        self.ser = serial.Serial(port=tty, baudrate=9600, dsrdtr=1, timeout=0.5)
        self.serfd = self.ser.fd
        self.buf = []
        self.lock = threading.Lock()
        self.handlers = []

    ## internal data-handling methods
    def recv_packet(self, timeout=None, debug=False):
        if debug:
            print("!!!!!!!!!!!!!!!!")
        t0 = time.time()

        self.ser.timeout = None
        while timeout is None or time.time() < t0 + timeout:
            if debug:
                print(timeout)
            if timeout is not None:
                self.ser.timeout = t0 + timeout - time.time()
            c = self.ser.read()
            # time.sleep(0.1)
            if debug:
                print("333333")
            if not c:
                if debug:
                    print("2")
                return None

            ret = self.proc_byte(ord(c))
            if ret:
                if ret.typ == 0x80:
                    self.handle_event(ret)
                if debug:
                    print(ret)
                return ret

    def recv_packets(self, timeout=0.5):
        res = []
        t0 = time.time()
        while time.time() < t0 + timeout:
            p = self.recv_packet(t0 + timeout - time.time())
            if not p:
                return res
            res.append(p)
        return res

    def proc_byte(self, c):
        if not self.buf:
            if c in [0x00, 0x80, 0x08, 0x88]:
                self.buf.append(c)
            return None
        elif len(self.buf) == 1:
            self.buf.append(c)
            self.packet_len = 4 + (self.buf[0] & 0x07) + self.buf[1]
            return None
        else:
            self.buf.append(c)

        if self.packet_len and len(self.buf) == self.packet_len:
            p = Packet(self.buf)
            self.buf = []
            return p
        return None

    def handle_event(self, p):
        for h in self.handlers:
            h(p)

    def add_handler(self, h):
        self.handlers.append(h)

    def remove_handler(self, h):
        try:
            self.handlers.remove(h)
        except ValueError:
            pass

    def wait_event(self, cls, cmd):
        res = [None]

        def h(p):
            if p.cls == cls and p.cmd == cmd:
                res[0] = p

        self.add_handler(h)
        while res[0] is None:
            self.recv_packet()
        self.remove_handler(h)

        return res[0]

    def wait_event_2(self, cls, cmd):
        print("wait_event_2")
        res = [None]

        def h(p):
            if p.cls == cls and p.cmd == cmd:
                res[0] = p

        self.add_handler(h)
        t0 = time.time()
        while res[0] is None:
            print("receiving......")
            self.recv_packet(timeout=2, debug=True)
            print("finish recv")
            if time.time() - t0 > 2:
                break
        print("finish waiting")
        self.remove_handler(h)

        return res[0]

    ## specific BLE commands
    def connect(self, addr):
        print("packing", multichr(addr))
        # b'\x12/\xa5\xa0.\xf9' ROS
        # b'\x12/\xa5\xa0.\xf9' Python

        # print(pack("<6sBHHHH", multichr(addr), 0, 6, 6, 64, 0))
        # b'\x12/\xa5\xa0.\xf9\x00\x06\x00\x06\x00@\x00\x00\x00' ROS
        # b'\x12/\xa5\xa0.\xf9\x00\x06\x00\x06\x00@\x00\x00\x00' Python
        return self.send_command(
            6, 3, pack("6sBHHHH", multichr(addr), 0, 6, 6, 64, 0), isConnect=True
        )

    def get_connections(self):
        return self.send_command(0, 6)

    def discover(self):
        return self.send_command(6, 2, b"\x01")

    def end_scan(self):
        return self.send_command(6, 4)

    def disconnect(self, h):
        return self.send_command(3, 0, pack("B", h))

    def read_attr(self, con, attr):
        self.send_command(4, 4, pack("BH", con, attr))
        # Serial write: b'\x00\x03\x04\x04\x01\x17\x00' ROS
        # Serial write: b'\x00\x03\x04\x04\x01\x17\x00'

        return self.wait_event(4, 5)

    def write_attr(self, con, attr, val):
        self.send_command(4, 5, pack("BHB", con, attr, len(val)) + val)
        return self.wait_event(4, 1)

    def send_command(self, cls, cmd, payload=b"", wait_resp=True, isConnect=False):
        if isConnect:
            print(f"Connect: {cls}, {cmd}, {payload}")
            # 6, 3, b'\x12/\xa5\xa0.\xf9\x00\x00\x06\x00\x06\x00@\x00\x00\x00' ROS
            # 6, 3, b'\x12/\xa5\xa0.\xf9\x00\x06\x00\x06\x00@\x00\x00\x00' Python
        s = pack("4B", 0, len(payload), cls, cmd) + payload

        if isConnect:
            print(f"Serial write connect: {s}")
            # b'\x00\x0f\x06\x03\x12/\xa5\xa0.\xf9\x00\x06\x00\x06\x00@\x00\x00\x00'
            # b'\x00\x10\x06\x03\x12/\xa5\xa0.\xf9\x00\x00\x06\x00\x06\x00@\x00\x00\x00'
        print(f"Serial write: {s}")

        # b'\x00\x03\x04\x04\x01\x17\x00' Python
        # b'\x00\x04\x04\x04\x01\x00\x17\x00' ROS

        self.ser.write(s)

        while True:
            p = self.recv_packet()

            ## no timeout, so p won't be None
            if p.typ == 0:
                return p

            ## not a response: must be an event
            self.handle_event(p)

    def fake(self):
        while True:
            print("reading")
            c = self.ser.read()

            print(c)


class MyoRaw(object):
    """Implements the Myo-specific communication protocol."""

    def __init__(self, tty=None):
        if tty is None:
            tty = self.detect_tty()

        if tty is None:
            raise ValueError("Myo dongle not found!")

        self.bt = BT(tty)
        self.conn = None
        self.emg_handlers = []
        self.imu_handlers = []
        self.arm_handlers = []
        self.pose_handlers = []

    def detect_tty(self):
        for p in comports():
            if re.search(r"PID=2458:0*1", p[2]):
                print("using device:", p[0])
                return p[0]

        return None

    def run(self, timeout=None):
        return self.bt.recv_packet(timeout)

    def connect(self):
        ## stop everything from before
        self.bt.end_scan()
        self.bt.disconnect(0)
        self.bt.disconnect(1)
        self.bt.disconnect(2)

        # start scanning
        print("scanning...")
        self.bt.discover()
        print("discovered")
        while True:
            p = self.bt.recv_packet()
            # print("scan response:", p)

            if p.payload.endswith(
                b"\x06\x42\x48\x12\x4A\x7F\x2C\x48\x47\xB9\xDE\x04\xA9\x01\x00\x06\xD5"
            ):
                addr = list(multiord(p.payload[2:8]))
                break
        self.bt.end_scan()
        print("end scanning")
        print(addr)
        conn_pkt = self.bt.connect(addr)

        ## connect and wait for status event
        self.conn = multiord(conn_pkt.payload)[-1]

        print("wait event")
        # print(self.bt.ser.fd, self.bt.serfd)
        # print(os.stat(self.bt.ser.fd))
        # print(self.bt.ser.is_open)
        # print(self.bt.ser.fileno())
        # print(self.bt.ser.get_settings())
        # print(self.bt.ser.readable())
        self.bt.wait_event(3, 0)
        print("xxxxxxxxxxxxxxxxxxxxx")

        ## get firmware version
        fw = self.read_attr(0x17)
        print(f"fw finished {fw.payload}")
        # Packet(80, 04, 05, [01 17 00 00 08 01 00 05 00 B2 07 02 00]) Python
        # Packet(80, 04, 05, [01 17 00 00 08 01 00 05 00 B2 07 02 00])
        # b'\x01\x17\x00\x00\x08\x01\x00\x05\x00\xb2\x07\x02\x00' ROS
        # b'\x01\x17\x00\x00\x08\x01\x00\x05\x00\xb2\x07\x02\x00'

        _, _, _, _, v0, v1, v2, v3 = unpack("BHBBHHHH", fw.payload)
        print("firmware version: %d.%d.%d.%d" % (v0, v1, v2, v3))

        self.old = v0 == 0

        if self.old:
            ## don't know what these do; Myo Connect sends them, though we get data
            ## fine without them
            self.write_attr(0x19, b"\x01\x02\x00\x00")
            # Subscribe for notifications from 4 EMG data channels
            self.write_attr(0x2F, b"\x01\x00")
            self.write_attr(0x2C, b"\x01\x00")
            self.write_attr(0x32, b"\x01\x00")
            self.write_attr(0x35, b"\x01\x00")

            ## enable EMG data
            self.write_attr(0x28, b"\x01\x00")
            ## enable IMU data
            self.write_attr(0x1D, b"\x01\x00")

            C = 1000
            emg_hz = 50
            ## strength of low-pass filtering of EMG data
            emg_smooth = 100

            imu_hz = 50

            ## send sensor parameters, or we don't get any data
            self.write_attr(
                0x19,
                pack(
                    "BBBBHBBBBB", 2, 9, 2, 1, C, emg_smooth, C // emg_hz, imu_hz, 0, 0
                ),
            )

        else:
            name = self.read_attr(0x03)
            print("device name: %s" % name.payload)

            ## enable IMU data
            self.write_attr(0x1D, b"\x01\x00")
            ## enable on/off arm notifications
            self.write_attr(0x24, b"\x02\x00")

            # self.write_attr(0x19, b'\x01\x03\x00\x01\x01')
            self.start_raw()

        # add data handlers
        def handle_data(p):
            if (p.cls, p.cmd) != (4, 5):
                return

            c, attr, typ = unpack("<BHB", p.payload[:4])
            pay = p.payload[5:]

            if attr == 0x27:
                # Unpack a 17 byte array, first 16 are 8 unsigned shorts, last one an unsigned char
                vals = unpack("<8HB", pay)
                # not entirely sure what the last byte is, but it's a bitmask that
                # seems to indicate which sensors think they're being moved around or
                # something
                emg = vals[:8]
                moving = vals[8]
                self.on_emg(emg, moving)
            # Read notification handles corresponding to the for EMG characteristics
            elif attr == 0x2B or attr == 0x2E or attr == 0x31 or attr == 0x34:
                """According to http://developerblog.myo.com/myocraft-emg-in-the-bluetooth-protocol/
                each characteristic sends two secuential readings in each update,
                so the received payload is split in two samples. According to the
                Myo BLE specification, the data type of the EMG samples is int8_t.
                """
                emg1 = struct.unpack("<8b", pay[:8])
                emg2 = struct.unpack("<8b", pay[8:])
                self.on_emg(emg1, 0)
                self.on_emg(emg2, 0)
            # Read IMU characteristic handle
            elif attr == 0x1C:
                vals = unpack("10h", pay)
                quat = vals[:4]
                acc = vals[4:7]
                gyro = vals[7:10]
                self.on_imu(quat, acc, gyro)
            # Read classifier characteristic handle
            elif attr == 0x23:
                typ, val, xdir, _, _, _ = unpack("6B", pay)

                if typ == 1:  # on arm
                    self.on_arm(Arm(val), XDirection(xdir))
                elif typ == 2:  # removed from arm
                    self.on_arm(Arm.UNKNOWN, XDirection.UNKNOWN)
                elif typ == 3:  # pose
                    self.on_pose(Pose(val))
            # Read battery characteristic handle
            elif attr == 0x11:
                battery_level = ord(pay)
                self.on_battery(battery_level)
            else:
                print("data with unknown attr: %02X %s" % (attr, p))

        self.bt.add_handler(handle_data)

    def write_attr(self, attr, val):
        if self.conn is not None:
            self.bt.write_attr(self.conn, attr, val)

    def read_attr(self, attr):
        if self.conn is not None:
            return self.bt.read_attr(self.conn, attr)
        return None

    def disconnect(self):
        if self.conn is not None:
            self.bt.disconnect(self.conn)

    def start_raw(self):
        """To get raw EMG signals, we subscribe to the four EMG notification
        characteristics by writing a 0x0100 command to the corresponding handles.
        """
        self.write_attr(0x2C, b"\x01\x00")  # Suscribe to EmgData0Characteristic
        self.write_attr(0x2F, b"\x01\x00")  # Suscribe to EmgData1Characteristic
        self.write_attr(0x32, b"\x01\x00")  # Suscribe to EmgData2Characteristic
        self.write_attr(0x35, b"\x01\x00")  # Suscribe to EmgData3Characteristic
        self.write_attr(0x19, b"\x01\x03\x02\x01\x01")

    def mc_start_collection(self):
        """Myo Connect sends this sequence (or a reordering) when starting data
        collection for v1.0 firmware; this enables raw data but disables arm and
        pose notifications.
        """

        self.write_attr(0x28, b"\x01\x00")  # Suscribe to EMG notifications
        self.write_attr(0x1D, b"\x01\x00")  # Suscribe to IMU notifications
        self.write_attr(0x24, b"\x02\x00")  # Suscribe to classifier indications
        self.write_attr(
            0x19, b"\x01\x03\x01\x01\x01"
        )  # Set EMG and IMU, payload size = 3, EMG on, IMU on, classifier on
        self.write_attr(0x28, b"\x01\x00")  # Suscribe to EMG notifications
        self.write_attr(0x1D, b"\x01\x00")  # Suscribe to IMU notifications
        self.write_attr(
            0x19, b"\x09\x01\x01\x00\x00"
        )  # Set sleep mode, payload size = 1, never go to sleep, don't know, don't know
        self.write_attr(0x1D, b"\x01\x00")  # Suscribe to IMU notifications
        self.write_attr(
            0x19, b"\x01\x03\x00\x01\x00"
        )  # Set EMG and IMU, payload size = 3, EMG off, IMU on, classifier off
        self.write_attr(0x28, b"\x01\x00")  # Suscribe to EMG notifications
        self.write_attr(0x1D, b"\x01\x00")  # Suscribe to IMU notifications
        self.write_attr(
            0x19, b"\x01\x03\x01\x01\x00"
        )  # Set EMG and IMU, payload size = 3, EMG on, IMU on, classifier off

    def mc_end_collection(self):
        """Myo Connect sends this sequence (or a reordering) when ending data collection
        for v1.0 firmware; this reenables arm and pose notifications, but
        doesn't disable raw data.
        """

        self.write_attr(0x28, b"\x01\x00")
        self.write_attr(0x1D, b"\x01\x00")
        self.write_attr(0x24, b"\x02\x00")
        self.write_attr(0x19, b"\x01\x03\x01\x01\x01")
        self.write_attr(0x19, b"\x09\x01\x00\x00\x00")
        self.write_attr(0x1D, b"\x01\x00")
        self.write_attr(0x24, b"\x02\x00")
        self.write_attr(0x19, b"\x01\x03\x00\x01\x01")
        self.write_attr(0x28, b"\x01\x00")
        self.write_attr(0x1D, b"\x01\x00")
        self.write_attr(0x24, b"\x02\x00")
        self.write_attr(0x19, b"\x01\x03\x01\x01\x01")

    def vibrate(self, length):
        if length in xrange(1, 4):
            ## first byte tells it to vibrate; purpose of second byte is unknown
            self.write_attr(0x19, pack("3B", 3, 1, length))

    def add_emg_handler(self, h):
        self.emg_handlers.append(h)

    def add_imu_handler(self, h):
        self.imu_handlers.append(h)

    def add_pose_handler(self, h):
        self.pose_handlers.append(h)

    def add_arm_handler(self, h):
        self.arm_handlers.append(h)

    def on_emg(self, emg, moving):
        for h in self.emg_handlers:
            h(emg, moving)

    def on_imu(self, quat, acc, gyro):
        for h in self.imu_handlers:
            h(quat, acc, gyro)

    def on_pose(self, p):
        for h in self.pose_handlers:
            h(p)

    def on_arm(self, arm, xdir):
        for h in self.arm_handlers:
            h(arm, xdir)


import multiprocessing


class ConnectMyo(Node):
    def __init__(self):
        super().__init__("connect_myo")
        # self.ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600, dsrdtr=1, timeout=0.5)
        # self.imu_callback_group = rclpy.callback_groups.ReentrantCallbackGroup()

        parser = argparse.ArgumentParser()
        parser.add_argument("serial_port", nargs="?", default=None)

        # parser.add_argument("-i", "--imu-topic", default="myo_imu")
        parser.add_argument("-e", "--emg-topic", default="myo_emg")
        # parser.add_argument("-a", "--arm-topic", default="myo_arm")
        # parser.add_argument("-g", "--gest-topic", default="myo_gest")

        args = parser.parse_args()

        connected = 0
        print("Initializing...")
        while connected == 0:
            try:
                self.m = MyoRaw("/tmp/ttyV0")
                # fix bug
                connected = 1
                # for debug
                print("Myo Armbad start connecting")

            except (ValueError, KeyboardInterrupt) as e:
                print("Myo Armband not found. Attempting to connect...")
                self.sleep(0.5)
                pass

        # Publish to the turtlesim movement topic
        # self.imuPub = self.create_publisher(
        #     Imu, args.imu_topic, 10, callback_group=self.imu_callback_group
        # )
        self.emgPub = self.create_publisher(EmgArray, args.emg_topic, 10)
        # self.armPub = self.create_publisher(MyoArm, args.arm_topic, 10)
        # self.gestPub = self.create_publisher(UInt8, args.gest_topic, 10)

        self.m.add_emg_handler(self.proc_emg)
        # self.m.add_imu_handler(self.proc_imu)
        # self.m.add_arm_handler(self.proc_arm)
        # self.m.add_pose_handler(self.proc_pose)
        # self.m.connect()

        thread_handle_connect = multiprocessing.Process(target=self.m.connect)
        thread_handle_connect.start()
        thread_handle_connect.join()
        print("CONNECTED")
        # self.get_logger().info("Connected to Myo armband")
        thread_handle_read = multiprocessing.Process(target=self.read_serial_data)
        thread_handle_read.start()

    def proc_emg(self, emg, moving, times=[]):
        ## create an array of ints for emg data
        msg = EmgArray()
        msg.data = emg
        self.emgPub.publish(msg)
        print(emg)
        ## print framerate of received data
        times.append(time.time())
        if len(times) > 20:
            times.pop(0)

    def proc_imu(self, quat1, acc, gyro):
        h = Header()
        h.stamp = self.get_clock().now().to_msg()
        h.frame_id = "myo"
        cov = [0, 0, 0, 0, 0, 0, 0, 0, 0]
        quat = Quaternion(
            quat1[0] / 16384.0,
            quat1[1] / 16384.0,
            quat1[2] / 16384.0,
            quat1[3] / 16384.0,
        )
        quatNorm = math.sqrt(
            quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w
        )
        normQuat = Quaternion(
            quat.x / quatNorm, quat.y / quatNorm, quat.z / quatNorm, quat.w / quatNorm
        )
        normAcc = Vector3(acc[0] / 2048.0, acc[1] / 2048.0, acc[2] / 2048.0)
        normGyro = Vector3(gyro[0] / 16.0, gyro[1] / 16.0, gyro[2] / 16.0)
        imu = Imu(h, normQuat, cov, normGyro, cov, normAcc, cov)
        self.imuPub.publish(imu)

    def proc_arm(self, arm, xdir):
        calibArm = MyoArm(arm.value, xdir.value)
        self.armPub.publish(calibArm)

    def proc_pose(self, p):
        self.gestPub.publish(p.value)

    def read_serial_data(self):
        try:
            while True:
                packet = self.m.run(1)
                if packet is None:
                    self.get_logger().warn("No packet received, continuing...")
        except Exception as e:
            self.get_logger().error(f"Error in read_serial_data: {e}")
        finally:
            self.m.disconnect()


def main(args=None):
    rclpy.init(args=args)
    myo_connection = ConnectMyo()

    try:
        rclpy.spin_once(myo_connection)
    except rclpy.exceptions.ROSInterruptException:
        pass
    finally:
        myo_connection.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
