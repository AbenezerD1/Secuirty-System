#include "Auth.h"

Auth::Auth(String validTagID, String validPin){
  key = validTagID;
  pinCode = validPin;
}

void Auth::init(){
  setupRFID();
  setupKeypad();
}

bool Auth::isAuthorized(){
  String scannedRFIDTag = readRFIDtoString();
  String password = getPass();

  if(scannedRFIDTag != key || password != pinCode){
    return false;
  }
  return true;
}