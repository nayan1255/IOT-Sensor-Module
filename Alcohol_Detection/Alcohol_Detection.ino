//Alcohol Detector based on MQ3
 /* Here are the list of I/O pins*/
 
int MQ3 = A0;
int threshold_val = 700; //Threshold value of MQ3 reading above which it should trigger
int value; // global int to store the analog reading from MQ3 (0 to 1023)
int led = D8;

void setup() 
{
  Serial.begin(9600);
  pinMode(MQ3, INPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{
  value = analogRead(MQ3); // reads the analog value from MQ3
  //Serial.println(value);

if (value > threshold_val)   //if alcohol is detected
{
  Serial.println("Alcohol Detected");
  Serial.println(value);
  digitalWrite(led, LOW); // turn LED OFF
  delay(1000);
}
else
{
  Serial.println("No Alcohol Detected");
  Serial.println(value);
  digitalWrite(led, HIGH); // turn LED OFF
  delay(1000);
}
}
