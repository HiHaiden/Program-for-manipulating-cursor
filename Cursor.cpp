#include <iostream>
#include <conio.h>
#include <windows.h>

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
    int x = 960, y = 540;
    int step = 10;
    char c;

    SetCursorPos(x, y);
    do {
        hidecursor();
        c = _getch();
        switch (c) {
        case 75: SetCursorPos(x -= step, y); break;
        case 77: SetCursorPos(x += step, y); break;
        case 72: SetCursorPos(x, y -= step); break;
        case 80: SetCursorPos(x, y += step); break;
        }
    } while (c != 27); // Esc

    system("pause");
    return 0;
}