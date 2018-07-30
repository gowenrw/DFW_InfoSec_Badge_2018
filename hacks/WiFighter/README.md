# WiFighter

This hack was shared with us by [@Ridgeback111](https://twitter.com/Ridgeback111)

This hack will turn your badge into a WiFi scanner / counter using ESP32 and CiruitPython Express.

Here is a small video of this hack in action on the badge:
[WiFighter_Badge_Hack](https://youtu.be/AukL9QIAfeE)

Here is another video of it working before being added to the badge:
[WiFighter POC](https://youtu.be/-_xaSA5cCK4)

Here are some photos of the hack assembled on the badge:
![Front](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/hacks/WiFighter/Front.jpg)
![Back](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/hacks/WiFighter/Back.jpg)

## The hack explained

The two devices used are an ESP32 DevKitC and a Circuit Python Express.
The ESP32 has micropython installed and the CPX obviously runs CircuitPython.

The switch on the bottom right is the power switch.

The green cable with the alligator lead is the serial line sending two bytes 00-99.

On the back is a LiIonPoly battery split to both devices.
The Vin is routed though the switch.

The existing pin holes and some traces were used for routing.

The wider set of pin rows was a perfect match for the width of the ESP32.

CPX code goes in main.py on the onboard flash.  
Here is the code used for [main.py](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/blob/master/hacks/WiFighter/main.py)

ESP32 code uploads to boot.py in his flash.
Here is the code used for [boot.py](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/blob/master/hacks/WiFighter/boot.py)
