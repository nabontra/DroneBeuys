int redPin = 10;
int greenPin = 9;
int bluePin = 6;
int randmin = 10;
int randmax = 150;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  randomSeed(analogRead(0));  
}

void loop()
{ int randselect = random(6);
  switch (randselect){
    case 0:
      setColor(255, 0, 0);  // red
      delay(random(randmin,randmax));
    break;
    case 1:
      setColor(0, 255, 0);  // green
      delay(random(randmin,randmax));
    break;
    case 2:
      setColor(0, 0, 255);  // blue
      delay(random(randmin,randmax));
    break;
    case 3:
      setColor(255, 255, 0);  // yellow
      delay(random(randmin,randmax));
    break;
    case 4:
      setColor(80, 0, 80);  // purple
      delay(random(randmin,randmax));
    break;
    case 5:
      setColor(0, 255, 255);  // aqua
      delay(random(randmin,randmax));
    break;
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
