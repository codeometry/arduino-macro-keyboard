/*******************************************************************
 *  A simple Macro keyboard built with Arduino Leonardo and a        
 *  4*4 Button Matrix Keypad.
 *  
 *  Parts:
 *  Arduino Leonardo* - https://amzn.to/2zkbxWq
 *  4*4 Keypad Button Matrix
 *  
 *  * = Affilate
 *  
 * Video Tutorial on: https://youtube.com/codeometry
 * Written Tutorial on: https://codeometry.in
 *******************************************************************/

#include <HID-Project.h>
// Library with a lot of the HID definitions and methods
// Can be installed from the library manager, search for "HID-project"
// and install the one by NicoHood
// https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h

#include <Keypad.h>
// This library is for interfacing with the 4x4 Matrix
// Can be installed from the library manager, search for "keypad"
// and install the one by Mark Stanley and Alexander Brevig
// https://playground.arduino.cc/Code/Keypad/

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {4, 5, 6, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 9, 10, 11 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Consumer.begin();
  Keyboard.begin();
}

void loop() {
  //Getting the key that was pressed.
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
        Keyboard.print("Key '1' was pressed");
        break;

      case '2':
        Keyboard.print("Key '2' was pressed");
        break;

      case '3':
        // https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
        Keyboard.print("Key '3' was pressed");
        break;

      case '4':
        Keyboard.print("Key '4' was pressed");
        break;

      case '5':
        Keyboard.print("Key '5' was pressed");
        break;

      case '6':
        Keyboard.print("Key '6' was pressed");
        break;

      case '7':
        Keyboard.print("Key '7' was pressed");
        break;

      case '8':
        Keyboard.print("Key '8' was pressed");
        break;

      case '9':
        Keyboard.print("Key '9' was pressed");
        break;

      case '0':
        Keyboard.print("Key '0' was pressed");
        break;

      case '*':
        Keyboard.print("Key '*' was pressed");
        break;

      case '#':
       Keyboard.print("Key '#' was pressed");
       break;

      case 'A':
        // https://github.com/NicoHood/HID/wiki/Consumer-API
        Keyboard.print("Key 'A' was pressed");
        break;

      case 'B':
        Keyboard.print("Key 'B' was pressed");
        break;

      case 'C':
        Keyboard.print("Key 'C' was pressed");
        break;

      case 'D':
        Keyboard.print("Key 'D' was pressed");
        break;

    }

    delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}
