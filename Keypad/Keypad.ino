#include <Keypad.h>
 
const byte n_rows = 4;
const byte n_cols = 4;
 
char keys[n_rows][n_cols] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// ESP8266
byte colPins[n_rows] = {D3, D2, D1, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 
 
void setup()
{
  Serial.begin(9600);
}
 
void loop(){
  char myKey = myKeypad.getKey();
 
  if (myKey != NULL)
  {
    Serial.print("Key pressed :-  ");
    Serial.println(myKey);
  }
}