/*
  ValueButton.h - Library for accessing a simple momentary button that
  keeps track of an integer value.
  Created by M2Squared, July 11, 2025
*/

#ifndef VALUE_BUTTON_H
#define VALUE_BUTTON_H

#include "Arduino.h"
#include "Button.h"

/*
  A button that keeps track of an integer value;
*/
class ValueButton : public Button {
    public:
    ValueButton(int pin);
    ValueButton(int pin, int initialIncrement);
    ValueButton(int pin, int initialIncrement, int initialValue);
    int getValue();
    void setValue(int value);
    int getIncrement();
    void setIncrement(int increment);
    void onPress();
    void onRelease();
    void reset();

    private:
    int _initialIncrement;
    int _increment;
    int _initialValue;
    int _value;
    bool _pressed;
};

#endif