/* **************************
 *  RGB LED TEST
 *  This program will do a simple test of
 *  all five LEDs to make sure they are working
 *  and that you have the pin definitions correct
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

#define LED4_RED 18
#define LED4_GREEN 17
#define LED4_BLUE 16

#define LED5_RED 15
#define LED5_GREEN 12
#define LED5_BLUE 11


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
  int DelayTime = 750;

  /* ***************************
   *  Testing Note
   *  If you do not see the LEDs progress in color
   *  in the order that the colors are specified here
   *  then this means your color pin definitions are wrong
   **************************** */
  // RED
  digitalWrite(LED1_RED, HIGH);
  digitalWrite(LED2_RED, HIGH);
  digitalWrite(LED3_RED, HIGH);
  digitalWrite(LED4_RED, HIGH);
  digitalWrite(LED5_RED, HIGH);
  delay(DelayTime);
  
  // RED + GREEN
  digitalWrite(LED1_GREEN, HIGH);
  digitalWrite(LED2_GREEN, HIGH);
  digitalWrite(LED3_GREEN, HIGH);
  digitalWrite(LED4_GREEN, HIGH);
  digitalWrite(LED5_GREEN, HIGH);
  delay(DelayTime);
  
  // GREEN
  digitalWrite(LED1_RED, LOW);
  digitalWrite(LED2_RED, LOW);
  digitalWrite(LED3_RED, LOW);
  digitalWrite(LED4_RED, LOW);
  digitalWrite(LED5_RED, LOW);
  delay(DelayTime);
  
  // GREEN + BLUE
  digitalWrite(LED1_BLUE, HIGH);
  digitalWrite(LED2_BLUE, HIGH);
  digitalWrite(LED3_BLUE, HIGH);
  digitalWrite(LED4_BLUE, HIGH);
  digitalWrite(LED5_BLUE, HIGH);
  delay(DelayTime);
  
  // BLUE
  digitalWrite(LED1_GREEN, LOW);
  digitalWrite(LED2_GREEN, LOW);
  digitalWrite(LED3_GREEN, LOW);
  digitalWrite(LED4_GREEN, LOW);
  digitalWrite(LED5_GREEN, LOW);
  delay(DelayTime);
  
  // BLUE + RED
  digitalWrite(LED1_RED, HIGH);
  digitalWrite(LED2_RED, HIGH);
  digitalWrite(LED3_RED, HIGH);
  digitalWrite(LED4_RED, HIGH);
  digitalWrite(LED5_RED, HIGH);
  delay(DelayTime);
  
  // RBG WHITE
  digitalWrite(LED1_GREEN, HIGH);
  digitalWrite(LED2_GREEN, HIGH);
  digitalWrite(LED3_GREEN, HIGH);
  digitalWrite(LED4_GREEN, HIGH);
  digitalWrite(LED5_GREEN, HIGH);
  delay(DelayTime);
  
  // ALL OFF NO DELAY
  digitalWrite(LED1_RED, LOW);
  digitalWrite(LED2_RED, LOW);
  digitalWrite(LED3_RED, LOW);
  digitalWrite(LED4_RED, LOW);
  digitalWrite(LED5_RED, LOW);
  digitalWrite(LED1_GREEN, LOW);
  digitalWrite(LED2_GREEN, LOW);
  digitalWrite(LED3_GREEN, LOW);
  digitalWrite(LED4_GREEN, LOW);
  digitalWrite(LED5_GREEN, LOW);
  digitalWrite(LED1_BLUE, LOW);
  digitalWrite(LED2_BLUE, LOW);
  digitalWrite(LED3_BLUE, LOW);
  digitalWrite(LED4_BLUE, LOW);
  digitalWrite(LED5_BLUE, LOW);
  
}
