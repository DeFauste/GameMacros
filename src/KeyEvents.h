#include "iostream"
#include "Event.h"
#include <vector>

#ifndef GAMEMACROS_KEYCOMMANDS_H
#define GAMEMACROS_KEYCOMMANDS_H

class KeyEvents {
 private:
  int _mainKey ;
  std::vector<Event*> _vEvent;
 public:
  KeyEvents(int mainKey, std::vector<Event*> vEvent);
  int getMainKey();
  std::vector<Event*> getArrEvent();
};

#endif //GAMEMACROS_KEYCOMMANDS_H
