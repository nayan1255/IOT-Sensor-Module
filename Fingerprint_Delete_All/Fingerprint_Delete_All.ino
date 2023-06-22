#include <Adafruit_Fingerprint.h>

// ESP8266

int TXD = D3; // INPUT from Sensor
int RXD = D4; // OUTPUT from NodeMCU

SoftwareSerial mySerial(D3, D4); // Set up the serial port to use softwareserial..

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);

  Serial.println("\n\nDeleting all fingerprint templates!");
  Serial.println("Press 'Y' key to continue");

  while (1) {
    if (Serial.available() && (Serial.read() == 'Y')) {
      break;
    }
  }

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }

  finger.emptyDatabase();

  Serial.println("Now database is empty :)");
}

void loop() {
}
