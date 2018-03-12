This file contains commands to setup rosserial to communicate with Teensy via ROS framework. It also involves command for generation of custom messages headers which can be accessed by code in arduino.


Setup Arduino with Teensy:

1) Setup arduino with Teensy package using link : https://www.pjrc.com/teensy/td_download.html


2) Setup rosserial : 
	Follow link : http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

	OR

	use commands :
	sudo apt-get install ros-indigo-rosserial-arduino
	sudo apt-get install ros-indigo-rosserial


3) To setup libraries (use custom messages):
	- go into race folder from Week 2
	- create build folder: `mkdir build`
	- move into it: `cd build`
	- run cmake on parent folder: `cmake ..`
	- now Makefile is available, so run it with: `make`
	- source created setup file: `source ./devel/setup.bash`
	- move into [place_for_arduino_projects]/libraries
	- delete old ros libs folder `rm -rf ros_lib`
	- run rosserial libraries builder `rosrun rosserial-arduino make_libraries.py .`

	Now, you should be able to find folder `race` in `ros_lib` folder with 3 header files (custom messages).

4)	Once this is configured : 
	Choose Teensy 3.2/3.1 in Tools menu of arduino software. Also make sure settings are configured to : "serial" and "96 Mhz optimized".
	After choosing the appropriate port, your arduino should be ready to dump the firmware.
