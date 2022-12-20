/*****************************************************
  Activity Name: Counter Using IR Sensor
  Organisation: Soham Academy Of Human Excellence
  Website: https://ria.sohamacademy.org/
****************************************************/

#define aPin 8  //        
#define bPin 9  //      _____
#define cPin 3  //     |  A  |
#define dPin 4  //   F |_____| B
#define ePin 5  //     |  G  |
#define fPin 7  //   E |_____| C
#define gPin 6  //        D     O dot
#define irPin 2

boolean On = HIGH;  //<On=0; for Common anode> <On=1; for Common cathode>
boolean Off = LOW;
boolean IRState = true ;
boolean prevIRState = true ;

int count = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Soham Acadmey of Human Excellence");
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(irPin, INPUT);
  zero();
}

void loop()  {
  IRState = digitalRead(irPin);
  Serial.println(IRState);
  if ((prevIRState == 1) && (IRState == LOW)) {
   count++;
  }
  if(count < 9){
    count++;
    showNumber(count);
  }
  else{
    count = 0;
    showNumber(count); 
  }
  prevIRState = IRState;
}

void showNumber(int x) {
  switch (x){
    case 1: one();   break;
    case 2: two();   break;
    case 3: three(); break;
    case 4: four();  break;
    case 5: five();  break;
    case 6: six();   break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine();  break;
    case 0: zero(); break;
  }
}

void one() {
  digitalWrite( aPin, Off); //
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //      |
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
}

void two() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, Off); //  ____|
  digitalWrite( dPin, On);  // |
  digitalWrite( ePin, On);  // |____
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
}

void three() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //  ____|
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, Off);
  digitalWrite( gPin, On);
}

void four() {
  digitalWrite( aPin, Off); //
  digitalWrite( bPin, On);  // |    |
  digitalWrite( cPin, On);  // |____|
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void five() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, Off); // |
  digitalWrite( cPin, On);  // |____
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void six() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, Off); // |
  digitalWrite( cPin, On);  // |____
  digitalWrite( dPin, On);  // |    |
  digitalWrite( ePin, On);  // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void seven() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  //      |
  digitalWrite( cPin, On);  //      |
  digitalWrite( dPin, Off); //      |
  digitalWrite( ePin, Off); //      |
  digitalWrite( fPin, Off);
  digitalWrite( gPin, Off);
}

void eight() {
  digitalWrite( aPin, On); //  ____
  digitalWrite( bPin, On); // |    |
  digitalWrite( cPin, On); // |____|
  digitalWrite( dPin, On); // |    |
  digitalWrite( ePin, On); // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void nine() {
  digitalWrite( aPin, On);  //  ____
  digitalWrite( bPin, On);  // |    |
  digitalWrite( cPin, On);  // |____|
  digitalWrite( dPin, On);  //      |
  digitalWrite( ePin, Off); //  ____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, On);
}

void zero() {
  digitalWrite( aPin, On); //  ____
  digitalWrite( bPin, On); // |    |
  digitalWrite( cPin, On); // |    |
  digitalWrite( dPin, On); // |    |
  digitalWrite( ePin, On); // |____|
  digitalWrite( fPin, On);
  digitalWrite( gPin, Off);
}
