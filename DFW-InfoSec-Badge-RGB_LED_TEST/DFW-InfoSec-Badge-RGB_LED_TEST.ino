// Define Pins
#define LED1_RED 2
#define LED1_GREEN 4
#define LED1_BLUE 3

#define LED2_RED 5
#define LED2_GREEN 7
#define LED2_BLUE 6

#define LED3_RED 8
#define LED3_GREEN 10
#define LED3_BLUE 9

#define LED4_RED A4
#define LED4_GREEN A2
#define LED4_BLUE A3

#define LED5_RED A1
#define LED5_GREEN 11
#define LED5_BLUE 12


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
  
  // New Code Work for Digital HIGH/LOW
  int DelayTime = 250;
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