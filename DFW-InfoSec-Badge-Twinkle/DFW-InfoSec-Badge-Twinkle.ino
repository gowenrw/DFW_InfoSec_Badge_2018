/* **************************
 *  Twinkle
 *  This program will choose random colors for
 *  all five LEDs to create a twinkle effect
 * ************************** */

// Define Pins
/* NOTE that not all RGB LEDs have the same color pinout
 *  so you need to adjust these definitions based on
 *  the specific LEDs you use.
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


void setup()
{
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
}

// Main Loop
void loop()
{
  
  // Set Delay for each transition [in ms]
  int DelayTime = 100;

  // Color to Twinkle With in R,G,B Binary Values
  // White Red Yellow Green Cyan Blue Magenta OFFx5
  char Color[12][3] = {
    {1, 1, 1}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 1}, {0, 0, 1}, {1, 0, 1}, 
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
  };

  // LED Pin Array
  int LED[5][3] = {
    {LED1_RED, LED1_GREEN, LED1_BLUE}, 
    {LED2_RED, LED2_GREEN, LED2_BLUE},
    {LED3_RED, LED3_GREEN, LED3_BLUE},
    {LED4_RED, LED4_GREEN, LED4_BLUE},
    {LED5_RED, LED5_GREEN, LED5_BLUE}
  };

  for (int l = 0; l < 5; l++) {           // LEDs (MAX = LED[n])
    int c = random(12);
    for (int i = 0; i < 3; i++) {         // Individual Colors (MAX = 3 rgb)
      digitalWrite(LED[l][i], Color[c][i]); 
    }
    delay(DelayTime);
  }

}
