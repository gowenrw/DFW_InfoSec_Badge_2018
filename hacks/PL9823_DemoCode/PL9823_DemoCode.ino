// DFW HACKERS PL9823-F8 HACK Demo Code (c) Gregory A. Miller / TheLab.ms
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// This sketch allows you to control NeoPixel style LED devices on the DFW HACKERS Badge

// This sketch requires the Adafruit NeoPixel Library v1.1.6 or higher
#include <Adafruit_NeoPixel.h>

// Which Arduino pin is the PWM Output? Nano options include 3,5,6,9,10,11
// PIN 5 was chosen by default to match the Hacked scematic.
#define PIN             11

// This defines how many LED devices you have on the string.
#define DEVICECOUNT     5

// Depending on your device model and Mfr. the parameter in the following line can be either NEO_GRB or NEO_RGB.
// If the colors are all wrong, try switching this parameter. All it does is change the bit order on the colors output.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(DEVICECOUNT, PIN, NEO_RGB + NEO_KHZ800);

// If you experience flicker or random flashes of color, increase this delay to make it go away.
int iDelay_ms = 500;   // Time delay in miliseconds

void setup() {
  Serial.begin(9600);   // Used for debugging purposes only
  ConfigurationSet();
  pixels.begin(); // This initializes the NeoPixel library.
}

// This variable is used to determine which Hacked Configuration demo (0-7) should be run OR if the RGB configuration (99) is set.
int iSelected = 99;   // Defaults to RGB Configuration.

void loop() {
  
  // All of the demos are represented here in this loop
  switch(iSelected) {
    case 0:
      // DemoBasic steps through and sets each LED to each basic color at full intensity. RED, GREEN, BLUE & WHITE
      demoBasic();
      break;
    case 1:
      // This demos two different techniques for fading
      // DemoFade steps through each basic color RED, GREEN, BLUE & WHITE and fades from full off to full on of each color. The parameter slows the fade speed.
      demoFade1(5);
      // DemoFade steps through each basic color RED, GREEN, BLUE & WHITE and fades from full off to full on of each color. The parameter slows the fade speed.
      demoFade2(5);
      break;
    case 2:
      // demoSpinningWheel starts a spinning action which gets faster and then slows down and reverses and then repeats
      demoSpinningWheel();
      break;
    case 3:
      // demoRandomBlinky sets a random color on a random LED and strobes it as fast as the controller can. The parameter passed is the number of blinks it will produce.
      demoRandomBlinky(500);
      break;
    case 4:
      // demoPatriotic uses a RED, WHIT & BLUE motif
      demoPatriotic();
      break;
    case 5:
      // demoFunColors tuns on the LEDs with various colors which are mixed from the RGB brightness. The parameter is the delay each color is displayed
      demoFunColors(1000);
      break;
    case 6:
      // demoRandomColors randomly creates a color mix and displays it on all devices. The parameter is fast the fade happens.
      demoRandomColors(100);
      break;
    case 7:
      // This selection runs all of the demos in order
      demoBasic();
      demoFade1(5);
      demoFade2(5);
      demoRandomBlinky(500);
      demoPatriotic();
      demoFunColors(1000);
//      demoRandomFade(5);
      break;
    default:
      // This is only run if the badge is in RGB mode
      Serial.println("RGB Configuration");
      OriginalBadgeCode();
      break;
  }
showPixels();
Serial.println(iSelected);  // This is used for debugging only
Serial.println("-----");    // This is used for debugging only
delay(1000);
}

void ConfigurationSet() {
    // Determine if the RGB configuration is active or teh Hacked configuration.
  // If the Hacked configuration, which demo sode is desired based on which Analog pin is selected.
  // If any of the Analog pins are set to High via special connector (Vcc---10Kohm---A[0-7]) then choose that Hacked Config option
  // If none of teh Analog pins are selected (floating/disconnected) then assume the RGB configuration is in play.
  for(int a=0;a<8;a++){ 
    // The Nano has 8 analog pins which can be used for selection testing.
    // Test each one and find one that has an output value of "1023" which will indicate it is ties to Vcc
    Serial.println(analogRead(a));
    if(analogRead(a)==1023){
      iSelected = a;
      break;
    }else {
      iSelected = 99;
    }
  }
}

void showPixels() {
  pixels.show();
}


void demoSpinningWheel() {
  // This demo will simulate a spinning movement that speeds up, slows down and reverses
  for(int i=256;i>0;i=i-4){
    for(int d=0;d<DEVICECOUNT;d++){
      demoTurnOff(1);
      pixels.setPixelColor(d,pixels.Color(255,255,255));
      pixels.show();
      delay(i/2);
    }
  }
  for(int i=1;i<128;i=i+4){
    for(int d=0;d<DEVICECOUNT;d++){
      demoTurnOff(1);
      pixels.setPixelColor(d,pixels.Color(255,255,255));
      pixels.show();
      delay(i*2);
    }
  }
  for(int i=256;i>0;i=i-4){
    for(int d=DEVICECOUNT-1;d>-1;d--){
      demoTurnOff(1);
      pixels.setPixelColor(d,pixels.Color(255,255,255));
      pixels.show();
      delay(i/2);
    }
  }
  for(int i=1;i<128;i=i+4){
    for(int d=DEVICECOUNT-1;d>-1;d--){
      demoTurnOff(1);
      pixels.setPixelColor(d,pixels.Color(255,255,255));
      pixels.show();
      delay(i*2);
    }
  }
}


void demoRandomColors(int iDelaySpeed){
  // This demo randomly creates a color mix and displays it on all devices and repeats 20 times
  randomSeed(analogRead(7));  // Grab a random value from Analog pin 7
  demoTurnOff(1);
  for(int iCycle=1;iCycle<=20;iCycle++){
      pixels.setPixelColor(0,pixels.Color(getRnd(),getRnd(),getRnd()));
      pixels.setPixelColor(1,pixels.Color(getRnd(),getRnd(),getRnd()));
      pixels.setPixelColor(2,pixels.Color(getRnd(),getRnd(),getRnd()));
      pixels.setPixelColor(3,pixels.Color(getRnd(),getRnd(),getRnd()));
      pixels.setPixelColor(4,pixels.Color(getRnd(),getRnd(),getRnd()));
      pixels.show();
  delay(iDelaySpeed);
  }
}

int getRnd(){
  return random(0,255);
}

void demoPatriotic() {
  #define colorRed pixels.Color(255,0,0)
  #define colorWhite pixels.Color(255,255,255)
  #define colorBlue pixels.Color(0,0,255)
  #define colorOFF pixels.Color(0,0,0)

  demoTurnOff(1);
  pixels.setPixelColor(1, colorRed);
  pixels.setPixelColor(2, colorRed);
  pixels.show();
  delay(iDelay_ms/4);
  pixels.setPixelColor(0, colorRed);
  pixels.setPixelColor(3, colorRed);
  pixels.setPixelColor(1, colorWhite);
  pixels.setPixelColor(2, colorWhite);
  pixels.show();
  delay(iDelay_ms/4);
  pixels.setPixelColor(4,colorRed);
  pixels.setPixelColor(0, colorWhite);
  pixels.setPixelColor(3, colorWhite);
  pixels.setPixelColor(1, colorBlue);
  pixels.setPixelColor(2, colorBlue);
  pixels.show();
  delay(iDelay_ms);
  pixels.setPixelColor(4,colorWhite);
  pixels.setPixelColor(0, colorBlue);
  pixels.setPixelColor(3, colorBlue);
  pixels.setPixelColor(1, colorRed);
  pixels.setPixelColor(2, colorRed);
  pixels.show();
  delay(iDelay_ms/4);
  pixels.setPixelColor(4,colorBlue);
  pixels.setPixelColor(0, colorRed);
  pixels.setPixelColor(3, colorRed);
  pixels.setPixelColor(1, colorWhite);
  pixels.setPixelColor(2, colorWhite);
  pixels.show();
  delay(iDelay_ms/4);
  pixels.setPixelColor(4,colorRed);
  pixels.setPixelColor(0, colorWhite);
  pixels.setPixelColor(3, colorWhite);
  pixels.setPixelColor(1, colorBlue);
  pixels.setPixelColor(2, colorBlue);
  pixels.show();
  delay(iDelay_ms);
  pixels.setPixelColor(4,colorWhite);
  pixels.setPixelColor(0, colorBlue);
  pixels.setPixelColor(3, colorBlue);
  pixels.setPixelColor(1, colorOFF);
  pixels.setPixelColor(2, colorOFF);
  pixels.show();
  delay(iDelay_ms/4);
  pixels.setPixelColor(4,colorBlue);
  pixels.setPixelColor(0, colorOFF);
  pixels.setPixelColor(3, colorOFF);
  pixels.setPixelColor(1, colorOFF);
  pixels.setPixelColor(2, colorOFF);
  pixels.show();
  delay(iDelay_ms/4);
  demoTurnOff(1);
}

void demoFunColors(int holdDelay){
  demoTurnOff(1);
  #define orange pixels.Color(128,64,0)
  #define yellow pixels.Color(128,128,0)
  #define magenta pixels.Color(128,0,128)
  #define cyan pixels.Color(0,128,128)
  
  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, orange);
    pixels.show();
    // This sends the updated pixel color to the hardware.
  }
  delay(holdDelay); // Delay for a period of time (in milliseconds).

  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, yellow);
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(holdDelay); // Delay for a period of time (in milliseconds).

  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, magenta);
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(holdDelay); // Delay for a period of time (in milliseconds).

  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, cyan);
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(holdDelay); // Delay for a period of time (in milliseconds).

}

void demoRandomBlinky(int iBlinkCount){
  randomSeed(analogRead(7));  // Grab a random value from Analog pin 7
  demoTurnOff(1);
  for (int i=0;i<iBlinkCount;i++) {
    for(int i=0;i<DEVICECOUNT;i++){
      int iRndNum = random(0,5);
      pixels.setPixelColor(iRndNum, pixels.Color(random(255),random(255),random(255)));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(5);
      pixels.setPixelColor(iRndNum, pixels.Color(0,0,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(5); // Delay for a period of time (in milliseconds).
    }
  }
}

void demoTurnOff(int iDelayOff){
  // This demo code will turn off all LED devices for the specific time provided
  if (iDelayOff > 0){
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iDelayOff); // Delay for a period of time (in milliseconds).
  }
}

void demoFade1(int iFadeSpeed){
  demoTurnOff(1);
  // This code will fade a color from off to full brightness and back to off
  for(int p=0;p<=255;p++) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(p,0,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=255;p>=0;p--) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(p,0,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=0;p<=255;p++) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(0,p,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=255;p>=0;p--) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(0,p,0));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=0;p<=255;p++) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,p));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=255;p>=0;p--) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,p));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=0;p<=255;p++) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(p,p,p));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
  for(int p=255;p>=0;p--) {
    for(int i=0;i<DEVICECOUNT;i++){
      pixels.setPixelColor(i, pixels.Color(p,p,p));
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    delay(iFadeSpeed); // Delay for a period of time (in milliseconds).
  }  
}

void demoFade2(int iFadeSpeed){
  for(int i=0; i<3; i++){
    for (int j=0; j<256; j++){
      switch (i){
        case 0: 
          setAll(j,0,0);
          break;
        case 1: 
          setAll(0,j,0);
          break;
        case 2: 
          setAll(0,0,j);
          break;
      }
      showPixel();
      delay(iFadeSpeed);
    }
  }
}

void setAll(byte red, byte green, byte blue){
  for(int i=0;i<DEVICECOUNT; i++){
    pixels.setPixelColor(i,red,green,blue);
  }
}

void showPixel(){
  pixels.show();
}

void demoBasic() {
  demoTurnOff(1);
    // This code will loop through each LED as RED and then GREEN and then BLUE and then WHITE and then repeat
  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(iDelay_ms); // Delay for a period of time (in milliseconds).
  }
  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(iDelay_ms); // Delay for a period of time (in milliseconds).
  }
  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(iDelay_ms); // Delay for a period of time (in milliseconds).
  }
  for(int i=0;i<DEVICECOUNT;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(iDelay_ms); // Delay for a period of time (in milliseconds).
  }
}


void OriginalBadgeCode() {
  /* **************************
 *  Color Walk
 *  This program will walk each color around
 *  all five LEDs in a specified color order
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


//void setup()
//{
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
//}

// Main Loop
//void loop()
while(1)
{
  
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

  // LED Pin Array
  int LED[5][3] = {
    {LED1_RED, LED1_GREEN, LED1_BLUE}, 
    {LED2_RED, LED2_GREEN, LED2_BLUE},
    {LED3_RED, LED3_GREEN, LED3_BLUE},
    {LED4_RED, LED4_GREEN, LED4_BLUE},
    {LED5_RED, LED5_GREEN, LED5_BLUE}
  };

  for (int c = 0; c < 14; c++) {               // Color Loop (MAX = Color[n])
      for (int l = 0; l < 5; l++) {           // LEDs (MAX = LED[n])
        for (int i = 0; i < 3; i++) {         // Individual Colors (MAX = 3 rgb)
          digitalWrite(LED[l][i], Color[c][i]); 
        }
        delay(DelayTime);
      }
  }

}
}

