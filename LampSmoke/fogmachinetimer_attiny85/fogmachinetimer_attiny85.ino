int blinkPin = 7;

void setup()
{
  pinMode(blinkPin, OUTPUT);
}

void loop()
{
  int randtime = (int(random(30,45)));
  for (int x=0; x<randtime; x++){
    delay(1000);
  }
  digitalWrite(blinkPin, HIGH);
  delay(1500);
  digitalWrite(blinkPin, LOW);
}
