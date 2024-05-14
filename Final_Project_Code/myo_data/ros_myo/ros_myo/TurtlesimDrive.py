#!/usr/bin/env python

## Simple myo demo that listens to std_msgs/UInt8 poses published 
## to the 'myo_gest' topic and drives turtlesim

import math
import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8
from geometry_msgs.msg import Twist, Vector3
from myo_interfaces.msg import MyoArm, EmgArray




class TurtlesimDrive(Node):
	
	def __init__(self):
		super().__init__('turtlesim_driver')
		# Publish to the turtlesim movement topic
		self.tsPublisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
		self.EMGArray_subscriber = self.create_subscription(EmgArray, 'myo_emg', self.strength, 10)


	def strength(self, emgArr1):
		emgArr=emgArr1.data
		# Define proportional control constant:
		K = 0.005
		# Get the average muscle activation of the left, right, and all sides
		aveRight=(emgArr[0]+emgArr[1]+emgArr[2]+emgArr[3])/4
		aveLeft=(emgArr[4]+emgArr[5]+emgArr[6]+emgArr[7])/4
		ave=(aveLeft+aveRight)/2
		# If all muscles activated, drive forward exponentially
		if ave > 500:
			self.tsPublisher_.publish(Twist(Vector3(0.1*math.exp(K*ave),0,0),Vector3(0,0,0)))
		# If only left muscles activated, rotate proportionally
		elif aveLeft > (aveRight + 200):
			self.tsPublisher_.publish(Twist(Vector3(0,0,0),Vector3(0,0,K*ave)))
		# If only right muscles activated, rotate proportionally
		elif aveRight > (aveLeft + 200):
			self.tsPublisher_.publish(Twist(Vector3(0,0,0),Vector3(0,0,-K*ave)))	
		# If not very activated, don't move (high-pass filter)    
		else: 
			self.tsPublisher_.publish(Twist(Vector3(0,0,0),Vector3(0,0,0)))



def main(args=None):
	rclpy.init(args=args)

	TurtlesimDrive = TurtlesimDrive()

	rclpy.spin(TurtlesimDrive)

	# Destroy the node explicitly
	# (optional - otherwise it will be done automatically
	# when the garbage collector destroys the node object)
	TurtlesimDrive.destroy_node()
	rclpy.shutdown()

if __name__ == '__main__':
	main()



