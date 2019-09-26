/*
  DroneBeuys Smoke Breath Rev B
  For use with a fog machine with a simple on/off trigger
*/

void setup() {
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  delay(25*1000);  //initial pause
  digitalWrite(0, HIGH);  //activate relay for smoke machine
  digitalWrite(1, HIGH);  //activate led indicator eyes
  delay(5000);            //pause while smoke is coming out
  digitalWrite(0, LOW);   //turn off smoke machine
  digitalWrite(1, LOW);   //turn off eyes
}
