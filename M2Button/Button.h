/*
  Button.h - Library for accessing a simple momentary button.
  Created by M2Squared, July 9, 2025
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"
/*
  A simple button. 
*/
class Button {
    public:
    Button(int pin);
    void begin();
    bool isPressed();
    bool isLongPressed();
    void setLongPressTime(long time);
    long getLongPressTime();
    virtual void onPress();
    virtual void onRelease();

    private:
    int _pin;
    long _longPressTime;
    long _lastPressed;
};

#endif
