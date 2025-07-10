/*
  Impelementation of a Simple Momentary Button
  Created by M2Squared, July 9, 2025
*/

#include "Arduino.h"
#include "Button.h"

const long DEFAULT_LONG_PRESS_TIME = 3000;

Button::Button(int pin, int type) {
    _pin = pin;
    _type = type;
    _longPressTime = DEFAULT_LONG_PRESS_TIME;
    _lastPressed = 0L;
}

void Button::begin() {
    pinmode(_pin, _type);
}

void Button::setLongPressTime(long time) {
    _longPressTime = time;
}

bool Button::isPressed() {
    int val = digitalRead(_pin);
    if (_type == INPUT_PULLUP) {
        return val == LOW;
    }
    return val == HIGH;
}

bool Button::isLongPressed() {
    int val = digitalRead(_pin);

    if ((_type == INPUT_PULLUP && val == LOW) ||
        (_type == INPUT_PULLDOWN && val == HIGH)) {
        if (_lastPressed == 0L) {
            _lastPressed = millis();
        }
    }
    else {
        _lastPressed = 0L;
        return false;
    }
    return millis() - _lastPressed >= _longPressTime;
}
