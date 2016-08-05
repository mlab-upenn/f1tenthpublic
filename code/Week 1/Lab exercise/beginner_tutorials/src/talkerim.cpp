#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32.h"
#include <sstream>
#include "beginner_tutorials/Num.h"
#include "beginner_tutorials/driveCmd.h"
#include "std_msgs/Int16.h"
#include "custom_messages/onlySteering.h"
#include "custom_messages/driveMessage.h"
#include "custom_messages/driveMessage_timed.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class talker
{

/*

	Your job is to fill up the methods of the talker class such that once the object of this class is instantiated, it will keep listening for the messages published by the teleop_traxxas.You should process the commands and publish them on topic "chatter" with a data type of "driveMessage_timed"
	The teensy will listen to these messages and generate the waveform with the corresponding duty cycle which will be directly fed into the ESC and servo
        If you go with the default settings, a value of 9830 is 15% duty cycle and an increment of 655 leads to a 0.01% change in the duty cycle

	Make sure you limit the published values to the operating regions of 15%±5%. 





*/


}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talkerim");
  ros::NodeHandle n;

  talker talkObject;

  ros::spin();

  return 0;   

}
