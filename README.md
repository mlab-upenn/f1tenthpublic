# f1tenth_public, please read me
This repository hosts all of the code, CAD files, and other resources necessary to get your car ready for competition.

## F1tenth BOM 2019.xlsx
This is the bill of materials for building a F1/10 car. It contains order links for mechanical and electrical parts. The updated power board and parts list and order links are also inside.

## power-board-v3.zip
The source files of power board v3. It is designed in Altium Designer. To order the powerboard, please go to "F1tenth BOM 2019.xlsx" and find the order link in "Bill of Material for Power Board v3.0" section. The order link is https://oshpark.com/shared_projects/qvIKu3aY

### Warning: please test power board before connecting battery, Jetson and Lidar!
After soldering the power board, please test the board with a DC power supply and multimeter. 
* Using a multimeter, test if the GND_BATT pin and the opposite pin of the battery connector on the power board are shorted. Test if any 12V pin and GND pin, 8V pin and GND pin are shorted. Double check the polarity of electrolytic capacitor and the 12V to 8V DC converter. Check if the switch functions.
* Set the DC power supply to 12 V, current limit of 100 mA, and connect GND of power supply to GND_BATT pin and + of power supply to 1st pin at battery connector. Turn on power supply, and flip on the switch. Red PWR_LED should light up. Test 12V and 8V output voltage.

### Connect battery only after making sure no short circuit exists!

## Chassis
The Chassis folder contains solidworks files for making the chassis.
The following parts need to be laser cut:
* Chassis_Surfaced_MASTER_small_powerboard.DWG (for power board v3)
* Lidar_Mount_10LX.DWG or Lidar_Mount_30LX.DWG

The following parts need to be 3D printed:
* Camera_Mount.STL

The 3dPrints folder contains optional parts for zed camera.

If the FOCBOX cannot fit under the small power board, you can use only 3 standoffs to mount the power board.

## Power-board-v2.0
Old power board design source files. Obsolete. Designed in Altium Designer.

## Change log
v3:
Updated power board. Removed teensy and lithium battery charging module because no one would run the car while charging the battery.
Updated chassis to match the smaller power board.
