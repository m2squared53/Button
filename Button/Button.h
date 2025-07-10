/*
  Button.h - Library for accessing a simple momentary button.
  Created by M2Squared, July 9, 2025
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

/*
  pin is the digital pin that the button connects to
  type is the INPUT type and must be either INPUT_PULLUP for negative logic, 
    i.e. Active LOW when pushed or INPUT_PULLDOWN for positive Active HIGH logic
*/
class Button {
    public:
    Button(int pin, int type);
    void begin();
    bool isPressed();
    bool isLongPressed();
    void setLongPressTime(long time);
    long getLongPressTime();

    private:
    int _pin;
    int _type;
    long _longPressTime;
    long _lastPressed;
}

#endif