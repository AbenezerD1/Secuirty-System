#ifndef PIN_DEF_H_
#define PIN_DEF_H_
//pin definitions for the Arduino Mega

//RFID pins
#define RFID_SS       53
#define RFID_RST      A13  // TODO: inteferes with the RFID pin, need to change

//Keypad pins
const uint8_t rowPins[4] = {A15, A14, A13, A12};
const uint8_t colPins[4] = {A11, A10, A9, A8};

#endif