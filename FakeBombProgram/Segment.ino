void segmentSetup()
{
  display.setBrightness(0x0f);
  segmentShow(0);
}

void segmentShow(int number)
{
  if (number <= 99)
    display.showNumberDec(number, 0);
}

void segmentShow(int number, int dotPost, int showZero)
{
  if (number <= 99)
  {
    display.showNumberDecEx(number, (0x80 >> dotPost+1),showZero);
  }
}
