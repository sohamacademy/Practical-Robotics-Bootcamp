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
        case 'a': digitalWrite(Light, HIGH); break;    // if 'a' received Turn on Light
        case 'b': digitalWrite(Light, LOW); break;     // if 'b' received Turn off Light
        case 'c': digitalWrite(Fan, HIGH);  break;     // if 'c' received Turn on Fan
        case 'd': digitalWrite(Fan, LOW);  break;      // if 'd' received Turn off Fan
        case 'e': digitalWrite(Tv, HIGH); break;       // if 'e' received Turn on Tv
        case 'f': digitalWrite(Tv, LOW); break;        // if 'f' received Turn off Tv
        case 'g': digitalWrite(Ac, HIGH); break;       // if 'g' received Turn on Ac
        case 'h': digitalWrite(Ac, LOW);  break;       // if 'h' received Turn off Ac
        case 'i': all_Switch_ON(); break;              // if 'i' received Turn on all 
        case 'j': all_Switch_OFF(); break;             // if 'j' received Turn off all 
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
  digitalWrite(Light, LOW);
  digitalWrite(Fan, LOW);
  digitalWrite(Tv, LOW);
  digitalWrite(Ac, LOW);
  delay(100);

}

void loop()
{  
    if (SerialBT.available()){
      Serial.println("Bluetooth_Connected");
      Bluetooth_handle();
    }
  } 
