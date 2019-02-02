# MIDI_Macro_Launcher

## Overview

This project started based on  John Park's Launch Deck example (https://blog.adafruit.com/2018/12/01/new-guide-john-parks-launch-deck-trellis-m4-adafruit-johnedgarpark-adafruit/). I found tracking multiple layers of keystrokes to be a pain and likely to conflict with existing keyboard macros. So i sought another approach. As I don't use midi in my day to day work this works for me.

This code is a take on John Park's Trellis.M4 expressive MIDI controller (https://learn.adafruit.com/trellis-m4-midi-keypad-and-tilt-controller/overview) I've removed the accelerometer code and added pixel lighting and banks of buttons.

## Use

The Trellis starts displaying Channel 0 Note 0-31 or "Bank 1". The default color of Bank 1 is Red (0xFF0000) which is the color displayed on the 32nd button. In this mode the first 31 keys will each send a MIDI note when pressed and stop when released. The 32nd button is the bank switch button. Pressing bank-switch will turn off the light of the 32nd key and replace the current button set with a bank selector. Each button represents a bank and displays it's color. Pressing a lit button in bank-switch mode will set the Trellsi to that mode.

The current code offers 8 banks each is a channel, expansion is possible to 16 channels, and  ~4 (128 notes devided by 31 buttons per page) pages per bank. In reality the rational limit will likley by 31 * 31 = 961 buttons.

I'm using Keyboard Mastero(https://www.keyboardmaestro.com/main/) which is happy to triger macros by MIDI commands.

The keypad will emit the MIDI notes even if a color isn't assigned to a given key. It should work for any OS that understands USB MIDI input. Any key not confgured will display as off.

## Configuration

Configuration lives in the midi_launcher.h file. There are 2 main areas  to configure.

 * The Channel colors.
 * The Button colors of each bank.
