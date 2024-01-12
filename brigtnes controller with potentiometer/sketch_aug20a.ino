
int potPin = A0;
int readValue; 
//float Voltage;
int redLed = 10;
int writeValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);         // turn on serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  readValue = analogRead(potPin);
  //Serial.println(readValue);
  writeValue = (255.0/1023.0)*readValue;
  analogWrite(redLed, writeValue);
  Serial.println(writeValue);
  delay(1000);

}
