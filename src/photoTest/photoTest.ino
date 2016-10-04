// board: atmega328
#include <MIDI.h>

int lightThreshold = 900; //define what constitutes darkness
int kick = 5;  //define a pin for Photo resistor
int bongo = 4;  //define a pin for Photo resistor
boolean kickPlaying = 0; // begin without music
boolean bongoPlaying = 0; // begin without music

void setup()
{
  //Serial.begin(9600);  //Begin serial communcation
  MIDI.begin(4);            	// Launch MIDI with default options
  //set all notes to off
}

void loop()
{
  int kickVal = analogRead(kick);
  int bongoVal = analogRead(bongo);
  if((kickVal < lightThreshold)) {
    playKick();
  } else {
    stopKick();
  }
  if((bongoVal < lightThreshold)) {
    playBongo();
  } else {
    stopBongo();
  }
  delay(500); //simulate 120bpm?
}

void playKick() {
  if(kickPlaying == 0) {
    MIDI.sendNoteOn(48,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    kickPlaying = 1;
  }
}

void stopKick() {
  if(kickPlaying == 1) {
    MIDI.sendNoteOff(48,0,1);   // Stop the note
    kickPlaying = 0;
  }
}

void playBongo() {
  if(bongoPlaying == 0) {
    MIDI.sendNoteOn(55,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    bongoPlaying = 1;
  }
}

void stopBongo() {
  if(bongoPlaying == 1) {
    MIDI.sendNoteOff(55,0,1);   // Stop the note
    bongoPlaying = 0;
  }
}

