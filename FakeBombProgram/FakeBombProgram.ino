//Segment settings
#include <TM1637Display.h>
#define CLK 14
#define DIO 15
TM1637Display display(CLK, DIO);
//Timer settings
#include <TimerOne.h>
int ledState = LOW;
volatile int remainingTime = 60; //remaining time before the explosion happened
volatile float tickTockCount = 100;
volatile float currentTimeRatio = 1; //the time ratio of the time, <1 means slower than normal, >1 means faster. e.g. currentTimeRatio=2 means time counting in 2x speed
volatile unsigned long blinkCount = 0; // use volatile for shared variables
//MP3 Player settings
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;
#include <SoftwareSerial.h>
SoftwareSerial softSerial(8, 9);
//Wire Settings
#define wire1Pin 10
#define wire2Pin 11
#define wire3Pin 12
#define wire4Pin 7
volatile bool wire1Break, wire2Break, wire3Break, wire4Break = false; //store the wire status
int wire1Function = -1; 
int wire2Function = -1; 
int wire3Function = -1; 
int wire4Function = -1; 
//store the random generated functions of the wires, -1 means no wire connected at the begining

void setup()
{
  softSerial.begin(9600);
  Serial.begin(115200);
  wireSettings();
  playerSettings();
  timerSetup();
  segmentSetup();
}

void loop()
{

}
