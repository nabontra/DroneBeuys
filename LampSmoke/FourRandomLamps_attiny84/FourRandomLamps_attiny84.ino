//this sketch created for use with the ATTINY84

const int CHANNELS = 4;

const int LED_PINS[CHANNELS] = {5, 6, 7, 8};
const int MIN_BRIGHTNESS[CHANNELS] = {25, 25, 25, 25};
const int MAX_BRIGHTNESS[CHANNELS] = {225, 225, 225, 225};

int CurrentBrightness[CHANNELS] =  {175, 60, 120, 100};
int FadeAmount[CHANNELS] = {5, 5, 5, 5};

// the setup routine runs once when you press reset:
void setup() {
  randomSeed(A0);
  for (int i = 0; i < CHANNELS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    FadeAmount[i] = (random(3,20));
  }
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i < CHANNELS; i++) {
    analogWrite(LED_PINS[i], CurrentBrightness[i]);

    CurrentBrightness[i] += FadeAmount[i];

    // reverse the direction of the fading at the ends of the fade:
    if (CurrentBrightness[i] <= MIN_BRIGHTNESS[i] ||
        CurrentBrightness[i] >= MAX_BRIGHTNESS[i]) {
      FadeAmount[i] = -FadeAmount[i];
      
    }
  }

  // wait for 90 milliseconds to see the dimming effect
  delay(90);
  
}
