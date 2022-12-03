/*****************************************************
  Activity Name : Displaying Date and Time  on LCD
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/
#include <SPI.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int Day;
int Month;
int Year;
int Secs;
int Minutes;
int Hours;
char* dofweek;

String myDate;
String myTime;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  if (! rtc.begin()) {
    
    Serial.println("Couldn't find RTC");
    while (1){
        Serial.print("DATE:");
     Serial.println(F(__DATE__));
      }
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Following line sets the RTC with an explicit date & time
    // for example to set January 26 2023 at 12:56 you would call:
    // rtc.adjust(DateTime(2023, 1, 26, 12, 56, 0));
  }
  lcd.setCursor(5, 0);
  lcd.print("SOHAM");
  lcd.setCursor(0, 1);
  lcd.print("  DIGITAL CLOCK");
  lcd.display();
  delay(3000);
}


void loop()

{
  DateTime now = rtc.now();
  lcd.clear();
  Day = now.day();
  Month = now.month();
  Year = now.year();
  Secs = now.second();
  Hours = now.hour();

  Minutes = now.minute();
  dofweek = daysOfTheWeek[now.dayOfTheWeek()];

  myDate = myDate + Day + "/" + Month + "/" + Year ;
  myTime = myTime + Hours + ":" + Minutes + ":" + Secs ;
  // send to serial monitor
  Serial.println(dofweek);
  Serial.println(myDate);
  Serial.println(myTime);
  //Print on lcd
  lcd.setCursor(0, 0);
  lcd.print("Date :");
  lcd.print(myDate);
  lcd.setCursor(0, 1);
  lcd.print("Time :");
  lcd.print(myTime);
  myDate = "";
  myTime = "";
  delay(1000);
}
