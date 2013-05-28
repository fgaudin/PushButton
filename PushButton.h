#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton
{
  public:
    static const int UNCHANGED;
    static const int PRESSED;
    static const int RELEASED;
    PushButton(int pin);
    int getState();
  private:
    int _pin;
    boolean _prevState;
    unsigned long _lastHighState;
    int _minDelayBetweenHighState;
    boolean _buttonPressed();
    boolean _buttonReleased();
    boolean _buttonState();
};

#endif 
