#ifndef   SPEAKER_H_
#define   SPEAKER_H_
#include "pitches.h"
#include "pin_def.h"
#include <avr/interrupt.h>

uint8_t enterSound = NOTE_00;
uint8_t wrongSound = NOTE_DS8;

void initTimer0() {
  TCCR2A = (1 << WGM01) | (1 << COM2A0); // CTC mode, toggle OC2A
  TCCR2B = (1 << CS01)  | (1 << CS22);     // Prescaler 64
}

void setupSpeaker(){
  initTimer0();
}

void startTone(uint8_t note) {
  OCR2A = note;
  SPEAKER_DDR |= (1 << SPEAKER); // Enable speaker output
}

void stopTone() {
  SPEAKER_DDR &= ~(1 << SPEAKER); // Disable speaker output
}

void playTone(int note, uint16_t duration){
  startTone(note);
  _delay_ms(duration);
  stopTone();
}

void playEnterSound(){
  playTone(enterSound, 500);
}

void playWrongSound(){
  playTone(wrongSound, 500);
}

void playAlarm(){
  playTone(wrongSound, 500);
}
#endif