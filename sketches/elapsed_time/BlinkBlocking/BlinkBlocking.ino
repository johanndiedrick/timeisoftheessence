/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledButton = 12;
int ledBlocking = 13;
int button = 2;
int buttonState = 0;

int delayTime = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledButton, OUTPUT);     
  pinMode(ledBlocking, OUTPUT);     
  pinMode(button, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    digitalWrite(ledButton, HIGH);
  } else if (buttonState == LOW) {
    digitalWrite(ledButton, LOW);
  }
    
    //comment out here to test blocking button
    
  digitalWrite(ledBlocking, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(ledBlocking, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
  
}
