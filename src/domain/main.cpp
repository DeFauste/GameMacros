#include "iostream"
#include "KeyListener.h"

#pragma warning(disable:4996);
#pragma warning(disable:4703);

int main() {
  bool f = true;
  std::vector<Event *> vector
	  {new ButtonEvent(0x30),
	   new ButtonEvent(0x48), new ButtonEvent(0x45), new ButtonEvent(0x4C),
	   new ButtonEvent(0x4C), new ButtonEvent(0x4F)};

  auto *keyEvents = new KeyEvents(0x48, vector);

  auto *keyListener = new KeyListener(&f,keyEvents);
  keyListener->execute();

  return 0;
}


//using namespace std;
//
//int Save(int key);
//int RunEvent(KeyEvents events);
//void KeyUpTwo(BOOL bState, unsigned int keyCode);
//
//HHOOK hook;
//
//KBDLLHOOKSTRUCT kbStruct;
//
//bool flagEnter = false;
//
//int Save(int key) {
//  if (key == 1 || key == 2) {
//	return 0;
//  }
//
//  std::vector<Event *> vector
//	  {new ButtonEvent(0x30),
//	   new ButtonEvent(0x48), new ButtonEvent(0x45), new ButtonEvent(0x4C),
//	   new ButtonEvent(0x4C), new ButtonEvent(0x4F)};
//
//  auto *keyEvents = new KeyEvents(0x48, vector);
//
//  cout << key << " = " << keyEvents->getMainKey() << "\n";
//  if (key == keyEvents->getMainKey() && !flagEnter) {
//	flagEnter = true;
//	flagEnter = RunEvent(*keyEvents);
//  }
//  return 0;
//}
//
//void KeyUpTwo(BOOL bState, unsigned int keyCode) {
//  BYTE keyState[256];
//  GetKeyboardState((LPBYTE) &keyState);
//  if ((bState && !(keyState[keyCode] & 1)) ||
//	  (!bState && (keyState[keyCode] & 1))) {
//	keybd_event(keyCode, 0, 0, 0);
//	keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
//  }
//}
//int RunEvent(KeyEvents events) {
//  for (Event *s : events.getArrEvent()) {
//	if (s->getType() == TypeEvent::key) {
//	  auto *b = (ButtonEvent *) (s);
//	  KeyUpTwo(true, b->getKey());
//	} else if (s->getType() == TypeEvent::times) {
//	  auto *b = (TimerEvent *) (s);
//	  Sleep(b->getSleepTime());
//	}
//	Sleep(10);
//  }
//  return 0;
//}
//
//LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
//
//  if (nCode >= 0) {
//	if (wParam == WM_KEYDOWN) {
//	  kbStruct = *((KBDLLHOOKSTRUCT *) lParam);
//	  if(!flagEnter)Save(kbStruct.vkCode);
//	}
//  }
//  return CallNextHookEx(hook, nCode, wParam, lParam);
//}
//
//int main() {
//    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1);
//
//    if (!(hook = SetWindowsHookExA(WH_KEYBOARD_LL, HookCallback, NULL, 0))) {
//        MessageBox(NULL, "Nope", "Error", MB_ICONERROR);
//    }
//
//    MSG message;
//    while (true) {
//        GetMessage(&message, NULL, 0, 0);
//    }
//    return 0;
//}