void wireSettings()
{
  pinMode(wire1Pin, INPUT);
  pinMode(wire2Pin, INPUT);
  pinMode(wire3Pin, INPUT);
  pinMode(wire4Pin, INPUT);
  digitalWrite(wire1Pin, HIGH); //preset these pins to internal pull-HIGH
  digitalWrite(wire2Pin, HIGH);
  digitalWrite(wire3Pin, HIGH);
  digitalWrite(wire4Pin, HIGH);
  assignFunctions();
}

void wireFuctions(int func) //input different number to trigger different behaviour
{
  switch (func)
  {
    case 0:
      remainingTime = 0; //trigger the bomb immediately
      tickTockCount = 0;
      break;
    case 1:
      currentTimeRatio = 0; //stop the timer
      myDFPlayer.playMp3Folder(3); //play the celebrate sound!!
      break;
    case 2:
      remainingTime = remainingTime + 10; //add extra 10 secs for timer
      break;
    case 3:
      currentTimeRatio = currentTimeRatio / 2; //count down in half speed
      break;
    case 4:
      currentTimeRatio = currentTimeRatio * 2; //count down in twice the normal speed
      break;
    case 5:
      remainingTime = 5; //change the remaining time to 5 secs
      break;
    case 6:
      break;
    default:
      break;
  }
}

void checkWire()
{
  if (digitalRead(wire1Pin) && !wire1Break)
  {
    wireFuctions(wire1Function);
    wire1Break = true;
  }
  if (digitalRead(wire2Pin) && !wire2Break)
  {
    wireFuctions(wire2Function);
    wire2Break = true;
  }
  if (digitalRead(wire3Pin) && !wire3Break)
  {
    wireFuctions(wire3Function);
    wire3Break = true;
  }
  if (digitalRead(wire4Pin) && !wire4Break)
  {
    wireFuctions(wire4Function);
    wire4Break = true;
  }
}

void assignFunctions()
{
  randomSeed(analogRead(5) + analogRead(4) + analogRead(2) + analogRead(3)); //get a random seed from A2-5
  if (!digitalRead(wire1Pin)) //if wires are initially connected, assign a random function
    wire1Function = 5;
  else wire1Break = true;
  if (!digitalRead(wire2Pin))
    wire2Function = 1;
  else
    wire2Break = true;
  if (!digitalRead(wire3Pin))
    wire3Function = 2;
  else
    wire1Break = true;
  if (!digitalRead(wire4Pin))
    wire4Function = 3;
  else wire4Break = true;
  Serial.println("Wire functions assigned, they are: " + (String)wire1Function + "," + (String)wire2Function + "," + (String)wire3Function + "," + (String)wire4Function);
}
