/*****************************************************
  Activity Name : Home Automation
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

#include "BluetoothSerial.h" 

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run
`make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

//Name of the Bluetooth
String bt_name=" Soham_BT_1100";

#define Light 18  //D18
#define Fan 19  //D19
#define Tv 21  //D21
#define Ac 22  //D22

char bt_data; // variable for storing bluetooth data 


void all_Switch_ON(){
  digitalWrite(Light, HIGH); 
  digitalWrite(Fan, HIGH);  
  digitalWrite(Tv, HIGH);  
  digitalWrite(Ac, HIGH);  
}

void all_Switch_OFF(){
  digitalWrite(Light, LOW); 
  digitalWrite(Fan, LOW);   
  digitalWrite(Tv, LOW);  
  digitalWrite(Ac, LOW); 
}

void Bluetooth_handle()
{
  bt_data = SerialBT.read();
  Serial.println(bt_data);
  delay(20);

  switch(bt_data)
      {
        case '1': digitalWrite(Light, HIGH); break;    // if '1' received Turn on Light
        case '2': digitalWrite(Light, LOW); break;     // if '2' received Turn off Light
        case '3': digitalWrite(Fan, HIGH);  break;     // if '3' received Turn on Fan
        case '4': digitalWrite(Fan, LOW);  break;      // if '4' received Turn off Fan
        case '5': digitalWrite(Tv, HIGH); break;       // if '5' received Turn on Tv
        case '6': digitalWrite(Tv, LOW); break;        // if '6' received Turn off Tv
        case '7': digitalWrite(Ac, HIGH); break;       // if '7' received Turn on Ac
        case '8': digitalWrite(Ac, LOW);  break;       // if '8' received Turn off Ac
        case '9': all_Switch_ON(); break;              // if '9' received Turn on all 
        case '0': all_Switch_OFF(); break;             // if '0' received Turn off all 
        default : break;
      }
}


void setup()
{
  Serial.begin(115200);
  btStart();               //Serial.println("Bluetooth On");
  SerialBT.begin(bt_name); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);

  pinMode(Light, OUTPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Tv, OUTPUT);
  pinMode(Ac, OUTPUT);
    
  //During Starting all Relays should TURN OFF
  digitalWrite(Light, HIGH);
  digitalWrite(Fan, HIGH);
  digitalWrite(Tv, HIGH);
  digitalWrite(Ac, HIGH);
  delay(100);
  digitalWrite(Light, HIGH);
  digitalWrite(Fan, HIGH);
  digitalWrite(Tv, HIGH);
  digitalWrite(Ac, HIGH);
  delay(100);

}

void loop()
{  
    if (SerialBT.available()){
      Serial.println("Bluetooth_Connected");
      Bluetooth_handle();
    }
  } 
