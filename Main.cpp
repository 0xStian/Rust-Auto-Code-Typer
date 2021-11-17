#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <winuser.h>
void buttonpress(int x);
using namespace std;
int input;

int main()
{
    HWND console = GetConsoleWindow(); RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 300, 400, TRUE);
    ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);

    cout << "code: ";
    cin >> input;
    cout << "\n\n\n\n\n\n\n\n      Press \"Q\" to type code";

    int number1 = input / 1000 % 10 + 0x30;
    int number2 = input / 100 % 10 + 0x30;
    int number3 = input / 10 % 10 + 0x30;
    int number4 = input % 10 + 0x30;

    while (true) {

        if (GetAsyncKeyState(0x51)) {

            buttonpress(number1);
            Sleep(50);
            buttonpress(number2);
            Sleep(50);
            buttonpress(number3);
            Sleep(50);
            buttonpress(number4);

        }
        Sleep(1);
    }
}

void buttonpress(int x) {

    keybd_event(x, 0, KEYEVENTF_EXTENDEDKEY, 0);
    Sleep(1);
    keybd_event(x, 0, KEYEVENTF_KEYUP, 0);
}