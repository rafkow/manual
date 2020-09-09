#include <Wire.h>

void setup(){
  Wire.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void DisplayOn(){
  Wire.beginTransmission(0x3E);
  Wire.write(0x84);
  Wire.write(0b11);
  Wire.endTransmission();
}

void DriveMode(){
  Wire.beginTransmission(0x3E);
  Wire.write(0x80);
  Wire.write(0b1);
  Wire.endTransmission();
}

void BlinkingMode(){
  Wire.beginTransmission(0x3E);
  Wire.write(0x88);
  Wire.write(0b0);
  Wire.endTransmission();
}

void FrameFrequency(){
  Wire.beginTransmission(0x3E);
  Wire.write(0x86);
  Wire.write(0b0);
  Wire.endTransmission();
}

void DisplaySegment(){
  for(int i = 0; i<51; i++){
     Wire.beginTransmission(0x3E);
     Wire.write(0x00);
     for(int j = 0; j<27; j++){
       Wire.write(random(8));
     }
     Wire.endTransmission();
     delay(500);
   } 
}

void loop(){
  DriveMode();
  BlinkingMode();
  DisplayOn();
  DisplaySegment();
  while(true);
}
