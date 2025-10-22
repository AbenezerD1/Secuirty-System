# Security System

CSS 427 Group final project

For the final project, we made a prototype of a security system that allows authorized users to access a space using a valid RFID tag or pin code to enter. The user interface consists of a 

* LCD screen for displaying the status text
* Keypad and RFID reciever for authentication
* Servo for locking/unlocking the door
* Speaker for providing audible feedback and alarm signals 

The system in its default status only checks for valid tag/pin to enter the space but doesn't check if these authenticaton methods have been bypassed. 

When an admin user uses the admin rfid tag. They can change valid tags/pins and they also have the option to make the system check for intrusions. The system uses a switch we have attached to the door to know when a possible intrusion event has occured. 

If the switch is opened and no authentication has occured, it sounds the alarms using the speaker. The alarm keeps sounding until a valid form of authentication has been entered which stops the alarm and checking for intruders.

<img src="lib\Front_side.webp" alt="Photo of the front side of the prototype" width="500">
<img src="lib\Back_side.webp" alt="PPhoto of the back side of the prototype" width="500">