#!/usr/bin/env python

# 
import rospy
from std_msgs.msg import String

def callback(data): # whenever a message arrives on the chatter topic, it is logged. 
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    
def listener():

    rospy.init_node('listener', anonymous=True) # Node called Listner
    rospy.Subscriber("chatter", String, callback) # Node subscribes to the topic chatter (mesage is of type string)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
