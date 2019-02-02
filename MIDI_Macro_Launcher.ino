// Tressli M4 MIDI Keypad for macro triggering
// 31 notes color-coded and 1 key to select a new bank. 

// was: 
// Trellis M4 MIDI Keypad CC
// sends 32 notes, pitch bend & a CC from accelerometer tilt over USB MIDI
#define BANKSEL 1
#define MACRO 0

#define BANKSEL_KEY 31
#define START_PAGE 0

#include <Adafruit_NeoTrellisM4.h>

#include "midi_launcher.h"

Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();

void setup(){
  trellis.begin();
  trellis.setBrightness(70);

  // USB MIDI messages sent over the micro B USB port
  trellis.enableUSBMIDI(true);

  init_pages();
  init_banksel();

  page = START_PAGE;
  color_keys(page);
  trellis.tick();
}

void loop() {
  // put your main code here, to run repeatedly:
  trellis.tick();

  while (trellis.available()){
    keypadEvent e = trellis.read();
    int key = e.bit.KEY;
    str_btn *active_key;
    if (key == 31){
      if (e.bit.EVENT == KEY_JUST_PRESSED){ //Select page list.
        render_banksel();
        mode = BANKSEL;
      }
    } else if (mode == BANKSEL){
      if (key < (sizeof(banksel)/sizeof(str_rgbcolor))) page=key;
      color_keys(page);
      mode = MACRO;
    } else {
      active_key = &button_set[page][key];
      if(active_key->active){
        if (e.bit.EVENT == KEY_JUST_PRESSED) {
          trellis.setPixelColor(key, 0xFFFFFF);
          trellis.setUSBMIDIchannel(active_key->channel);
          trellis.noteOn(active_key->note, 64);
        } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
          trellis.setPixelColor(key, gen_color_ptr(&active_key->color));
          trellis.setUSBMIDIchannel(active_key->channel);
          trellis.noteOff(active_key->note, 64);
        }
      }
    }
  }
  trellis.sendMIDI(); // send any pending MIDI messages
  delay(10);
}

void color_keys(byte page){
  str_btn *active_key;
  for (int i = 0; i < 30; i++){
    active_key = &button_set[page][i];
    if(active_key->active){
      trellis.setPixelColor(i, gen_color_ptr(&active_key->color));
    } else {
      trellis.setPixelColor(i, gen_color(C_OFF));
    }
  }
  trellis.setPixelColor(BANKSEL_KEY, gen_color_ptr(&banksel[page]));
}

void render_banksel(){
  byte b_size = (sizeof(banksel)/sizeof(str_rgbcolor));
  for (int j = 0; j < b_size; j++){
    trellis.setPixelColor(j,gen_color_ptr(&banksel[j]));
  }
  for (int i = b_size; i < 31; i++){
    trellis.setPixelColor(i,gen_color(C_OFF));
  }
  trellis.setPixelColor(BANKSEL_KEY,gen_color(C_OFF));
}

uint32_t gen_color(str_rgbcolor color){
  return ((long)color.r << 16L) + ((long)color.g << 8L) + ((long)color.b);
}
uint32_t gen_color_ptr(str_rgbcolor *color) {
  return ((long)color->r << 16L) + ((long)color->g << 8L) + ((long)color->b);
}


