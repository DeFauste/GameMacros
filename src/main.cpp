#include <windows.h>
#include "KeyCommands.h"
#include <chrono>
#include <thread>
#include <winuser.h>

using namespace std;

void KeyUp(unsigned int keyCode) {
    INPUT Input = {0};
    Input.type = INPUT_KEYBOARD;
    char b = keyCode;
    cout << keyCode;
    Input.ki.wVk = VkKeyScanA(b);
    SendInput(1, &Input, sizeof(Input));
    ZeroMemory(&Input, sizeof(Input));
    Input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &Input, sizeof(Input));
}
void KeyUpTwo(BOOL bState, unsigned int keyCode) {
    BYTE keyState[256];

    GetKeyboardState((LPBYTE) &keyState);
    if ((bState && !(keyState[keyCode] & 1)) ||
        (!bState && (keyState[keyCode] & 1))) {
        keybd_event(keyCode, 0, 0 ,0);
        keybd_event(keyCode, 0, KEYEVENTF_KEYUP,0);
    }
}
void keyRead(KeyCommands keyCommands) {
    unsigned int *key = keyCommands.getPushKey();
    for (unsigned int i = 0; i < 6; i++) {
        Sleep(1000);
//        KeyUp(key[i]);
        KeyUpTwo(true, key[i]);
    }
}


int main() {
    unsigned int keyCode[] = {0x5C, 0x48, 0x45, 0x4C, 0x4C, 0x4F};
    KeyCommands test(0, keyCode);
    keyRead(test);
//    KeyUp(true, 0x45);
    return 0;
}