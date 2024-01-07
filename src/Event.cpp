#include "Event.h"

int ButtonEvent::getKey() const {
  return _keyCode;
}
int Event::getType() const {
  return _typeEvent;
}
unsigned int TimerEvent::getSleepTime() {
  return _sleepTime;
}
