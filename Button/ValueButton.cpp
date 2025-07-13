/*
  Impelementation of a Simple Momentary Button that keeps track
  of an integer value.
  Created by M2Squared, July 11, 2025
*/

#include "Arduino.h"
#include "ValueButton.h"

const int DEFAULT_INCREMENT = 1;
const int DEFAULT_INITIAL_VALUE = 0;

/*
    Constructor. Sets increment and initial value to defaults.
*/
ValueButton::ValueButton(int pin) : Button(pin) {
    _increment = _initialIncrement = DEFAULT_INCREMENT;
    _value = _initialValue = DEFAULT_INITIAL_VALUE;
    _pressed = false;
}

/*
    Constructor. Sets increment to value passed and initial value to default.
*/
ValueButton::ValueButton(int pin, int initialIncrement) : Button(pin)  {
    _increment = _initialIncrement = initialIncrement;
    _value = _initialValue = DEFAULT_INITIAL_VALUE;
    _pressed = false;
}

/*
    Constructor. Sets increment and initial value to passed values.
*/
ValueButton::ValueButton(int pin, int initialIncrement, int initialValue) : Button(pin)  {
    _increment = _initialIncrement = initialIncrement;
    _value = _initialValue = initialValue;
    _pressed = false;
}

/*
    Retrieves the current tracked value.
*/
int ValueButton::getValue() {
    return _value;
}

/*
    Sets the current tracked value.
*/
void ValueButton::setValue(int value) {
    _value = value;
}

/*
    Retrieves the increment.
*/
int ValueButton::getIncrement(){
    return _increment;
}

/*
    Sets the increment.
*/
void ValueButton::setIncrement(int increment) {
    _increment = increment;
}

/*
    Sets the _pressed flag to true indicating that the button has been pressed.
    It is called from isPressed if the button is pressed.
*/
void ValueButton::onPress() {
    _pressed = true;
}

/*
    If the _pressed flag is set this method increments the stored value by
    _increment then resets the _pressed flag. It is called from isPressed if
    the button is not pressed.
*/
void ValueButton::onRelease() {
    if (_pressed) {
        _value += _increment;
        _pressed = false;
    }
}

/*
    Resets this ValueButton to its initial state.
*/
void ValueButton::reset() {
    _increment = _initialIncrement;
    _value = _initialValue;
}
