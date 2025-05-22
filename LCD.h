#ifndef LCD_H_
#define LCD_H_

#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);

void LCDUpdateStatus(bool isLocked);

void setupLCD(){
  lcd.init();
  lcd.backlight();
}

void LCDidle(){
  lcd.setCursor(0,0);
  lcd.print("Scan a your tag");
  lcd.setCursor(0,1);
  lcd.print("or enter your pin");
  LCDUpdateStatus(true);
}

void LCDUpdateStatus(bool isLocked){
  if(isLocked){
    lcd.setCursor(0,3);
    lcd.printstr("        ");
    lcd.setCursor(0,3);
    lcd.print("Locked");
  }
  else
  { 
    lcd.setCursor(0,3);
    lcd.printstr("        ");
    lcd.setCursor(0,3);
    lcd.printstr("Unlocked");
  }
}

#endif