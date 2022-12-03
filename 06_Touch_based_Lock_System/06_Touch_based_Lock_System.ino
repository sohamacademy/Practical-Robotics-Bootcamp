/*****************************************************
  Activity Name : Touch based lock system
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>
const int servoPin = 3; // Servo pin
const int touchPin = 7; // touch pin
int ledPin = 5;
int touchState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
  lcd.begin();
  lcd.print(" Touch Based");
  lcd.setCursor(0, 1);
  lcd.print("Door Lock System");
  myservo.attach(3);
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  touchState = digitalRead(touchPin);
  delay(50);
  if (directionState == 0) {
    if (touchState == HIGH) {
      directionState = 1;
      digitalWrite(ledPin, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Status: Unlocked");
      lcd.setCursor(0, 1);
      lcd.print(" Touch to Lock");
      delay(100);
      for (pos = 0; pos <= 120; pos += 10)
      {
        myservo.write(pos);
        delay(10); // waits 15ms to reach the position
      }
    }
  }
  else if (directionState == 1) {
    if (touchState == HIGH) {
      directionState = 0;
      digitalWrite(ledPin, 0);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Status: Locked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Unlock");
      delay(100);
      for (pos = 120; pos >= 0; pos -= 10)
      {
        myservo.write(pos);
        delay(10);
      }
    }
  }
}
