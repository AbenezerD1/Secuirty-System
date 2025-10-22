#include  <Servo.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "Auth.h"
#include "pitches.h"
#include "speaker.h"
#include "reed_switch.h"


Auth auth("633cb6fd", "1111", "453cb6fd");
Servo servo;

void setup(){
  auth.init();
  setupLCD();
  servo.attach(SERVO_PIN);
  servo.write(180);
  setupSpeaker();
  setupReedSwitch();
  LCDidle();
  Serial.begin(9600);
  //auth.startAlarm();
}

void loop(){
  bool isAuth = auth.isAuthorized();
  if(isAuth){
    LCDUpdateStatus(false);
    servo.write(0);
    playEnterSound();
    delay(3000);
    while(!isDoorClosed()){
      //Serial.println("Door is open!");
    }
    servo.write(180);
    LCDUpdateStatus(true);
  }
  else if(!isAuth && auth.getScan() != "" && auth.getScan() != auth.getAdminKey())
  {
    if(auth.getScan() == auth.getAdminKey()) {
      auth.clearScan();
    }
    playWrongSound();
  }
  delay(50);
  if(!isDoorClosed() && auth.getAlarmMode() && !isAuth){
    auth.startAlarm();
    auth.setAlarmMode(false);
  }
}