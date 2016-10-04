// board: atmega1280
#include <MIDI.h>

const int lightThreshold = 900; //define what constitutes darkness

class Loop {
  
  public:

    int pin;
    int midiNote;
    boolean playing;

    Loop(int pinNumber, int midiNoteNumber){
      playing = 0; 
      pin = pinNumber;
      midiNote = midiNoteNumber;
    }
    void watch(){
      int val = analogRead(pin);
      if(val < lightThreshold) {
        start();
      } else {
        stop();
      }
    }

  private:

    void start(){
      if(playing == 0) {
        MIDI.sendNoteOn(midiNote,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
        playing = 1;
      }
    }
    void stop(){
      if(playing == 1) {
        MIDI.sendNoteOff(midiNote,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
        playing = 0;
      }
    }
};

Loop kick(15, 50);
Loop bongos(14, 62); // loopName(pinNumber, MidiNote)
Loop bassline(13, 55);
Loop vox(12, 48);
Loop keys(11, 48);
Loop percussion(10, 48);

void setup()
{
  //Serial.begin(9600);  //Begin serial communication (uncomment for debugging)
  MIDI.begin(4);            	// Launch MIDI with default options
}

void loop()
{
  kick.watch();
  bongos.watch();
  bassline.watch();
  vox.watch();
  keys.watch();
  percussion.watch();
  delay(500); //simulate 120bpm for diy quantization
}
