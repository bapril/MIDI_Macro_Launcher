// Tressli M4 MIDI Keypad for macro triggering
// 31 notes color-coded and 1 key to select a new bank.

// was:
// Trellis M4 MIDI Keypad CC
// sends 32 notes, pitch bend & a CC from accelerometer tilt over USB MIDI

//Adjustable values
#define START_PAGE 0
#define SCREENSAVER_MILLIS 300000
#define BRIGHTNESS 70

//States
#define M_BANKSEL 1
#define M_MACRO 0
#define M_SCREENSAVER 2

//Fixed Values
#define BANKSEL_KEY 31

#include <Adafruit_NeoTrellisM4.h>
#include "midi_launcher.h"

long last_press = millis();
byte brightness = BRIGHTNESS;
byte page = 0;
int mode = M_MACRO;
int last_mode = M_MACRO;

Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();

void setup(){
  trellis.begin();
  trellis.setBrightness(brightness);

  // USB MIDI messages sent over the micro B USB port
  trellis.enableUSBMIDI(true);

  init_pages();
  init_banksel();

  page = START_PAGE;
  color_keys(page);
  trellis.tick();
}

void loop() {
  bool have_midi = false;
  // put your main code here, to run repeatedly:
  trellis.tick();
  while (trellis.available()){
    keypadEvent e = trellis.read();
    int key = e.bit.KEY;
    str_btn *active_key;
    if (e.bit.EVENT == KEY_JUST_PRESSED or e.bit.EVENT == KEY_JUST_RELEASED){
      last_press = millis();
    }
    if (mode == M_SCREENSAVER){
      if (e.bit.EVENT == KEY_JUST_RELEASED){ //Only react to a release, so we don't count the press.
        for(; brightness < BRIGHTNESS; brightness++){
          trellis.setBrightness(brightness);
          trellis.show();
        }
        mode = last_mode;
      }
    } else if (key == BANKSEL_KEY){
      if (e.bit.EVENT == KEY_JUST_PRESSED){ //Select page list.
        render_banksel();
        mode = M_BANKSEL;
      }
    } else if (mode == M_BANKSEL){
      if (key < (sizeof(banksel)/sizeof(str_rgbcolor))) page=key;
      color_keys(page);
      mode = M_MACRO;
    } else {
      active_key = &button_set[page][key];
      if(active_key->active){
        have_midi = true;
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
  if (SCREENSAVER_MILLIS > 0 & (millis() - last_press) > SCREENSAVER_MILLIS){
    if(mode != M_SCREENSAVER) last_mode = mode;
    mode = M_SCREENSAVER;
    if (brightness > 0){
      brightness--;
      trellis.setBrightness(brightness);
      trellis.show();
    }
  }
  if (have_midi) trellis.sendMIDI(); // send any pending MIDI messages
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


