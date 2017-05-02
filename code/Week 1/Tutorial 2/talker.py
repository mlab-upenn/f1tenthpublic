#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10) # Creating a publisher called pub, publishes to topic chatter, message type String.
    rospy.init_node('talker', anonymous=True) # Create a node called talker.
    rate = rospy.Rate(10) # 10hz the rate at which the next loop is run
    while not rospy.is_shutdown(): 
        hello_str = "hello world %s" % rospy.get_time()
        pub.publish(hello_str)  # the hellow world message of type string is published to chatter, by node talker.
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()    
    except rospy.ROSInterruptException: # exit gracefully.
        pass
