#include "KeyEvents.h"

int KeyEvents::getMainKey() {
  return _mainKey;
}
std::vector<Event *> KeyEvents::getArrEvent() {
  return _vEvent;
}
KeyEvents::KeyEvents(int mainKey, std::vector<Event *> vEvent) {
  _mainKey = mainKey;
  for(Event* e: vEvent) {
	_vEvent.push_back(e);
  }
}
