/*****************************************************
  Activity Name: Im In A Mood For
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

#include "LiquidCrystal_I2C.h"
// Global variables
byte IR_val      = 0;
byte prev_IR_val = 1;
byte reply           = 0; // varies sfrom 0 to 7
const byte IR_PIN = 2  ;
String Msg1 = "SOHAM";
String Msg2 = "IM IN A MOOD FOR";
LiquidCrystal_I2C Lcd(0x27, 16, 2);
int Count = 0 ;

void printMsg(String msg1 , String msg2) {
  Lcd.clear();
  Lcd.setCursor(0, 0);
  Lcd.print(msg1);
  Lcd.setCursor(0, 1);
  Lcd.print(msg2);
  delay(500);
}

void setup() {
  Lcd.begin();
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
  // intro message
  printMsg(Msg1, Msg2);
}

void loop()  {
IR_val = digitalRead(IR_PIN);
  Serial.println(IR_val);
  if ((prev_IR_val == 1) && (IR_val == LOW)) {
    if (Count == 5) {
      Lcd.clear();
      Lcd.setCursor(0, 0);
      Lcd.print("PLEASE BE QUIET,");
      Serial.println(" I AM NOT IN A MOOD");
      Lcd.setCursor(0, 1);
      Lcd.print(" I'M NOT IN MOOD");
      Count++;
      }
    else {
      reply = random(12); // randomly choose 1 out of 12 anwers
      Lcd.clear();
      Lcd.setCursor(0, 0);
      Lcd.print(" I AM IN A MOOD");
      Serial.println(" I AM IN A MOOD");
      Lcd.setCursor(0, 1);
      //    delay(1000);
      switch (reply) {
        case 0:
          Lcd.print(" FOR ICE CREAM");
          Count++;
          break;
        case 1:
          Lcd.print(" TO WATCH MOVIE");
          Count++;
          break;
        case 2:
          Lcd.print(" TO LISTEN SONGS");
          Count++;
          break;
        case 3:
          Lcd.print("  TO DANCE");
          Count = 0 ;
          break;
        case 4:
          Lcd.print(" TO SING A SONG");
          break;
          Count++;
        case 5:
          Lcd.print(" TO KICK SOMEONE");
          Count = 0;
          break;
        case 6:
          Lcd.print("TO GO OUT TO EAT");
          Count++;
          break;
        case 7:
          Lcd.print("  FOR SHOPPING");
          Count++;
          break;
        case 8:
          Lcd.print("    TO SLEEP");
          Count++;
          break;
        case 9:
          Lcd.print("  TO MAKE REEL");
          Count++;
          break;
        case 10:
          Lcd.print("   TO FIGHT");
          Count++;
          break;
        case 11:
          Lcd.print("   TO STUDY");
          Count++;
          break;
      }
    }
    while(!digitalRead(IR_PIN));
//      delay(2500); // wait for 2.5 sec 
      Lcd.clear(); // the display is cleared
      Lcd.setCursor(0, 0); //set the cursor position at the column = 0 , row = 0 
      Lcd.print(Msg1);
      Lcd.setCursor(0, 1); //set the cursor position at the column = 0 , row = 1 
      Lcd.print(Msg2);
      delay(500);
  }
   prev_IR_val = IR_val;
}
