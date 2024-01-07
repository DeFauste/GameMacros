#include "KeyEvents.h"

unsigned int KeyEvents::getMainKey() const {
  return _mainKey;
}
std::vector<Event *> KeyEvents::getArrEvent() {
  return _vEvent;
}
KeyEvents::KeyEvents(unsigned int mainKey, std::vector<Event *> vEvent) {
  for(Event* e: vEvent) {
	_vEvent.push_back(e);
  }
}
