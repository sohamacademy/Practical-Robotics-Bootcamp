/*****************************************************
  Activity Name: Gaming Dice
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

// Pin configuration
#define PIN_BUTTON A0
#define PIN_BUZZER 11

const byte PIN_CHAOS = A5; //Unconnected analog pin used to initialize RNG

// Other configuration
const unsigned int BEEP_FREQUENCY = 2000;

int On = 1; //<On=0; for Common anode> <On=1; for Common cathode>
int Off;

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Soham Acadmey of Human Excellence");
  randomSeed(analogRead(PIN_CHAOS));
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);

  pinMode(PIN_BUTTON, INPUT_PULLUP);    // On button pin as input with pullup
  pinMode(PIN_BUZZER, OUTPUT);          // On buzzer pin as output

  // Indicate that system is ready
  for (int i = 6; i >= 1; i--) {
    showNumber(i);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 100);
    delay(300);
  }
  tone(PIN_BUZZER, BEEP_FREQUENCY, 250);  // Beep when done
  delay(1000);                            // Wait for 1 second
}

void loop() {
   Serial.println("Hello Gaming Dice");
  // Wait for button to be pressed, then run the test routine
  int buttonState = digitalRead(PIN_BUTTON);
  if (buttonState == LOW) {                 //Check whether the button is pressed or not.
    rollTheDice(10, 100);                   // Show the rolling animation
    rollTheDice(5, 300);
    rollTheDice(3, 400);
    rollTheDice(1, 100);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 250);  // Beep when done
  }
}

void rollTheDice(int count, int delayLength) {
  for (int i = 0; i < count; i++) {
    int number = random(1, 7);            // Get random number from 1 to 6
    tone(PIN_BUZZER, BEEP_FREQUENCY, 5);  // Beep very shortly ("click")
    showNumber(number);                   // Show the number
    delay(delayLength);                   // Wait
  }
}


void showNumber(int x) {

  if (On == 1)
  {
    Off = 0;
  }
  else {
    Off = 1;
  }
  switch (x) {
    case 1: one();   break;
    case 2: two();   break;
    case 3: three(); break;
    case 4: four();  break;
    case 5: five();  break;
    case 6: six();   break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine();  break;
    default: zero(); break;
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
