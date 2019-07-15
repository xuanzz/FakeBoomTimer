//Segment settings
#include <TM1637Display.h>
#define CLK 14
#define DIO 15
TM1637Display display(CLK, DIO);
//Timer settings
#include <TimerOne.h>
int ledState = LOW;
volatile int remainingTime = 9991; //remaining time before the explosion happened
volatile int tickTockCount = 100;
volatile int currentTimeRatio = 0; //the time ratio of the time, <1 means slower than normal, >1 means faster. e.g. currentTimeRatio=2 means time counting in 2x speed
volatile unsigned long blinkCount = 0; // use volatile for shared variables
//MP3 Player settings
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;


void setup()
{
  playerSettings();
  timerSetup();
  segmentSetup();
}

void loop()
{

}
