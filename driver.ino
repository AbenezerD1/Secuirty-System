#include "LCD.h"
#include "Auth.h"

Auth auth("633cb6fd", "123456");

void setup(){
  auth.init();
  setupLCD();

  LCDidle();
  Serial.begin(9600);
}

void loop(){
  if(auth.isAuthorized()){
    LCDUpdateStatus(false);
    _delay_ms(2000);
    LCDUpdateStatus(true);
  }
}