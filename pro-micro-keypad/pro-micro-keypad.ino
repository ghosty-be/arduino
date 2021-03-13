/*
 *  A quick macro keyboard built with 
 *  Arduino Pro Micro and a        
 *  4*4 Button Matrix.
 *
 *  in arduino IDE choose board type:
 *  Arduino Leonardo
 *  Even when the board is an Arduino pro micro
 *
 *  Keyboard.h (and Mouse.h) only work on devices that use the ATmega32u4 processor, 
 *  like the Leonardo or (pro) Micro
 *
*/

// ---------
// Libraries
// ---------

#include "Keyboard.h"
// Library with a lot of the HID definitions and methods
// Can be useful to take a look at it see whats available
// https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h

#include <Keypad.h>
// This library is for interfacing with the 4x4 Matrix
// 
// Can be installed from the library manager, search for "keypad"
// and install the one by Mark Stanley and Alexander Brevig
// https://playground.arduino.cc/Code/Keypad/

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F'},
};

// the way I connected it the rows are in reverse order
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '0':
        Keyboard.write('0');
        break;
      case '1':
        Keyboard.write('1');
        break;
      case '2':
        Keyboard.write('2');
        break;
      case '3':
        Keyboard.write('3');
        break;
      case '4':
        Keyboard.write('4');
        break;
      case '5':
        Keyboard.write('5');
        break;
      case '6':
        Keyboard.write('6');
        break;
      case '7':
        Keyboard.write('7');
        break;
      case '8':
        Keyboard.write('8');
        break;
      case '9':
        Keyboard.write('9');
        break;
      case 'A':
        Keyboard.write('A');
        break;
      case 'B':
        Keyboard.write('B');
        break;
      case 'C':
        Keyboard.write('C');
        break;
      case 'D':
        Keyboard.write('D');
        break;
      case 'E':
        Keyboard.write('E');
        break;
      case 'F':
        Keyboard.write('F');
        break;
    }

    delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}
