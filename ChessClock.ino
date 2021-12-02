
#include "LiquidCrystal_I2C.h"
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int BUTTON = 4;
int b = 5;
int w = 5;
int ws = 00;
int bs = 00;
char timeline[15];
char timeline2[15];
bool count;
int lastState;


void buttonCheck(int check)
{
  
    for(int i = 0; i < check; i++)
    {
      if(digitalRead(BUTTON) == HIGH)
      {
        count = Switch(count);
      }
      delay(1);
    }
    
}

bool Switch(bool a)
{
  if(a == true)
  {
    a = false;
  }
  else
  {
    a = true;
  }

  return a;
}



void setup() {
  // put your setup code here, to run once:
  //pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  lcd.init();
  lcd.backlight();
}



void loop() {
    
    
    lcd.setCursor(0,0);
    sprintf(timeline, "White:%0.2d:%0.2d", w, ws);
    lcd.print(timeline);
    lcd.setCursor(0,1);    
    sprintf(timeline2, "Black:%0.2d:%0.2d", b, bs);
    lcd.print(timeline2);
    
    if(count == true)
    {
      ws--;
    }
    else
    {
      bs--;
    }
    
    if(ws == -1)
    {
      w--;
      ws = 59;
    }
    else if(bs == -1)
    {
      b--;
      bs = 59; 
    }

    buttonCheck(2000);
    

}
