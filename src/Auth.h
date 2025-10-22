#ifndef AUTH_H_
#define AUTH_H_

#include "RFID.h"
#include "Keypad.h"
#include "speaker.h"
#include "Servo.h"

class Auth{
  public:
  Auth(String validTagID, String validPin, String validAdminPin){
    key = validTagID;
    pinCode = validPin;
    adminPin = validAdminPin;
    adminKey = "-1";
  }
  void init(){
    setupRFID();
    setupKeypad();
  }
  bool isAuthorized(){
    scannedRFIDTag = readRFIDtoString();
    String pin = getPass();

    //enter admin mode
    if(pin == adminPin || scannedRFIDTag == adminKey) {
      clearPass();
      adminPage();
    }

    //Serial.println(pin);
    return scannedRFIDTag == key || pin == pinCode;
  }

  void adminPage() {
    LCDUpdateAdminMode();
    String pin = "";
    while(pin != "*") {
      pin = getPass();
      if(pin == "1") {
        clearPass();
        LCDChangePass();
        while(true) {
          pin = getNewPass();
          pinCode = pin;
          clearPass();
          LCDidle();
          return;
        }
      } else if(pin == "2") {
        clearPass();
        LCDChangeRFID();
        while(true) {
          scannedRFIDTag = readRFIDtoString();
          if(scannedRFIDTag != "") {
            key = scannedRFIDTag;
            LCDidle();
            delay(1000);
            return;
          }
        }
      } else if(pin == "3") {
        clearPass();
        LCDAddAdminRFID();
        while(true) {
          scannedRFIDTag = readRFIDtoString();
          if(scannedRFIDTag != "") {
            adminKey = scannedRFIDTag;
            LCDidle();
            delay(1000);
            return;
          }
        }
      } else if(pin == "4") {
        alarmMode = true;
        LCDidle();
        delay(1000);
        return;
      }
    }
    clearPass();
    LCDidle();
  }
  bool getAlarmMode(){
    return alarmMode;
  }

  String getScan(){
    return scannedRFIDTag;
  }

  void clearScan() {
    scannedRFIDTag = "";
  }

  String getAdminKey() {
    return adminKey;
  }

  void startAlarm(){
    while(!isAuthorized()) {
      playAlarm();
    }
    playEnterSound();
  }

  void setAlarmMode(bool mode){
    alarmMode = mode;
  }
  private:
  String scannedRFIDTag = "";
  String key = "";
  String pinCode = "";
  String adminPin = "";
  String adminKey = "";
  bool alarmMode = false;
};
#endif