#ifndef __VIEW__
#define __VIEW__




#include <iostream>
#include <Windows.h>


class View
{
private:
    int mTablesize{0};
    bool mFinish;
public:
    void showMenu();
    void setFinish(const bool& finished);
    bool getFinish();

    void setTablesize(int size);
    int getTablesize();

    void showTable();

   // void showTableGame();

    void gotoXY(int x, int y);
    COORD checkClick();


    View();
    ~View();
};


#endif