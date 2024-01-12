


int trigPin = 13; //sensor trig pin connected to pin 13
int echoPin = 11; //echo pin connected to pin 11
int yellowLed = 7; //relay input
float pingTime; // time for ping to travel to target disatance
float targetDistance; //distance of sensor to target
float speedOfSound = 776.5; //speed of sound in miles per hour
int redLed = 8;

void setup() {
  Serial.begin(9600); //turn on Serial Port
  pinMode(trigPin, OUTPUT); //sensor trig pin is output
  pinMode(echoPin, INPUT); //sensor echo pin in on input
  pinMode(yellowLed, OUTPUT);//relay input signal pin as output
  pinMode(redLed, OUTPUT);//relay input signal pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW); //set trigger pin low
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15); 
//  delay(2000);
  digitalWrite(trigPin, LOW);

  pingTime = pulseIn(echoPin, HIGH); //measure pingtime at echopin in microseconds
  pingTime = pingTime/1000000; //converts time to seconds
  pingTime = pingTime/3600; //converts time to hours

  targetDistance = speedOfSound*pingTime; //calculates distance in miles
  targetDistance = targetDistance/2; //accounts for round trip of ping to target
  targetDistance = targetDistance*63360; //converts targetdistance to inches

//  digitalWrite(relayInputSignal,HIGH); // LOW
//  delay(2000);
//  digitalWrite(relayInputSignal,LOW);

  if(targetDistance<=3.5){
    digitalWrite(yellowLed,HIGH); // on
  }else{
    digitalWrite(redLed, HIGH); //off
  }
  Serial.print("the distance to target is : ");
  Serial.print(targetDistance);
  Serial.println("inches");
  delay(1000);
  
}
