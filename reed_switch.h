#ifndef REED_SWITCH_H_
#define REED_SWITCH_H_
#include "pin_def.h"
static bool doorClosed = false;

void setupReedSwitch(){
  pinMode(REED_SWITCH_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}
bool isDoorClosed(){
  bool switchState = digitalRead(REED_SWITCH_PIN);
  if(switchState == HIGH){
    Serial.println("door open!");
    doorClosed = false;
    digitalWrite(LED_PIN, HIGH);
  }else if(switchState == LOW){
    Serial.println("door closed!");
    doorClosed = true;
    digitalWrite(LED_PIN, LOW);
  }
  return doorClosed;
}
#endif