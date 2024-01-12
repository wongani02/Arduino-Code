// int greenLED = 12;
int relayInputSignal= 7;

void setup() {
  // put your setup code here, to run once:
  // pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
  pinMode(relayInputSignal, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relayInputSignal, HIGH);
  //digitalWrite(greenLED, HIGH)
  Serial.println('high');
  delay(4000);
  digitalWrite(relayInputSignal, LOW);
  //digitalWrite(greenLED, HIGH)
  Serial.println('low');
  delay(4000);
}
