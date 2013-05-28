#include "Arduino.h"
#include "PushButton.h"

const int PushButton::UNCHANGED = 0;
const int PushButton::PRESSED = 1;
const int PushButton::RELEASED = 2;

PushButton::PushButton(int pin){
  pinMode(pin, INPUT);
  _pin = pin;
  _prevState = false;
  _lastHighState = 0;
  _minDelayBetweenHighState = 100;
}

int PushButton::getState(){
   if (_buttonPressed()){
     return PRESSED; 
   } else if (_buttonReleased()){
     return RELEASED; 
   }
   return UNCHANGED;
}

boolean PushButton::_buttonPressed(){
  if (_buttonState() == true && _prevState == false) {
    _prevState = true; 
    return true;
  }
  return false;
}

boolean PushButton::_buttonReleased(){
  if (_buttonState() == false && _prevState == true) {
     if (abs(millis() - _lastHighState) > _minDelayBetweenHighState){
       _prevState = false;
       return true;
     }
  }
  return false ;
}

boolean PushButton::_buttonState(){
  if (digitalRead(_pin)){
    _lastHighState = millis();
    return true;
  }
  return false;
}