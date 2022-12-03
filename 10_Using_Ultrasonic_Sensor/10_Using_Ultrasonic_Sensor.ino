/*****************************************************
  Activity Name : Using Ultrasonic Sensor
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

#define TRIG_PIN 26 // ESP32 pin GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 25 // ESP32 pin GIOP25 connected to Ultrasonic Sensor's ECHO pin

float duration_us, distance_cm;
int count = 0 ; 

void setup() {
  lcd.begin();               // initialize the lcd
  lcd.backlight();           // open the backlight
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT); // config trigger pin to output mode
  pinMode(ECHO_PIN, INPUT);  // config echo pin to input mode
  lcd.clear();
  lcd.setCursor(0, 0);       // start to print at the first row
  lcd.print("     SOHAM");
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
}


void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  lcd.clear();
  lcd.setCursor(0, 0);      // start to print at the first row
  lcd.print("     SOHAM");
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.setCursor(10,1);
  lcd.print(distance_cm);
  Serial.print("distance:");
  Serial.print( distance_cm );
  delay(300);
}
