void timerSetup()
{
  Timer1.initialize(10000);
  Timer1.attachInterrupt(tickTock); // udpate timer every 0.01 seconds
}

void tickTock(void)
{
  updateTimer(currentTimeRatio);
}

void updateTimer(float timeRatio)
{
  tickTockCount -= timeRatio * 1;
  if (tickTockCount <= 0)
  {
    remainingTime--;
    segmentShow(remainingTime, ledState, 1);
    if (remainingTime > 0)
      myDFPlayer.playMp3Folder(1);
    else
    {
      myDFPlayer.playMp3Folder(2);
      currentTimeRatio = 0;
    }
    tickTockCount = 100;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }
}
