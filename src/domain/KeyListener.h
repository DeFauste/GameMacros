#include "KeyEvents.h"
#include <windows.h>
#include "iostream"
#include <winuser.h>

#ifndef SRC_DOMAIN_KEYLISTENER_H_
#define SRC_DOMAIN_KEYLISTENER_H_

class KeyListener {

 private:
  bool *_start;
  KeyEvents *_key_events;
//
//  int RunEvent(KeyEvents events);
//  int Save(int key);
//  void KeyUpTwo(BOOL bState, unsigned int keyCode);

 public:
  KeyListener(bool *start, KeyEvents *key_events);
  int execute();
  KeyEvents *getKeyEvents() { return _key_events; };

};

#endif //SRC_DOMAIN_KEYLISTENER_H_
