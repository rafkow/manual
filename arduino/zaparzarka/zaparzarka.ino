#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <String.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define POMPKA 11
#define BUTTON 5
#define BUTTON2 6

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  sensors.begin();
  pinMode(8,INPUT);
  pinMode(POMPKA, OUTPUT);
  digitalWrite(POMPKA, LOW);
  digitalWrite(9,HIGH);
  pinMode(BUTTON, INPUT);
  pinMode(BUTTON2, INPUT);
  
  lcd.setCursor(0,1);
  lcd.print("T");
  lcd.print("e");
  lcd.print("m");
  lcd.print("p");
  lcd.print(":");
  lcd.print(" ");
}

void digital(int x)
{
  int i = 0;
  int j;
  if(x > 9) i = 1;
  if(x > 99) i = 2;
  if(x > 999) i = 3;
  if(x > 9999) i = 4;
  if(x > 99999) i = 5;
  for(j = i; j >= 0 ; j--){
    int q = pow(10, j);
    int b = x/q;
    lcd.print(b);
    x = x-(b*q);
  }  
}

void loop(){
  int z =220;
  if(digitalRead(BUTTON) == LOW){
    lcd.print("S");
    while(z>0){
      digitalWrite(POMPKA, HIGH);
      if(digitalRead(8) == LOW){
        while(digitalRead(8) == LOW);
        z--;
        lcd.setCursor(0,0);
        for(int i = 0; i<5; i++)
          lcd.print(" ");
        lcd.setCursor(0,0);
        digital(z);
      }
    }
  }
  while(1){
    delay(250);
  //if(digitalRead(BUTTON2) == LOW){
    sensors.requestTemperatures();
    int x = sensors.getTempCByIndex(0);
    lcd.setCursor(6,1);
    for(int i = 0; i<5; i++)
      lcd.print(" ");
    lcd.setCursor(6,1);
    digital(x);
  }
  digitalWrite(POMPKA, LOW);
}


