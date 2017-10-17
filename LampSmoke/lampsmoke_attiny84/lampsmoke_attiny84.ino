#define NR_OF_LIGHTS 3
int pins[NR_OF_LIGHTS] = {6, 7, 8};

int values[NR_OF_LIGHTS];
int steps[NR_OF_LIGHTS];

#define NR_OF_FADESTEPS 4
int fadesteps[NR_OF_FADESTEPS] = { 192, 128, 64, 0 };
int fade_delay = 300; // millisec
int fade_cycles = 1000;

int smokePin = 9;
int smokeState = LOW;
long previousMillis = 0; 
long OnTime = 5000;
long OffTime = 60*1000;  

void setup() {
 randomSeed(analogRead(0));
 pinMode(smokePin,OUTPUT);
 for (int i = 0; i < NR_OF_LIGHTS; i++) {
   values[i] = (int)random(230) + 13; // start values between 'max min' and 'min max'
   steps[i] = (int)random(4) + 1; // steps between 1 and 4
 }
}

void loop() {
 unsigned long currentMillis = millis();

  if((smokeState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    smokeState = LOW;  // Turn it off
    OffTime = random((60*1000),(30*60*1000));
    
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(smokePin, smokeState);  // Update the actual LED
  }
  else if ((smokeState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    smokeState = HIGH;  // turn it on
    OnTime = random(5000,10000);
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(smokePin, smokeState);   // Update the actual LED
  }
    
 for (int j = 0; j < fade_cycles; j++) {
   for (int i = 0; i < NR_OF_LIGHTS; i++) {
     fadingLight(i);  
   }
   delay(fade_delay);
 }
}

void fadingLight(int i) {
 
 int minvalue = (NR_OF_FADESTEPS * abs(steps[i])) + 1;
 int maxvalue = 255 - minvalue;

 int fs = NR_OF_FADESTEPS;
 for (int j = 0; fs > 0; fs--, j++) {
   if (values[i] > fadesteps[j]) {
       break;
   }
 }
 values[i] += fs * steps[i];
 
 if (values[i] > maxvalue  ||  values[i] < minvalue) {
     steps[i] *= -1;
 }
 
 analogWrite(pins[i], values[i]);
}
