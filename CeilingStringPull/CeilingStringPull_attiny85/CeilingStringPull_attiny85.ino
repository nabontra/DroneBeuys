#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, 1, 0);
int motionpin = 2;
int motionstatus = 0;

long pos = 90000; //approx 6.5 feet 90000

void setup()
{ 
  stepper.setMaxSpeed(75000);
  stepper.setAcceleration(10000);
  //pinMode(motionpin, INPUT);
  randomSeed(analogRead(A0)); 
}

void loop()
{
  //motionstatus = analogRead(motionpin);
  if (stepper.distanceToGo() == 0)
  { int delaytime = int(random(1000,8000));
    delay(delaytime); //hold at the top
    int accelx = int(random(50,4000));
    stepper.setAcceleration(accelx);
    int maxspeedx = int(random(8000,25000));
    stepper.setMaxSpeed(maxspeedx);
    pos = -pos;
    stepper.moveTo(pos);
  }
  stepper.run();
}
