#!/usr/bin/env python

import rospy

from sensor_msgs.msg import LaserScan

import math

def callback(data):
	print data.ranges

if __name__=="__main__":
	print("Laser node started")
	rospy.init_node('scanner_output',anonymous = True)
	rospy.Subscriber("scan",LaserScan,callback)
