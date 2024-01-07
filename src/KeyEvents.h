#include "iostream"
#include "Event.h"
#include <vector>

#ifndef GAMEMACROS_KEYCOMMANDS_H
#define GAMEMACROS_KEYCOMMANDS_H

class KeyEvents {
 private:
  unsigned int _mainKey;
  std::vector<Event*> _vEvent;
 public:
  KeyEvents(unsigned int mainKey, std::vector<Event*> vEvent);
  unsigned int getMainKey() const;
  std::vector<Event*> getArrEvent();
};

#endif //GAMEMACROS_KEYCOMMANDS_H
