void segmentSetup()
{
  display.setBrightness(0x0f);
  segmentShow(0,0,1);
}


void segmentShow(int number, int dotPost, int showZero)
{
  if (number <= 9999 && number >= 0)
  {
    display.showNumberDecEx(number, (0x80 >> dotPost+1),showZero);
  }
}
