    
    int ssrPin = 7;                // choose the pin for the solid state relay
    int pirPin = A0;               // choose the input pin (for PIR sensor) 1k pulldown resistor to gnd
    int val = 0;                    // variable for reading the pin status
    int timeon;
     
    void setup() {
      pinMode(ssrPin, OUTPUT);      // declare ssr as output
      pinMode(pirPin, INPUT);     // declare sensor as input
     digitalWrite(ssrPin, LOW);
     randomSeed(analogRead(A1));
      Serial.begin(9600);
    }
     
    void loop(){
      val = analogRead(pirPin);  // read input value
      Serial.println(val);
      if (val >= 500) {            // check if the input is HIGH
        timeon = int(random(30,300));
        digitalWrite(ssrPin, HIGH);   // turn the ssr on (HIGH is the voltage level)
        delay(timeon*1000);              // wait for a second
          timeon = int(random(30,300));
          digitalWrite(ssrPin, LOW);    // turn the ssr off by making the voltage LOW
          delay(timeon*1000);              // wait for a second
      }else {
          digitalWrite(ssrPin, LOW);
          
        }
       
      delay(50);
        }
