# MIDI_Macro_Launcher

## Abandon-in-place
This project has been replaced. The new version us based on CircuitPython so updates to the button layouts no-longer require a code change. The new project is here: https://github.com/bapril/TrellisM4_MIDI_Keypad


## Overview
This project started based on John Park's Launch Deck example (https://blog.adafruit.com/2018/12/01/new-guide-john-parks-launch-deck-trellis-m4-adafruit-johnedgarpark-adafruit/). I found tracking multiple layers of keystrokes to be a pain and likely to conflict with existing keyboard macros so i sought another approach. As I don't use midi in my day to day work this works for me.

This code is a take on John Park's Trellis.M4 expressive MIDI controller (https://learn.adafruit.com/trellis-m4-midi-keypad-and-tilt-controller/overview) I've removed the accelerometer code and added pixel lighting and banks of buttons.

## Acknowledgements
 * Adafruit created the Trellis M4 and most of the libraries.
 * John Park created the launch deck and expressive MIDI controller examples.

## Use
The Trellis starts displaying the 31 buttons found on Page 0. The default color of Page 0 is Red (0xFF0000) which is the color displayed on the 32nd button (bottom right). The color for each page is configurable. In this mode the first 31 keys will each send the configured MIDI noteOn when pressed and a noteOff  when released. The 32nd button is the bank switch button. Pressing bank-switch will turn off the light of the 32nd key and replace the current button set with a bank selector. Each button represents a bank and displays it's color. Pressing a lit button in bank-switch mode will set the Trellis to that mode and redraw the keys.

I'm using Keyboard Mastero(https://www.keyboardmaestro.com/main/) which is happy to triger macros by MIDI commands.

The keypad will emit the MIDI notes even if a color isn't assigned to a given key. It should work for any OS that understands USB MIDI input. Any key not confgured will display as off.

## Features
 * Page selector - The button in the bottom right is always the page selector. Pressing it will switch the MIDI_Macro_Launcher into page select mode. Page select allows the user to change the page of buttons displayed at any time.
 * Screensaver - By setting the value in SCREENSAVER_MILLIS you will set the number of cycles where no button is pressed before the screensaver will kick in. Setting SCREENSAVER_MILLIS to 300000 will result in a screensaver timer of 5 minutes. When in screensaver mode, the first button pressed (and released) will wake it up, The press will not trigger a note. Setting SCREENSAVER_MILLIS = 0 will disable this mode.

## Configuration
Configuration lives in the midi_launcher.h file. There are 2 main areas  to configure.

 * The Channel colors - These are populated in the banksel array. You may confgure up to array index 31.
 * Buttons are arranged in the button_set array. The structure is as follows:

 button_set[page][key] = {active,channel,note,color} where:
 * page is a byte between 0 and 31 indicating which page the button lives on.
 * key is a byte betewwn 0 and 31 indicating which button position this item occupies.
 * active is a bool indiciating if the button should be active. (true for active)
 * channel is the midi channel that the button should send its note on. (byte 0-16)
 * note is the MIDI note that should be sent (byte 0-127)
 * color is either a macro color e.g. C_RED or an RGB value {0,255,0} = green.

### Parameters
 * START_PAGE - Default 0 - The id of the page that will be selected with the MIDI_Macro_Launcher boots.
 * SCREENSAVER_MILLIS - Default 300000 - Number of miliseconds without a button press before the screensaver kicks in.
 * BRIGHTNESS - Default 70 - The brightness level of the buttons.
