/*****************************************************
  Activity Name: Smart Fan
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

const int trigPin = 22;               //esp32 d23 pin connected to trig Pin of the ultrasonic sensor
const int echoPin = 23;               //esp32 d22 pin connected to echo Pin of the ultrasonic sensor
const int Input3 = 26;                 //esp32 d26 pin connected to L293D pin input3
const int Input4 = 27;                 //esp32 d27  pin connected to L293D pin input4


void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (Input4, OUTPUT);
  pinMode (Input3, OUTPUT);
  
  Serial.begin(9600);
}

long duration, distance;
void stop()
{
  digitalWrite(Input4, LOW); 
  digitalWrite(Input3, LOW); 
}

void start()
{
  digitalWrite(Input4, HIGH); 
  digitalWrite(Input3, LOW); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;        // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  Serial.println(distance);        // The echo travels out and back, so to find the distance of the object we take half of the distance travelled.
  Serial.println("distance: ");
  if(distance<20)
  {      
    start();
    delay(250);
  }
  else
  {
    stop();
    delay(250);
  }
}
