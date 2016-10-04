// board: atmega1280
#include <MIDI.h>

//const int lightThreshold = 900; //define what constitutes darkness

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
      int lightThreshold = analogRead(0);
      /*Serial.print("pin val:");        */
      /*Serial.println(val);             */
      /*Serial.print("light threshold:");*/
      /*Serial.println(lightThreshold);  */
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

//C Major
/*Loop loop4(4, 36); // loopName(pinNumber, MidiNote)*/
/*Loop loop5(5, 40);                                 */
/*Loop loop8(8, 43);                                 */
/*Loop loop9(9, 48);                                 */
/*Loop loop10(10, 52);                               */
/*Loop loop11(11, 55);                               */
/*Loop loop12(12, 60);                               */
/*Loop loop13(13, 64);                               */
/*Loop loop14(14, 67);                               */
/*Loop loop15(15, 72);                               */

//D Major
Loop loop4(4, 38);
Loop loop5(5, 42);
Loop loop8(8, 45);
Loop loop9(9, 50);
Loop loop10(10, 54);
Loop loop11(11, 57);
Loop loop12(12, 62);
Loop loop13(13, 66);
Loop loop14(14, 69); 
Loop loop15(15, 74);
void setup()
{
  //Serial.begin(9600);  //Begin serial communication (uncomment for debugging)
  MIDI.begin(4);            	// Launch MIDI with default options
}

void loop()
{
  loop4.watch();
  loop5.watch();
  loop8.watch();
  loop9.watch();
  loop10.watch();
  loop11.watch();
  loop12.watch();
  loop13.watch();
  loop14.watch();
  loop15.watch();
  delay(500); //simulate 120bpm for diy quantization
}
