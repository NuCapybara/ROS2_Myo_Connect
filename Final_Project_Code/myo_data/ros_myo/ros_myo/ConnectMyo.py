import rclpy
from rclpy.node import Node
from myo_interfaces.msg import EmgArray


class EMGSubscriber(Node):
    def __init__(self):
        super().__init__("emg_subscriber")
        self.subscription = self.create_subscription(
            EmgArray, "myo_emg", self.listener_callback, 10
        )
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        print(msg)


def main(args=None):
    rclpy.init(args=args)
    emg_subscriber = EMGSubscriber()
    rclpy.spin(emg_subscriber)
    emg_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
