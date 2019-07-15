void playerSettings()
{
  Serial1.begin(9600);
  Serial.begin(115200);
   
  if (!myDFPlayer.begin(Serial1)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
}
