#ifndef   RFID_H_
#define   RFID_H_

#include <SPI.h>
#include <MFRC522.h>
#include "pin_def.h"

MFRC522 rfid(RFID_SS, RFID_RST);

void setupRFID() {
  SPI.begin();
  rfid.PCD_Init();
}

void readRFID(){
  if(rfid.PICC_IsNewCardPresent()){
    if(rfid.PICC_ReadCardSerial()){
      MFRC522::PICC_Type piccTypes = rfid.PICC_GetType(rfid.uid.sak);

      Serial.println("UID:");
      for(int i =0; i < rfid.uid.size; i++){
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0":" ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
}

String readRFIDtoString(){
  String ID = "";
  if(rfid.PICC_IsNewCardPresent()){
    if(rfid.PICC_ReadCardSerial()){
      MFRC522::PICC_Type piccTypes = rfid.PICC_GetType(rfid.uid.sak);

      for(int i =0; i < rfid.uid.size; i++){
        //ID += String((rfid.uid.uidByte[i] < 0x10 ? "0":" "));
        ID += String(rfid.uid.uidByte[i], HEX);
      }
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
  return ID;
}

#endif