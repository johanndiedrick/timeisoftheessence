
int sensorValue = 0;

void setup(){
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  //get potentiometer value
  //sensorValue = (analogRead(A0))/4;
  sensorValue = map(analogRead(A0), 0, 1023, 50, 150);
  
  //print information about sensor value
  Serial.println(sensorValue);
  
  //turn led on
  digitalWrite(13, HIGH);
  
  //wait
  delay(sensorValue);
  
  //turn led off
  digitalWrite(13, LOW);
  
  //wait
  delay(sensorValue);
  

  
}
