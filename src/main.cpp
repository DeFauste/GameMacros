#include <windows.h>
#include "KeyEvents.h"
#include <chrono>
#include <thread>
#include <winuser.h>

using namespace std;

void KeyUpTwo(BOOL bState, unsigned int keyCode) {
  BYTE keyState[256];
  GetKeyboardState((LPBYTE) &keyState);
  if ((bState && !(keyState[keyCode] & 1)) ||
	  (!bState && (keyState[keyCode] & 1))) {
	keybd_event(keyCode, 0, 0, 0);
	keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
  }
}
void RunEvent(KeyEvents events) {
  for (Event *s : events.getArrEvent()) {
	if (s->getType() == TypeEvent::key) {
	  ButtonEvent *b = static_cast<ButtonEvent *>(s);
	  KeyUpTwo(true, b->getKey());
	} else if (s->getType() == TypeEvent::times) {
	  TimerEvent *b = static_cast<TimerEvent *>(s);
	  Sleep(b->getSleepTime());
	}
  }
}

int main() {
  std::vector<Event *> vector
	  {new ButtonEvent(0x5C), new TimerEvent(2),
	   new ButtonEvent(0x48), new ButtonEvent(0x45), new ButtonEvent(0x4C),
	   new ButtonEvent(0x4C), new ButtonEvent(0x4F)};
  KeyEvents *keyEvents = new KeyEvents(0x48, vector);
  RunEvent(*keyEvents);

  return 0;
}