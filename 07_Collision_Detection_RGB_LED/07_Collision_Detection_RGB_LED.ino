#define TRIG_PIN 26 // ESP32 pin GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 25 // ESP32 pin GIOP25 connected to Ultrasonic Sensor's ECHO pin

#define redPin    23 // GIOP23
#define greenPin  22 // GIOP22
#define bluePin   21 // GIOP21

float duration_us, distance_cm;

void setup() {
Serial.begin(9600);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
pinMode(TRIG_PIN, OUTPUT); // config trigger pin to output mode
pinMode(ECHO_PIN, INPUT);  // config echo pin to input mode
}
 
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if( distance_cm < 10){
 Serial.println(distance_cm);
 analogWrite(redPin,255);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0); 
  delay(500);
  }
  else if(distance_cm < 20){
  //yellow
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
  delay(500);
  }
  else if(distance_cm < 30){
  //green
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
  delay(500);
  }
  else{
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);
  delay(500);
  }
}
