#include "KeyListener.h"

#pragma warning(disable:4996);
#pragma warning(disable:4703);

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam);

using namespace std;

KeyEvents *keyEvents;

KeyListener::KeyListener(bool *start, KeyEvents *key_events) {
  _start = start;
  _key_events = key_events;
}
/******/
using namespace std;

HHOOK hook;

KBDLLHOOKSTRUCT kbStruct;

bool flagEnter = false;

void KeyUpTwo(BOOL bState, unsigned int keyCode) {
  BYTE keyState[256];
  GetKeyboardState((LPBYTE) &keyState);
  if ((bState && !(keyState[keyCode] & 1)) ||
	  (!bState && (keyState[keyCode] & 1))) {
	keybd_event(keyCode, 0, 0, 0);
	keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
  }
}
int RunEvent(KeyEvents events) {
  for (Event *s : events.getArrEvent()) {
	if (s->getType() == TypeEvent::key) {
	  auto *b = (ButtonEvent *) (s);
	  KeyUpTwo(true, b->getKey());
	} else if (s->getType() == TypeEvent::times) {
	  auto *b = (TimerEvent *) (s);
	  Sleep(b->getSleepTime());
	}
	Sleep(10);
  }
  return 0;
}
int Save(int key) {
  if (key == 1 || key == 2) {
	return 0;
  }

  cout << key << " = " << keyEvents->getMainKey() << "\n";
  if (key == keyEvents->getMainKey() && !flagEnter) {
	flagEnter = true;
	flagEnter = RunEvent(*keyEvents);
  }
  return 0;
}
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {

  if (nCode >= 0) {
	if (wParam == WM_KEYDOWN) {
	  kbStruct = *((KBDLLHOOKSTRUCT *) lParam);
	  if (!flagEnter)Save(kbStruct.vkCode);
	}
  }
  return CallNextHookEx(hook, nCode, wParam, lParam);
}

int KeyListener::execute() {

  keyEvents = getKeyEvents();

//  ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1);

  if (!(hook = SetWindowsHookExA(WH_KEYBOARD_LL, HookCallback, NULL, 0))) {
	MessageBox(NULL, "Nope", "Error", MB_ICONERROR);
  }

  MSG message;
  while (*_start) {
	GetMessage(&message, NULL, 0, 0);
  }
  return 0;
}
