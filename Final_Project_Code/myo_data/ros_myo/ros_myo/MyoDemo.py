#!/usr/bin/env python

## Simple myo demo that listens to std_msgs/UInt8 poses published 
## to the 'myo_gest' topic and drives turtlesim

import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8, String
from geometry_msgs.msg import Twist, Vector3
from myo_interfaces.msg import MyoArm, EmgArray

########## Data Enums ###########
# MyoArm.arm___________________ #
#    UNKNOWN        = 0 	#
#    RIGHT          = 1		#
#    Left           = 2		#
# MyoArm.xdir___________________#
#    UNKNOWN        = 0		#
#    X_TOWARD_WRIST = 1		#
#    X_TOWARD_ELBOW = 2		#
# myo_gest UInt8________________#
#    REST           = 0		#
#    FIST           = 1		#
#    WAVE_IN        = 2		#
#    WAVE_OUT       = 3		#
#    FINGERS_SPREAD = 4		#
#    THUMB_TO_PINKY = 5		#
#    UNKNOWN        = 255	#
#################################



class MyoDemo(Node):
	global armState
	global xDirState
	armState = 0


	def __init__(self):
		super().__init__('turtlesim_driver')
		# Publish to the turtlesim movement topic


		self.turtlesimPub = self.create_publisher(String, "directs", 10)
		self.tsPub = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
		self.armSub = self.create_subscription(MyoArm, "myo_arm", self.setArm, 1)
		self.myo_gest_sub = self.create_subscription(UInt8, "myo_gest", self.drive, 1)
		self.get_logger().info('Please sync the Myo')
		self.armState = None
		self.xDirState = None
		
		

	def setArm(self, data):
		self.get_logger().info('I heard arm info!!!')
		self.armState = data.arm
		self.xDirState = data.xdir
		self.sleep(2.0)

	def drive(self, gest):
    
		if gest.data == 1: #FIST
			self.turtlesimPub.publish("go back")
			self.tsPub.publish(Twist(Vector3(-1.0, 0, 0), Vector3(0, 0, 0)))
		elif gest.data == 2 and self.armState == 1: #WAVE_IN, RIGHT arm
			self.turtlesimPub.publish("go left")
			self.tsPub.publish(Twist(Vector3(0, 0, 0), Vector3(0, 0, 1.0)))
		elif gest.data == 2 and self.armState == 2: #WAVE_IN, LEFT arm
			self.turtlesimPub.publish("go right")
			self.tsPub.publish(Twist(Vector3(0, 0, 0), Vector3(0, 0, -1.0)))
		elif gest.data == 3 and self.armState == 1: #WAVE_OUT, RIGHT arm
			self.turtlesimPub.publish("go right")
			self.tsPub.publish(Twist(Vector3(0, 0, 0), Vector3(0, 0, -1.0)))
		elif gest.data == 3 and self.armState == 2: #WAVE_OUT, LEFT arm
			self.turtlesimPub.publish("go left")
			self.tsPub.publish(Twist(Vector3(0, 0, 0), Vector3(0, 0, 1.0)))
		elif gest.data == 4: #FINGERS_SPREAD
			self.turtlesimPub.publish("go forward")
			self.tsPub.publish(Twist(Vector3(1.0, 0, 0), Vector3(0, 0, 0)))


def main(args=None):
	rclpy.init(args=args)

	myoDemo = MyoDemo()

	rclpy.spin(myoDemo)
	rclpy.shutdown()

if __name__ == '__main__':
	main()





