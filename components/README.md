# Components

This section contains a list of all the components that we will be including with
the badge and information about them.

We will be including two types of LEDs and resistors and battery connectors to allow the user to choose what they like best.

## Arduino Nano v3.0

The board was designed to take an Arduino Nano v3.0 and it's associated pin out.

The place I am sourcing these from in China uses the cheaper CH340 USB chip.
This means that on some machines (Windows) you will need a CH340 driver to connect to the Arduino.

This is the link to the CH340 chip manufacturer website for details on the CH340 and driver download links:
[http://www.wch.cn/products/CH340.html](http://www.wch.cn/products/CH340.html)

## Red, Green, Blue LEDs

The board was designed to take 5mm 4-pin through hole type RGB LEDs.

I've included two types in the badge kit.  Both are very similar.

The major difference between the two is one is clear and the other is diffused. 

## Resistors

The board was designed to take through hole type resistors.

I've included two types in the badge kit.

The 220 ohm resistors that have been included are the lowest resistance I would recommend using with these LEDs.
Using these will make for very bright LEDs but will do so at the cost of battery life.
If you are planning on using a 9V battery then this should be fine.

The 470 ohm resistors that have been included are the resistance I would recommend for these LEDs when powered by coin cells.
The LEDs are still faily bright but reducing the current drawn a bit more than with the 220's extends the battery life of the coin cells.

## Battery related items

The board was designed to take input voltage between 6 and 12 volts on two leads.

I've included two types of battery connectors in the badge kit, a 9v and a 6v (2x3v CR2032).
Since the 6v coin cell holder is smaller and lighter than a big 9v battery I assumed this would be the preffered choice and have
included CR2032 batteries in the kit.
Finally I included 1x2 pin male and female headers to allow for the battery connectors to be removable should you choose to use them.

The 9v battery connector is the simple standard type used on many arduino projects.  So even if you don't use it on this badge,
it could come in handy on other projects.

The 6v coin cell holder is a fairly new thing I found that works with the Arduino.  

I was worried that the voltage drop across the VIN port on the Arduino would be too great for a 6V power source to work, but it does.  
This does mean that the coin cells do not last as long as they might otherwise since they might still have stored power that is just 
not providing enough voltage to power the board.
However, my testing seems to indicate that they last long enough for this to be a viable battery solution for the badge.
Note: If the batteries seems to be powering the Arduino (red light) but stop lighting the RGB LEDs, I have found that turning them
off for a few minutes will allow them to operate properly again for a while when turned back on since the voltage loss recovers a bit with rest.



