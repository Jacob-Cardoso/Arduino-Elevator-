#include <Stepper_28BYJ_48.h> // Imports the stepper library.
Stepper_28BYJ_48 stepper(6, 5, 4, 3); // Declares the pins the stepper motor is plugged into.

const int buttonPin1 = 7; // Variables that will not change. Button 1, 2 and Led 1, 2.
const int buttonPin2 = 8;
const int buttonPin3 = 9;
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int buzzer = 13;

int limitState = 0;
int buttonState1 = 0; // State of Button 1 allows it to be read and know if it is pressed or not.
int buttonState2 = 0; // State of Button 2 allows it to be read and know if it is pressed or not.
int buttonState3 = 0;
int floorState = 3; // Knows what floor the elevator is on this is used for most of the code.

bool homed = false;

void setup() {
  pinMode(buttonPin1, INPUT); // Tells the computer buttonPin1 and buttonPin2 are inputs.
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(ledPin1, INPUT); // Tells the computer ledPin1 and ledPin2 are inputs.
  pinMode(ledPin2, INPUT);
  pinMode(ledPin3, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  while (! Serial); // Allows the serial to initialise this helps to get rid of possible errors in timing.
  Serial.println("Enter the floor you would like to reach:"); //Prints to the serial monitor.

}

void loop() {
  buttonState1 = digitalRead(buttonPin1); //Lets the arduino know  buttonState1, buttonState2 are to be read from pin 1 and 2.
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  limitState = digitalRead(2);
  if (homed == false) {
    
    if (limitState == LOW) {
      stepper.step(-5000);
      delay(10);

    }

    if (limitState == HIGH) {

      stepper.step(0);
    }
  }

  if (limitState == HIGH) {
    
    homed = true;
    stepper.step(0);
  }
  if (homed == true);{
    digitalWrite(ledPin3, HIGH);
  }

  if (Serial.available())  { // Gets the number of characters available for reading the serial port.
    char ch = Serial.read(); // Char variable type is used to hold a single byte/character in this case the number 1, 2, or 3 and reads what it is.
    if (ch == '1') { // If the user inputs floor 1 it executes the code below.
      digitalWrite(ledPin1, HIGH); // Turn on led 1 and turn off 2 and 3.
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);

      if (floorState == 3) { // If the floor is set to 3 then execute the following code.
        stepper.step(2000); // Move the stepper down 2000.
        digitalWrite(ledPin1, HIGH); // Turn on the led.
        delay(300); //Delay 300 milliseconds.
        digitalWrite(ledPin1, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin1, HIGH);
        delay(300);
        digitalWrite(ledPin1, LOW);
        delay(300);
        digitalWrite(ledPin1, HIGH);
        delay(300);
        digitalWrite(ledPin1, LOW);
        delay(100);
        digitalWrite(ledPin1, HIGH);
        floorState = 1; // Set the floorstate to 1 because the elevator is now at floor 1.
        tone(buzzer, 750, 300); // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.


      }
      if (floorState == 2) { // If the floor is set to 2 then execute the following code.
        stepper.step(900); // Move the stepper down 900.
        digitalWrite(ledPin1, HIGH); // Turn on the led.
        delay(300); //Delay 300 milliseconds.
        digitalWrite(ledPin1, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin1, HIGH);
        delay(300);
        digitalWrite(ledPin1, LOW);
        delay(300);
        digitalWrite(ledPin1, HIGH);
        delay(300);
        digitalWrite(ledPin1, LOW);
        delay(100);
        digitalWrite(ledPin1, HIGH);
        floorState = 1; // Set the floorstate to 1 because the elevator is now at floor 1.
        tone(buzzer, 750, 300); // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.

      }
    }
    if (ch == '2') { // If the user inputs floor 2 it executes the code below.
      digitalWrite(ledPin2, HIGH); // Turn on led 2 and turn off 1 and 3.
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin3, LOW);
      if (floorState == 3) { // If the floor is set to 3 then execute the following code.

        stepper.step(1000); // Move the stepper down 1000.
        digitalWrite(ledPin2, HIGH); // Turn on the led.
        delay(300); //Delay 300 milliseconds.
        digitalWrite(ledPin2, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin2, HIGH);
        delay(300);
        digitalWrite(ledPin2, LOW);
        delay(300);
        digitalWrite(ledPin2, HIGH);
        delay(300);
        digitalWrite(ledPin2, LOW);
        delay(100);
        digitalWrite(ledPin2, HIGH);
        floorState = 2; // Set the floorstate to 2 because the elevator is now at floor 2.
        tone(buzzer, 750, 300); // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.

      }
      if (floorState == 1) { // If the floor is set to 1 then execute the following code.

        stepper.step(-800); // Move the stepper up 800.
        digitalWrite(ledPin2, HIGH); // Turn on the led.
        delay(300);  //Delay 300 milliseconds.
        digitalWrite(ledPin2, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin2, HIGH);
        delay(300);
        digitalWrite(ledPin2, LOW);
        delay(300);
        digitalWrite(ledPin2, HIGH);
        delay(300);
        digitalWrite(ledPin2, LOW);
        delay(100);
        digitalWrite(ledPin2, HIGH);
        floorState = 2; // Set the floorstate to 2 because the elevator is now at floor 2.
        tone(buzzer, 750, 300); // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Up!"); // Print to the serial monitor the elevator is going up.

      }
    }

    if (ch == '3') { // If the user inputs floor 3 it executes the code below.
      digitalWrite(ledPin3, HIGH);  // Turn on led 3 and turn off 1 and 2.
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      if (floorState == 2) { // If the floor is set to 2 then execute the following code.

        stepper.step(-1000); // Move the stepper up 1000.
        digitalWrite(ledPin3, HIGH); // Turn on the led.
        delay(300);  //Delay 300 milliseconds.
        digitalWrite(ledPin3, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin3, HIGH);
        delay(300);
        digitalWrite(ledPin3, LOW);
        delay(300);
        digitalWrite(ledPin3, HIGH);
        delay(300);
        digitalWrite(ledPin3, LOW);
        delay(100);
        digitalWrite(ledPin3, HIGH);

        floorState = 3; // Set the floorstate to 3 because the elevator is now at floor 3.
        tone(buzzer, 750, 300);  // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Up!"); // Print to the serial monitor the elevator is going up.

      }

      if (floorState == 1) {  // If the floor is set to 1 then execute the following code.

        stepper.step(-2000); // Move the stepper up 2000.
        digitalWrite(ledPin3, HIGH); // Turn on the led.
        delay(300); //Delay 300 milliseconds.
        digitalWrite(ledPin3, LOW); // Turn off the led.
        delay(300);
        digitalWrite(ledPin3, HIGH);
        delay(300);
        digitalWrite(ledPin3, LOW);
        delay(300);
        digitalWrite(ledPin3, HIGH);
        delay(300);
        digitalWrite(ledPin3, LOW);
        delay(100);
        digitalWrite(ledPin3, HIGH);
        floorState = 3; // Set the floorstate to 3 because the elevator is now at floor 3.
        tone(buzzer, 750, 300); // Ring the buzzer to signify the elevator has arrived. buzzer stands for the pin parameter 750 is the frequency and the duration is 300 milliseconds.
        Serial.print("Going Up!");  // Print to the serial monitor the elevator is going up.


      }
    }
  }





  if (buttonState1 == HIGH) { // If button 1 is pressed execute the following code.
    digitalWrite(ledPin1, HIGH); // Turn led 1 on and turn off 2 and 3.
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

    if (floorState == 3) { // If the floor is set to 3 then execute the following code.
      stepper.step(2000); // Move the stepper down 2000.
      digitalWrite(ledPin1, HIGH); // Turn on the led
      delay(300); // Delay 300 milliseconds
      digitalWrite(ledPin1, LOW); // Turn off the led.
      delay(300);
      digitalWrite(ledPin1, HIGH);
      delay(300);
      digitalWrite(ledPin1, LOW);
      delay(300);
      digitalWrite(ledPin1, HIGH);
      delay(300);
      digitalWrite(ledPin1, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      floorState = 1; // Set the floorstate to 1 because the elevator is now at floor 1.
      tone(buzzer, 750, 300);
      Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.


    }

    if (floorState == 2) { // If the floor is set to 2 then execute the following code.
      stepper.step(900);// Move the stepper down 900.
      digitalWrite(ledPin1, HIGH); // Turn on the led.
      delay(300); // Delay 300 milliseconds.
      digitalWrite(ledPin1, LOW); // Turn off the led.
      delay(300);
      digitalWrite(ledPin1, HIGH);
      delay(300);
      digitalWrite(ledPin1, LOW);
      delay(300);
      digitalWrite(ledPin1, HIGH);
      delay(300);
      digitalWrite(ledPin1, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      floorState = 1; // Set the floorstate to 1 because the elevator is now at floor 1.
      tone(buzzer, 750, 300);
      Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.

    }

  }

  if (buttonState2 == HIGH) { // If button 2 is pressed execute the following code.
    digitalWrite(ledPin2, HIGH);  // Turn on led 2 and turn off 1 and 3.
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin3, LOW);

    if (floorState == 3) { // If the floor is set to 3 then execute the following code.

      stepper.step(1000); // Move the stepper down 1000.
      digitalWrite(ledPin2, HIGH); // Turn on the led.
      delay(300); //Delay 300 milliseconds.
      digitalWrite(ledPin2, LOW); // Turn off the led.
      delay(300);
      digitalWrite(ledPin2, HIGH);
      delay(300);
      digitalWrite(ledPin2, LOW);
      delay(300);
      digitalWrite(ledPin2, HIGH);
      delay(300);
      digitalWrite(ledPin2, LOW);
      delay(100);
      digitalWrite(ledPin2, HIGH);
      floorState = 2; // Set the floorstate to 2 because the elevator is now at floor 2.
      tone(buzzer, 750, 300);
      Serial.print("Going Down!"); // Print to the serial monitor the elevator is going down.

    }

    if (floorState == 1) { // If the floor is set to 1 then execute the following code.

      stepper.step(-800); // Move the stepper up 800.
      digitalWrite(ledPin2, HIGH);  // Turn on the led.
      delay(300); //Delay 300 milliseconds
      digitalWrite(ledPin2, LOW);  // Turn off the led
      delay(300);
      digitalWrite(ledPin2, HIGH);
      delay(300);
      digitalWrite(ledPin2, LOW);
      delay(300);
      digitalWrite(ledPin2, HIGH);
      delay(300);
      digitalWrite(ledPin2, LOW);
      delay(100);
      digitalWrite(ledPin2, HIGH);
      floorState = 2; // Set the floorstate to 2 because the elevator is now at floor 2.
      tone(buzzer, 750, 300);
      Serial.print("Going Up!"); // Print to the serial monitor the elevator is going up.

    }
  }

  if (buttonState3 == HIGH) {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);

    if (floorState == 2) {

      stepper.step(-1000);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(300);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(300);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin3, HIGH);

      floorState = 3;
      tone(buzzer, 750, 300);
      Serial.print("Going Up!");

    }

    if (floorState == 1) {

      stepper.step(-2000);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(300);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(300);
      digitalWrite(ledPin3, HIGH);
      delay(300);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin3, HIGH);
      floorState = 3;
      tone(buzzer, 750, 300);
      Serial.print("Going Up!");

    }
  }
}
