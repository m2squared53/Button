/*
  Impelementation of a Simple Momentary Button
  Created by M2Squared, July 9, 2025
*/

#include "Arduino.h"
#include "Button.h"

const long DEFAULT_LONG_PRESS_TIME = 3000;

/*
    Constructor. Assigns pin to internal state and sets the long press time
    to DEFAULT_LONG_PRESS_TIME.
*/
Button::Button(int pin) {
    _pin = pin;
    _longPressTime = DEFAULT_LONG_PRESS_TIME;
    _lastPressed = 0L;
}

/*
 This method assigns the digital pin to the button. It always uses INPUT_PULLUP
 so no external resitor is required.
*/
void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
}

/*
   Sets the long press time the value passed. No validity checks are made!
*/
void Button::setLongPressTime(long time) {
    _longPressTime = time;
}

/*
    Retrieves the long press time in milliseconds.
*/
long Button::getLongPressTime() {
    return _longPressTime;
}

/*
    This is a do nothing method for the base class. It is called from isPressed
    if the button is pressed.
*/
void Button::onPress() {

}

/*
    This is a do nothing method for the base class. It is called from isPressed
    if the button is not pressed.
*/
void Button::onRelease() {

}

/*
    This method checks if the button is pressed.
*/
bool Button::isPressed() {
    int state = digitalRead(_pin);
    // Using negative logic, i.e. value is LOW when pressed.
    if (state == LOW) {
        onPress();
        return true;
    }
    onRelease();
    return false;
}

/*
    This method checks for long press. It should be called in a loop and will
    return true when the system time is _longPressTime milliseconds greater than
    _lastPressed.
*/
bool Button::isLongPressed() {
    int val = digitalRead(_pin);

    // Using negative logic, i.e. value is LOW when pressed.
    if (val == LOW) {
        if (_lastPressed == 0L) {
            // Store the current system time if pressed
            _lastPressed = millis();
        }
    }
    else {
        _lastPressed = 0L;
        return false;
    }
    return millis() - _lastPressed >= _longPressTime;
}
