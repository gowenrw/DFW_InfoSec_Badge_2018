![Hero Image](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/docs/DFW_Hacker_Badge_Banner.jpg)

# DFW Hacker Badge

Welcome to the DFW Hacker Badge website.

This is where you will find all the details of our badge including the components in the kit, assembly instructions, and code.

Please allow me to be your guide.

-- [@alt_bier](https://twitter.com/alt_bier)

## DIY Badge... Say What?!?

Yes, you read it correctly.  This is a DIY badge.  Some assembly required.
We will not be selling assembled badges.

This badge was designed to be an educational badge.

Building the badge from our kit will help teach people basic Electronics and Soldering skills
as well as Arduino Hardware Development and Programming skills.

To assist those without these skills I will link to online training that I created later on this page.
I will also be doing in person badge building classes at the following locations:

* A local DFW area badge building class will be scheduled in mid July.
    * This class has been scheduled for Tuesday July 17th at 6:30PM.
    * Sign up for the class via this Meetup link: [DFW Hacker Badge Building](https://www.meetup.com/TheLab-ms/events/252229891/)
* At BSidesLV I will find a nice corner to hang out and sell badges and answer any questions
    * I will post here and to twitter where and when that is once I know.
* At DEFCON I will be in the Hardware Hacking Village to sell badges and give building assistance
    * I'll post here and to twitter when I'll be at the HHV once my schedule is sorted.
* At BSidesDFW in Nov I will be running the Hardware Hacking Village featuring badge building.
    * This will be a much more comprehensive set of classes covering PCB design through badge assembly.
    * Details will be posted to BSidesDFW communications closer to that event.

## Show Me The Money!

All funds raised by the sale of this badge after production costs will go to
[BSidesDFW](http://www.bsidesdfw.com/) which is a 501c3 non-profit.

These badges will be sold at [BSidesLV](https://www.bsideslv.org/) and [DEFCON](https://defcon.org/).

The full kit will cost **$40.00** and just the PCB with no components will cost **$20.00** .

Early bird adopters (DFW area sales prior to hacker summer camp) will get them for half off.

A complete financial overview of the project including production costs is stored in this repo
and is available [HERE](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/blob/master/Financials.md) for review.

## What's In The Kit?

The badge kit will contain everything you see pictured below.

![Badge Kit Image](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/docs/DFW_Hacker_Badge_Kit.jpg)

Here is a complete list of the items included in the kit:

* 1x Beer Bottle Shaped PCB
* 1x Lanyard (black or green)
* 1x Arduino Nano (pre-loaded with badge code)
* 1x USB A to Mini-B Cable (for programming the Arduino)
* 5x RGB LEDs 5mm 4pin diffused (recommended LEDs)
* 5x RGB LEDs 5mm 4pin clear (optional LEDs to replace above for clear aesthetic)
* 15x 470 ohm resistors (recommended resistors)
* 15x 220 ohm resistors (optional to replace above for brighter LEDs and shorter battery life)
* 1x 1x2 male header pins (optional use for power pins)
* 1x 1x2 female header pins (optional use for power pins)
* 1x 6v 2xCR2032 coin cell battery holder (recommended battery holder)
* 4x CR2032 coin cell batteries (two sets for above)
* 1x 9v battery holder (optional replacement for above, 9v battery not included)
* 1 inch of Velcro adhesive strips (for battery holder attachment)

## Assembly Instructions

__[Click Here for detailed assembly instructions with pictures](./assembly.html)__

Here is a basic list of what you need to do:

* Add the Arduino to the PCB
    * Plug the Arduino into the front of the PCB by pushing its header pins into the appropriate holes
    * It should be a tight fit but make sure the Arduino is pushed all the way down
    * Flip the PCB over so that the header pins poking through are clearly visible
    * Solder each pin to the pad surrounding the hole on the PCB
    * Inspect each solder joint and correct as needed
    * On the backside of the PCB cut the header pins off just above the solder joint
* Add the resistors to the PCB
    * Unlike the header pins on the Arduino, the resistors have soft leads that are easy to bend
    * Bend each resistor into a U shape (with the resistor at the bottom of the U)
    * Push each resistors leads into appropriate holes in the front of the PCB
    * This will be a very loose fit so take care to hold the resistor in place as you flip the PCB over
    * On the back of the PCB bend the leads outward at 45 to 90 degrees to hold the resistor in place
    * Solder each lead of the resistor to the pad surrounding the hole on the PCB
    * Inspect each solder joint and correct as needed
    * On the backside of the PCB cut the leads off just above the solder joint
* Add the LEDs to the PCB
    * Plug each LED into the front of the PCB by pushing its header pins into the appropriate holes
    * Make sure you orient the LED correctly so the common cathode pin goes into the correct hole.
        * Each LED will have one pin longer than the others, this is the common cathode pin
        * You can tell the common cathode hole on the PCB by looking at the traces on the back
        * The common cathode holes for all five LEDs will be connected together by traces
    * It'll be a tight fit but make sure the LED is pushed all the way down to the pin stops
    * Flip the PCB over so that the LED pins poking through are clearly visible
    * Solder each pin to the pad surrounding the hole on the PCB
    * Inspect each solder joint and correct as needed
    * On the backside of the PCB cut the pins off just above the solder joint
* Add the battery connector to the PCB
    * Plug the bare ends of the lead wires for the battery connector into the power holes in the PCB
    * Secure the wires in place so that the bare wires do not move in the PCB holes
    * Solder each wire to the pad surrounding the hole on the PCB
    * Inspect each solder joint and correct as needed
    * Cut any excess wire off just beyond the solder joint
* Insert batteries and Turn it On     

If you are new to soldering you should review this training material I put together:
[Electronics Soldering Basics](http://solder.altbier.us/)

## Arduino Code for the Badge

The Arduino that came in the kit should have been loaded with code that will work with your badge.
This code walks different colors around the star of the badge by turning on and off LEDs.

This code is available here:
[DFW-InfoSec-Badge-Color_Walk_low_power](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/DFW-InfoSec-Badge-Color_Walk_low_power/DFW-InfoSec-Badge-Color_Walk_low_power.ino)

There is a version of this code that lights multiple LEDs at once when walking color around the badge.
This version uses more power which is why it was not loaded by default.

This code is available here:
[DFW-InfoSec-Badge-Color_Walk](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/DFW-InfoSec-Badge-Color_Walk/DFW-InfoSec-Badge-Color_Walk.ino)

There are more code examples in the github repository that you may want to check out.

If you are new to the Arduino you should review this training material I put together:
[Arduino for Beginners](http://arduino.altbier.us/)

---

# Badge Details

## Story

For a couple of years now several of us at the various DFW InfoSec groups have
talked about creating a badge to wear and trade at the cons.

However, it always seemed to hit the back burner until it was too late to get made in time.

This year was no different.  But, I really didn't want to let it go this time.

So, with no PCB creation experience and severe time limitation I set out on the quest for the badge.

## Timeline and Simplicity

I figured in order to make the timeline I would have to keep the board simple.

Given my lack of PCB experience, I decided to fall back on my hardware development board experience.

This allowed for the creation of a board that is just traces, pads, holes, and silkscreen art... simple.

All the components which include an Arduino Nano with some RGB LEDs will need to be added in post.

## Fritzing PCB Design

I decided to use Fritzing for the PCB design since I previously used its breadboard and
schematic features when working with various hardware development platforms.

While I realize that it is not the most robust program for working with PCBs, it does
support exporting Gerber files for manufacturing.

So, my prior knowledge and the timeline dictated its use over learning a new tool.

## Custom PCB Board Shape and Silkscreen

In order to make a custom shaped PCB with silkscreen art Fritzing requires vector graphics in SVG format.  
The SVG needs two group ID's, one for the board shape and one for the silkscreen art.
Here are what those look like:
```
<g id="board">
...
<g id="silkscreen">
```

So, I created an Illustrator image with these vectors and exported it to SVG.

Then I created a PCB in Fritzing and loaded the SVG image.
This is where I ran into a problem.  Fritzing requires width and height be specified.
This is regardless of any viewBox that may be present.
Illustrator exports with a viewBox only, so I needed to manually add the width and height
matching the viewBox values.

Here is what this looks like after my edit:
```
<svg version="1.2" baseProfile="tiny" xmlns="http://www.w3.org/2000/svg"
xmlns:xlink="http://www.w3.org/1999/xlink" x="0px"  y="0px"
width="248" height="832" viewBox="0 0 248 832" xml:space="preserve">
```

## The Circuit

I knew that I wanted to use an Arduino and some LEDs to keep it simple.
So, I came up with a design using an Arduino Nano and five RGB LEDs.

The trick to creating the circuit on the PCB was that I wanted to keep
the board to a single copper layer.
This means that no two traces can cross paths.

This did add some limitations to my design specifically in potential LED placement
as well as in the use of digital and analog pins.

But, these all worked out and I was able to create a circuit design that will
work as a single layer on a PCB.

## Testing The Circuit

Once I had the circuit designed I needed to make sure it would work.

So, I pulled out the boxes of breadboards, jumpers, and components.

I build the circuit exactly the way it was laid out on Fritzing.

I then wrote a quick Arduino script to test all five RGB LED functionality via the circuit.

It's some simple sloppy code, but got the job done... the circuit works.

##### Code Limitation

Because of the specific pins I had to use to each LED in order to keep it single layer, one
of the limitations is that most the LEDs do not have all three colors on analog or pwm pins.

These are the pins that allow you to do ```analogWrite``` to fade an LED on or off.

Since only ```digitalWrite``` will need to be used for consistency this means the RGB LED colors will be
on or off when they are set to ```HIGH``` or ```LOW``` and cannot be faded.
So, where you can turn on red and blue to make purple, you cannot fade them to get pink or lavender.

## Gerber Files

What allowed me to use Fritzing at all for PCB creation was its ability to export Gerber files for manufacturing.

These are the files and format that most of the PCB manufacturing sites require to build your design.

The Gerber files that are shown here are exports from Fritzing that were sent to be produced.

I've included them here so that if the board turns out good and someone wants to make more they can do so
without having to do any of the design work.  Simply send the manufacturer the Gerber files.

##### Layer and Color Limitation

While Fritzing will output Gerber files it does so with some limitations.

The first limitation is regarding the Solder Mask layers and the fact that Fritzing ignores any such layers
provided by your Custom PCB SVG file.  It will always use Green solder mask that covers your board front and back.

While some PCB manufacturers allow you to change the color of the solder mask during ordering, others do not.

The second limitation is regarding the Silkscreen layers and the fact that Fritzing always changes the color to white.

While some PCB manufacturers allow you to change the silkscreen color during ordering, others do not.

At first I though the solder mask color would be a big issue for my beer bottle shaped board.
But, then I found that most the cheap PCB places do not offer Brown solder mask and those that do charge a lot for it.
I was planning on the white silkscreen anyway, so with a green bottle we will be rocking Rolling Rock badges.  LOL

## Summary

This crazy badge creation bug got in my head at a DHA meeting on a Wednesday night and seven days later
I had a badge PCB prototype run on order and presented it at the DC214 meeting.

One week from start to finish is not bad considering I've never done this before.

I just hope it turns out good and that people receiving the badges are not too mad about all the soldering needed to make it functional.

-- [@alt_bier](https://twitter.com/alt_bier)

---

# Badge Hacks

So, just twenty four hours after the first badge sale it was hacked!

I will tag any badge hacks I am made aware of to the end of this page.

## Neopixel PL9823 Hack (First hack of this badge!)

[TheLab.ms](https://thelab.ms) did an awesome job hacking the badge by replacing the dumb RGB LEDs
with smart Neopixel type LEDS and the result looks awesome.

Here is an awesome write up on this hack:
[TheLab.ms PL9823 Badge Hack](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/raw/master/hacks/PL9823_DemoCode/DFW_Hackers_Badge-HACKED.pdf)

The code for this hack is here:
[PL9823_DemoCode](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/tree/master/hacks/PL9823_DemoCode)

This small video shows this hack in action:
[TheLab.ms_Neopixel_Badge_Hack](https://raw.githubusercontent.com/gowenrw/DFW_InfoSec_Badge_2018/master/hacks/PL9823_DemoCode/TheLab.ms_Neopixel_Badge_Hack.mp4)

## Add Sound Hack

Not to be outdone, I have also hacked the badge to add sound to it via a tiny speaker placed
in the center of the star which plays "Deep in the heart of Texas" to an LED light show.

The code for this hack is here:
[Add-Sound](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/tree/master/hacks/add-sound)

A small video of this hack in action is available here:
[DFW_Hacker_Badge_Add_Sound_Hack](https://youtu.be/RLlT0CuagGU)

## WiFighter Hack

In one of the best hacks I've seen yet, [@Ridgeback111](https://twitter.com/Ridgeback111) has
created a WiFi scanner/counter hack of our badge using ESP32 and CiruitPython Express.

The code for this hack is here:
[WiFighter](https://github.com/gowenrw/DFW_InfoSec_Badge_2018/tree/master/hacks/WiFighter)

Here is a small video of this hack in action:
[WiFighter_Badge_Hack](https://youtu.be/AukL9QIAfeE)
