# DFW_InfoSec_Badge_2018

Files related to the DFW InfoSec Badge 2018

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

### Code Limitation

Because of the specific pins I had to use to each LED in order to keep it single layer, one 
of the limitations is that most the LEDs do not have all three colors on analog or pwm pins. 
 
These are the pins that allow you to do ```analogWrite``` to fade an LED on or off.

Since only ```digitalWrite``` will need to be used for consistency this means LEDs will be
on or off when they are set to ```HIGH``` or ```LOW``` and cannot be faded.



 
