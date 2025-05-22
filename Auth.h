#ifndef AUTH_H_
#define AUTH_H_

#include "RFID.h"
#include "Keypad.h"

class Auth{
  public:
  Auth(String validTagID, String validPin);
  void init();
  bool isAuthorized();

  private:
  String key = "";
  String pinCode = "";
};
#endif