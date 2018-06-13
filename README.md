# DFW_InfoSec_Badge_2018

Files related to the DFW InfoSec Badge 2018

## Story

For a couple of years now several of us at the various DFW InfoSec groups have
talked about creating a badge to wear and trade at the cons.

However, it always seemed to hit the back burner until it was too late to get made in time.

This year was no different.  But, I really didn't want to let it go this time.

So, with no PCB creation experience and severe time limitation I set out on the quest for the badge.

--@alt_bier

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
Here is what this looks like post my edit:
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
I have a badge PCB prototype run on order and will be presenting this at a DC214 meeting.

One week from start to finish is not bad considering I've never done this before.

I just hope it turns out good and that people receiving the badges are not too mad about all the soldering needed to make it functional.

--@alt_bier




 
