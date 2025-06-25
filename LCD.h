#ifndef LCD_H_
#define LCD_H_

#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);

void LCDUpdateStatus(bool isLocked);
void clearLCD();

void setupLCD(){
  lcd.init();
  lcd.backlight();
}

void LCDidle(){
  clearLCD();
  lcd.setCursor(0,0);
  lcd.print("Scan a your tag");
  lcd.setCursor(0,1);
  lcd.print("or enter your pin");
  LCDUpdateStatus(true);
}

void LCDUpdateStatus(bool isLocked){
  if(isLocked){
    lcd.setCursor(0,3);
    lcd.printstr("            ");
    lcd.setCursor(0,3);
    lcd.print("Locked");
  }
  else
  { 
    lcd.setCursor(0,3);
    lcd.printstr("            ");
    lcd.setCursor(0,3);
    lcd.printstr("Unlocked");
  }
}

void LCDUpdateStatusPass(int count) {
  lcd.setCursor(0,3);
  char display[5];
  for(int i = 0; i < 4; i++) {
    if(i < count) {
      display[i] = '*';
    } else {
      display[i] = '-';
    }
  }
  display[4] = '\0';
  lcd.printstr("        ");
  lcd.setCursor(0,3);
  lcd.printstr(display);
}

void LCDUpdateAdminMode() {
  clearLCD();
  lcd.setCursor(0,0);
  lcd.printstr("Admin Mode");
  lcd.setCursor(0,1);
  lcd.printstr("Please select option");
  lcd.setCursor(0,2);
  lcd.printstr("mode (1-9)");
}

void LCDChangePass() {
  clearLCD();
  lcd.setCursor(0,0);
  lcd.printstr("Please enter new");
  lcd.setCursor(0,1);
  lcd.printstr("password:");
}

void LCDChangeRFID() {
  clearLCD();
  lcd.setCursor(0,0);
  lcd.printstr("Please scan new");
  lcd.setCursor(0,1);
  lcd.printstr("RFID badge:");
}

void LCDAddAdminRFID() {
  clearLCD();
  lcd.setCursor(0,0);
  lcd.printstr("Please scan new");
  lcd.setCursor(0,1);
  lcd.printstr("Admin RFID badge:");
}

void clearLCD() {
  for(int i = 0; i < 4; i++) {
    lcd.setCursor(0,i);
    lcd.printstr("                       ");
  }
}

#endif