#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

int RedLED = 7;
int greenLED = 6;
int onTime = 5000;
int offTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(RedLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

}

void loop() {
  // put your main code here, to run repeatedly:
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

  Serial.print("UID tag: ");
  String content = "";
  byte letter;
  for (byte i=0; i<mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i]<0x10 ?)
  }

  if (mfrc522.uid == "8A f2 8F 08"){
    Serial.print("access granted");
    digitalWrite(greenLED, HIGH);
    delay(onTime);
  }else{
    Serial.print("access denied");
    digitalWrite(RedLED, HIGH);
    delay(onTime);
  }

}
