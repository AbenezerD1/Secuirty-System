#ifndef KEYPAD_H
#define KEYPAD_H
#include "pin_def.h"
#include "LCD.h"

//function declaration for scope
void clearPass();

// Keypad layout
const char keypad[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
static char password[5]; // 4 chars + null terminator
static int count = 0;

void setupKeypad(){
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

// Scans the keypad for a pressed key
char scanKeypad() {
  for (uint8_t row = 0; row < 4; row++) {
    for (uint8_t r = 0; r < 4; r++) {
      pinMode(rowPins[r], INPUT);
      digitalWrite(rowPins[r], HIGH);
    }
    pinMode(rowPins[row], OUTPUT);
    digitalWrite(rowPins[row], LOW);
    delayMicroseconds(5);

    for (uint8_t col = 0; col < 4; col++) {
      if (digitalRead(colPins[col]) == LOW) {
        delay(10); // debounce
        return keypad[row][col];
      }
    }
  }
  return 0;
}

// Reads a 4-digit passcode from the keypad
String getPass() {
  if (count < 4) {
    char key = scanKeypad();
    if (key) {
      password[count++] = key;
      LCDUpdateStatusPass(count);

      // wait until key is released
      while (scanKeypad() == key) {
        delay(1);
      }
    }
  } else {
    clearPass();
  }

  password[4] = '\0';
  return String(password);
}

String getNewPass() {
  while (count < 4) {
    char key = scanKeypad();
    if (key) {
      password[count++] = key;
      LCDUpdateStatusPass(count);

      // wait until key is released
      while (scanKeypad() == key) {
        delay(1);
      }
    }
  }

  password[4] = '\0';
  return String(password);
}

void clearPass() {
  for(int i = 0; i < count; i++){
    password[i] = '\0';
  }
  count = 0;

  //return to idle
  LCDidle();
}

#endif
