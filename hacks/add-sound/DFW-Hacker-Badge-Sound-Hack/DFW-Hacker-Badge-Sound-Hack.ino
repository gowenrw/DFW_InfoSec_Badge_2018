/* **************************
 *  Sound Hack
 *  This hack requires an 8 ohm speaker be added to the badge
 *  This program will play sounds coordinated with LED lights
 *  The sound code was taken from this public domain code:
 *  http://www.arduino.cc/en/Tutorial/Tone
 * ************************** */

// Include some sound constants
#include "pitches.h"

// Define Pins
/*  NOTE that not all RGB LEDs have the same color pinout
 *  so you need to adjust these definitions based on
 *  the specific LEDs you use.
 *  Also confirm the SPEAKER positive pin connection
 *  (SPEAKER negative should go to ground)
 */
#define LED1_RED 2
#define LED1_GREEN 3
#define LED1_BLUE 4

#define LED2_RED 5
#define LED2_GREEN 6
#define LED2_BLUE 7

#define LED3_RED 8
#define LED3_GREEN 9
#define LED3_BLUE 10

#define LED4_RED 15
#define LED4_GREEN 12
#define LED4_BLUE 11

#define LED5_RED 18
#define LED5_GREEN 17
#define LED5_BLUE 16

#define SPEAKER 19

// LED Pin Array
int LED[5][3] = {
  {LED1_RED, LED1_GREEN, LED1_BLUE}, 
  {LED2_RED, LED2_GREEN, LED2_BLUE},
  {LED3_RED, LED3_GREEN, LED3_BLUE},
  {LED4_RED, LED4_GREEN, LED4_BLUE},
  {LED5_RED, LED5_GREEN, LED5_BLUE}
};

/*  Notes and durations and LED states of the melody to be played.
 *  Uncomment only one of each of the following for a specific melody: 
 *  
 */
 
// ***** Notes in the melody to be played *****

// basic test melody (shave and a haircut):
/*
int melodyNotes[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
*/

// Deep In The Heart Of Texas :
int melodyNotes[] = {
  NOTE_C3, NOTE_F3, NOTE_F3, NOTE_A4, 0, NOTE_C3, NOTE_F3, NOTE_F3, NOTE_A4, 0, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, 0, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A4, NOTE_G3
}; 


// ***** Note Durations: 4 = quarter note, 8 = eighth note, etc. *****

// basic test melody (shave and a haircut):
/*
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
*/

// Deep In The Heart Of Texas :
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 4, 4
};


void setup() {
  // Initialize Pins As Output
  pinMode(LED1_RED, OUTPUT);
  pinMode(LED1_GREEN, OUTPUT);
  pinMode(LED1_BLUE, OUTPUT);
  
  pinMode(LED2_RED, OUTPUT);
  pinMode(LED2_GREEN, OUTPUT);
  pinMode(LED2_BLUE, OUTPUT);
  
  pinMode(LED3_RED, OUTPUT);
  pinMode(LED3_GREEN, OUTPUT);
  pinMode(LED3_BLUE, OUTPUT);
  
  pinMode(LED4_RED, OUTPUT);
  pinMode(LED4_GREEN, OUTPUT);
  pinMode(LED4_BLUE, OUTPUT);
  
  pinMode(LED5_RED, OUTPUT);
  pinMode(LED5_GREEN, OUTPUT);
  pinMode(LED5_BLUE, OUTPUT);

  pinMode(SPEAKER, OUTPUT);

  /*  Only playing sound one time in setup
   *  as that could get very annoying.
   *  
   *  The badge will continue the low power color walk code
   *  in the main loop after the initial sound/light show.
   *  
   *  The reset button on the Arduino can be used to play
   *  the sound again without fully power cycling the badge.
   *  
   *  sizeof(melodyNotes) not working
   */
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 22; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPEAKER, melodyNotes[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SPEAKER);
  }
}

// Main Loop
void loop() {
  
  /*   This is the same code from the low power color walk program
   *   that will be looped until a power cycle or reset plays the sounds again. 
   */
  
  // Set Delay for each transition [in ms]
  int DelayTime = 150;

  // Color Order in R,G,B Binary Values
  // White OFF Red OFF 
  // Yellow OFF Green OFF 
  // Cyan OFF Blue OFF
  // Magenta OFF
  char Color[14][3] = {
    {1, 1, 1}, {0, 0, 0}, {1, 0, 0}, {0, 0, 0}, 
    {1, 1, 0}, {0, 0, 0}, {0, 1, 0}, {0, 0, 0}, 
    {0, 1, 1}, {0, 0, 0}, {0, 0, 1}, {0, 0, 0}, 
    {1, 0, 1}, {0, 0, 0}
  };

  for (int c = 0; c < 14; c++) {               // Color Loop (MAX = Color[n])
      for (int l = 0; l < 5; l++) {           // LEDs (MAX = LED[n])
        alloff();                             // Turn All Off Before Turning on Next LED
        for (int i = 0; i < 3; i++) {         // Individual Colors (MAX = 3 rgb)
          digitalWrite(LED[l][i], Color[c][i]); 
        }
        delay(DelayTime);
      }
  }
}

// All Off Loop
void alloff()
{
      for (int l = 0; l < 5; l++) {           // LEDs (MAX = LED[n])
        for (int i = 0; i < 3; i++) {         // Individual Colors (MAX = 3 rgb)
          digitalWrite(LED[l][i], LOW); 
        }
      }
}

