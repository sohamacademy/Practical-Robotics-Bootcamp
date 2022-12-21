/*****************************************************
  Activity Name: Counter using IR Sensor
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

int  aSegment = 10;
int  bSegment = 11;
int  cSegment = 5;
int  dSegment = 6;
int  eSegment = 7;
int  fSegment = 9;
int  gSegment = 8;
int irPin = 2; 
int time = 100;
int t = 0;

boolean irState = LOW ;
boolean prevState = HIGH ;

void setup()
{
  Serial.begin(9600);
  Serial.print("IR state:");
  Serial.println(digitalRead(irPin));
  pinMode(aSegment, OUTPUT);
  pinMode(bSegment, OUTPUT);
  pinMode(cSegment, OUTPUT);
  pinMode(dSegment, OUTPUT);
  pinMode(eSegment, OUTPUT);
  pinMode(fSegment, OUTPUT);
  pinMode(gSegment, OUTPUT);
  pinMode( irPin, INPUT);
}

void loop()
{
  Serial.println(digitalRead(irPin));
  irState = digitalRead(irPin);
  if ( !irState && prevState) {
    t++;
    delay(100);
    prevState = irState ;
  }
  else{
    prevState = irState ;
  }

  if (t == 0) {
    pattern0();
  }
  if (t == 1) {
    pattern1();
  }
  if (t == 2) {
    pattern2();
  }
  if (t == 3) {
    pattern3();
  }
  if (t == 4) {
    pattern4();
  }
  if (t == 5) {
    pattern5();
  }
  if (t == 6) {
    pattern6();
  }
  if (t == 7) {
    pattern7();
  }
  if (t == 8) {
    pattern8();
  }
  if (t == 9) {
    pattern9();
  }
  if (t == 10) {
    pattern10();
  }
}
void pattern0() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, HIGH);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, LOW);
  delay(time);
}
void pattern1() {
  digitalWrite(aSegment, LOW);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, LOW);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, LOW);
  digitalWrite(gSegment, LOW);
  delay(time);
}

void pattern2() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, LOW);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, HIGH);
  digitalWrite(fSegment, LOW);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern3() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, LOW);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern4() {
  digitalWrite(aSegment, LOW);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, LOW);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern5() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, LOW);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern6() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, LOW);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, HIGH);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern7() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, LOW);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, LOW);
  digitalWrite(gSegment, LOW);
  delay(time);
}

void pattern8() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, HIGH);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, HIGH);
  delay(time);
}

void pattern9() {
  digitalWrite(aSegment, HIGH);
  digitalWrite(bSegment, HIGH);
  digitalWrite(cSegment, HIGH);
  digitalWrite(dSegment, HIGH);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, HIGH);
  digitalWrite(gSegment, HIGH);
  delay(time);
}
void pattern10() {
  digitalWrite(aSegment, LOW);
  digitalWrite(bSegment, LOW);
  digitalWrite(cSegment, LOW);
  digitalWrite(dSegment, LOW);
  digitalWrite(eSegment, LOW);
  digitalWrite(fSegment, LOW);
  digitalWrite(gSegment, LOW);
  delay(time);
  t = 0;
}


                             
