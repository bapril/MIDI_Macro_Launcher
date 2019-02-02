// Tressli M4 MIDI Keypad for macro triggering
// 31 notes color-coded and 1 key to select a new bank. 

// was: 
// Trellis M4 MIDI Keypad CC
// sends 32 notes, pitch bend & a CC from accelerometer tilt over USB MIDI
#define BANKSEL 1
#define MACRO 0

#define LED_OFF 0x00

#define BANKSEL_KEY 31

#include <Adafruit_NeoTrellisM4.h>

#include "midi_launcher.h"

Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();

void setup(){
  trellis.begin();
  trellis.setBrightness(70);

  // USB MIDI messages sent over the micro B USB port
  trellis.enableUSBMIDI(true);
  trellis.setUSBMIDIchannel(channel);

  init_pages();
  init_banksel();

  color_keys(channel,first_note);
  trellis.tick();
}

void loop() {
  // put your main code here, to run repeatedly:
  trellis.tick();

  while (trellis.available()){
    keypadEvent e = trellis.read();
    int key = e.bit.KEY;
    if (key == 31 && e.bit.EVENT == KEY_JUST_PRESSED){ //Select Bank page. 
        render_banksel();
        mode = BANKSEL;
    } else if (key == 31 && e.bit.EVENT == KEY_JUST_RELEASED){ 
    } else if (mode == BANKSEL){
        if (key < 8){
          channel = key;
          trellis.setUSBMIDIchannel(channel);
        }
        color_keys(channel,first_note);
        mode = MACRO;
    } else {
      if (e.bit.EVENT == KEY_JUST_PRESSED) {
        trellis.setPixelColor(key, 0xFFFFFF);
        trellis.noteOn(first_note+key, 64);
      } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
        trellis.setPixelColor(key, gen_color_ptr(&colors[channel][first_note + key]));
        trellis.noteOff(first_note+key, 64);
      }
    }
  }
  trellis.sendMIDI(); // send any pending MIDI messages

  delay(10);
}

void color_keys(int ch, int key_in){
  rgbcolor col;
  for (int i = 0; i < 30; i++){
    if(colors[ch][key_in + i].r or colors[ch][key_in + i].g or colors[ch][key_in + i].b){
      trellis.setPixelColor(key_in + i, gen_color_ptr(&colors[ch][key_in + i]));
    } else {
      trellis.setPixelColor(key_in + i, LED_OFF);
    }
  }
  trellis.setPixelColor(BANKSEL_KEY, gen_color_ptr(&banksel[channel]));
}

void render_banksel(){
  for (int j = 0; j < banksize; j++){
    trellis.setPixelColor(j,gen_color_ptr(&banksel[j]));
  }
  for (int i = banksize; i < 31; i++){
    trellis.setPixelColor(i,LED_OFF);
  }
  trellis.setPixelColor(BANKSEL_KEY,LED_OFF);
}

uint32_t gen_color_ptr(rgbcolor *color) {
  return ((long)color->r << 16L) + ((long)color->g << 8L) + ((long)color->b);
}


