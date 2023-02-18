#ifndef __POINT__
#define __POINT__



class Point
{
private:
    char mCheck;
    int mTurn{0};
public:
    void setCheck(char& check);
    char getCheck();

    void setTurn(int turn);
    int getTurn();

    Point();
    ~Point();
};



#endif