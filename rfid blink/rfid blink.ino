#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   

int RedLED = 7;
int greenLED = 6;
int onTime = 5000;
int offTime = 1000;
 
void setup() 
{
  Serial.begin(9600);  
  SPI.begin();      
  mfrc522.PCD_Init();   
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  pinMode(RedLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}
void loop() 
{
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
 
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "8A F2 8F 08") // Make sure you change this with your own UID number
  {
    Serial.println("Authorised access");
    Serial.println();
    delay(3000);
    digitalWrite(greenLED, HIGH);
    delay(onTime);
    
  }
 
 else   {
    Serial.println(" Access denied");
    delay(3000);
    digitalWrite(RedLED, HIGH);
    delay(onTime);
    digitalWrite(RedLED, LOW);
    delay(offTime);

  }

}