#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(D3, D4);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

String member = "";
int flag = 0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("WELCOME");
  delay(2000);

  lcd.clear();

  while (!Serial);
  delay(100);
  Serial.println("\n\n Waiting for Fingerprint Sensor");
  lcd.setCursor(0, 0);
  lcd.print("    Waiting for           ");
  lcd.setCursor(0, 1);
  lcd.print("      Sensor              ");
  delay(1500);
  finger.begin(57600);

  if (finger.verifyPassword())
  {
    Serial.println("Found Successfully");
    lcd.setCursor(0, 0);
    lcd.print("Sensor found!         ");
    lcd.setCursor(0, 1);
    lcd.print("                      ");
    delay(1500);
  } else
  {
    Serial.println("Fingerprint sensor not found!!!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Not found!         ");
    lcd.setCursor(0, 1);
    lcd.print("                      ");
    while (1)
    {
      delay(1);
    }
  }
}

void loop()
{
  int fingerprintID = getFingerprintID();
  delay(50);
  if (fingerprintID == 1)
  {
    Serial.println("Welcome Nayan1");
    lcd.setCursor(0, 0);
    lcd.print("Welcome          ");
    lcd.setCursor(0, 1);
    lcd.print("                       ");
    flag = 0;
  }
  else if (fingerprintID == 2)
  {
    Serial.println("Welcome Nayan2");
    lcd.setCursor(0, 0);
    lcd.print("Welcome Manas          ");
    lcd.setCursor(0, 1);
    lcd.print("                       ");
    flag = 0;
  }
  else if (fingerprintID == 3)
  {
    Serial.println("Welcome Tara");
    lcd.setCursor(0, 0);
    lcd.print("Welcome Tara           ");
    lcd.setCursor(0, 1);
    lcd.print("                       ");
    flag = 0;
  }
  else
  {
    Serial.println("Waiting for valid finger!!!");
    lcd.setCursor(0, 0);
    lcd.print(" Place a Valid       ");
    lcd.setCursor(0, 1);
    lcd.print("     Finger           ");
  }
}

int getFingerprintID()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  return finger.fingerID;
}
