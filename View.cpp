#include "View.h"

void View::showMenu()
{
    std::cout << "Menu Play game Caro\n";
    std::cout << "Type 1 to choose as player 1\n";
    std::cout << "Type 2 to to exit\n";
}
void View::setFinish(const bool& finished)
{
    mFinish = finished;
}
bool View::getFinish()
{
    return mFinish;
}

void View::setTablesize(int size)
{
    mTablesize = size;
}
int View::getTablesize()
{
    return mTablesize;
}

void View::showTable()
{
    int size{0};
    std::cout << "Type the table size you want to show\n";
    std::cin >> size;
    mTablesize = size;
    system("cls");
    for( int i = 0; i < (mTablesize*4) + 1; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
    for(int i = 0; i < mTablesize; i++)
    {
        for(int j = 0; j < mTablesize; j++)
        {
            std::cout << "|" << ' ' << ' ' << ' ';
        }
        std::cout << '|' << "\n";
        for(int i = 0; i < (mTablesize*4) + 1; i++)
        {
            std::cout << "-";
        }
        std::cout << "\n";
    }
}

void View::gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
COORD View::checkClick()
{
    INPUT_RECORD ir[128];
    DWORD        nRead;
    COORD        xy;
    HANDLE       hStdInput = NULL;
    HANDLE       hStdOutput = NULL;
    HANDLE       hEvent = NULL;


    hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hStdInput);
    SetConsoleMode(hStdInput, ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    HANDLE handles[2] = { hEvent, hStdInput };
    while (WaitForMultipleObjects(2, handles, FALSE, INFINITE)) {
        ReadConsoleInput(hStdInput, ir, 128, &nRead);
        for (unsigned int i = 0; i < nRead; i++) {
            if (ir[i].EventType == MOUSE_EVENT) {
                xy.X = ir[i].Event.MouseEvent.dwMousePosition.X, xy.Y = ir[i].Event.MouseEvent.dwMousePosition.Y;
                if (((int)ir[i].Event.MouseEvent.dwButtonState & 0x07) == 1) {

                    return xy;
                }
            }
        }
    }
}


View::View() = default;
View::~View() = default;