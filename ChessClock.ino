#include "LiquidCrystal_I2C.h"
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int BUTTON = 4;
int blackMinutes = 5;
int whiteMinutes = 5;
int whiteSeconds = 0;
int blackSeconds = 0;
char timeline[15];
char timeline2[15];
bool count = true;
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

void endGame()
{
  lcd.clear();
  if(count == true)
  {
    lcd.print("Black Won");
  }
  else
  {
    lcd.print("White Won");
  }
  lcd.setCursor(0,1);
  lcd.print("Press Reset");
  exit(0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  
    lcd.setCursor(0,0);
    sprintf(timeline, "White:%0.2d:%0.2d", whiteMinutes, whiteSeconds);
    lcd.print(timeline);
    lcd.setCursor(0,1);    
    sprintf(timeline2, "Black:%0.2d:%0.2d", blackMinutes, blackSeconds);
    lcd.print(timeline2);
    
    if(count == true)
    {
      whiteSeconds--;
    }
    else
    {
      blackSeconds--;
    }
    
    if(whiteSeconds == -1)
    {
      if(whiteMinutes == 0)
      {
        endGame();
      }
      whiteMinutes--;
      whiteSeconds = 59;
    }
    else if(blackSeconds == -1)
    {
      if(blackMinutes == 0)
      {
        endGame();
      }
      blackMinutes--;
      blackSeconds = 59; 
    }
    buttonCheck(1000);
}
