int ledButton = 12; // pin for the LED
int button = 8; // pin for the button
int buttonState = 0; // initial state for the button

int ledBlocking = 13; // pin for the blocking/blink LED

int interval = 500; // interval for turning LED on or off

int ledState = LOW; // initial LED state

long previousMillis = 0; // initial millisecond value to check against 

unsigned long currentMillis = 0; // initial millis for current millis of arduino program

void setup(){
  pinMode(ledButton, OUTPUT); // set up LED
  pinMode(button, INPUT); // set up button
  pinMode(ledBlocking, OUTPUT); // setup blocking/blinking LED
  Serial.begin(9600);  // start our serial monitor
}

void loop(){
  buttonState = digitalRead(button); // read our button
  
  /*
  single equal sign (=) - assignement ex. this variable is a new value
  double equal sign (==) - equality ex. is this variable the same value as another value
  */
  
  //this controls the LED with a button
  if (buttonState == HIGH){ // if button is pressed 
    digitalWrite(ledButton, HIGH); // make the LED light up
  } else if(buttonState == LOW){ // if button is not pressed (unpressed) 
    digitalWrite(ledButton, LOW); // turn the LED off
  }

  // set our variable current mills to the actual milliseconds since program started
  currentMillis = millis();
  
  /*
  print useful debug information
  */
  
  Serial.print("Cur: ");
  Serial.print(currentMillis);
  
  Serial.print(" Prev: ");
  Serial.print(previousMillis);
  
  Serial.print(" Diff: ");
  Serial.println(currentMillis - previousMillis);

  //  this controls the LED that is blinking
  // if the difference between current time in the program minus the last checkpoint time is greater than our interval
  if(currentMillis - previousMillis > interval){ 

  Serial.println("THE INTERVAL BETWEEN CURR AND PREVIOUS IS LONG ENOUGH!!!");
  previousMillis = currentMillis; // reset our detect time check point to the current time to check again in another interval
  
  //switch from on to off or off to on
  if (ledState == LOW){ // if the LED is off
    ledState = HIGH; // set our LED state variable to on
  } else if (ledState == HIGH){ // if the LED is on
    ledState = LOW; // set out LED state variable to off
  }
  
  digitalWrite(ledBlocking, ledState); // use our LED state variable to turn the LED on or off
  
  }  

}


