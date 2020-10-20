#include <Stepper_28BYJ_48.h> // Imports the stepper library.
Stepper_28BYJ_48 stepper(6, 5, 4, 3); // Declares the pins the stepper motor is plugged into.
#define BLYNK_PRINT SwSerial // Tells the arduino and blynk app to use the Serial/USB option.
#include <SoftwareSerial.h> // Import the serial library to be used in the code.
SoftwareSerial SwSerial(10, 11); // RX, TX Declares the serial pins.
#include <BlynkSimpleStream.h>
char auth[] = "c344fed547f248a69e193d5238c66faa"; // Auth token used by Bylnk.
const int ledPin1 = 10; // Declares led pins.
const int ledPin2 = 11;
const int ledPin3 = 12;
const int buzzer = 13; // Declares pin for buzzer
void setup() {
  Serial.begin(9600); // Initalise serial connection.
  Blynk.begin(Serial, auth);
  while (Blynk.connect() == false) {
    SwSerial.begin(9600);
    Serial.begin(9600);
    Blynk.begin(Serial, auth);
  }
  pinMode(ledPin1, INPUT); // Tells the arduino ledPin1 and ledPin2 are inputs.
  pinMode(ledPin2, INPUT);
  pinMode(ledPin3, INPUT);
  pinMode(buzzer, OUTPUT);
}
BLYNK_WRITE(V1) // Code for the virtual pin on the blynk app. This pin is told to be button 1 and should execute the funtion stated below it.
{
  int b1 = param.asInt();

  if (b1 == 0)
  {
    threetotwo();
  }
}

BLYNK_WRITE(V2) // Code for the virtual pin on the blynk app. This pin is told to be button 2 and should execute the funtion stated below it.
{
  int b2 = param.asInt();

  if (b2 == 0)
  {
    threetoone();
  }
}
BLYNK_WRITE(V3) // Code for the virtual pin on the blynk app. This pin is told to be button 3 and should execute the funtion stated below it.
{
  int b3 = param.asInt();

  if (b3 == 0)
  {
    twotothree();
  }
}
BLYNK_WRITE(V4) // Code for the virtual pin on the blynk app. This pin is told to be button 4 and should execute the funtion stated below it.
{
  int b4 = param.asInt();

  if (b4 == 0)
  {
    twotoone();
  }
}
BLYNK_WRITE(V5) // Code for the virtual pin on the blynk app. This pin is told to be button 5 and should execute the funtion stated below it.
{
  int b5 = param.asInt();

  if (b5 == 0)
  {
    onetotwo();
  }
}
BLYNK_WRITE(V6) // Code for the virtual pin on the blynk app. This pin is told to be button 6 and should execute the funtion stated below it.
{
  int b6 = param.asInt();

  if (b6 == 0)
  {
    onetothree();
  }
}

void loop() {
  Blynk.run();
}
void threetotwo() { // Function for moving from floor 3-2 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin3, LOW);
  stepper.step(1000);
  tone(buzzer, 750, 300);
  delay(500);
}

void threetoone() { // Function for moving from floor 3-1 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  stepper.step(2000);
  tone(buzzer, 750, 300);
  delay(500);
}

void twotothree() { // Function for moving from floor 2-3 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  stepper.step(-1000);
  tone(buzzer, 750, 300);
  delay(500);
}

void twotoone() { // Function for moving from floor 2-1 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  stepper.step(900);
  tone(buzzer, 750, 300);
  delay(500);
}

void onetotwo() { // Function for moving from floor 1-2 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin3, LOW);
  stepper.step(-800);
  delay(500);
  tone(buzzer, 750, 300);
}

void onetothree() { // Function for moving from floor 1-3 turns on the led for the correct floor, rings the buzzer and moves to the desired floor.
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  stepper.step(-2000);
  tone(buzzer, 750, 300);
  delay(500);
}
