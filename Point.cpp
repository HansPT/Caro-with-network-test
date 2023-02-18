#include "Point.h"


void Point::setCheck(char& check)
{
    mCheck = check;
}
char Point::getCheck()
{
    return mCheck;
}

void Point::setTurn(int turn)
{
    mTurn = turn;
}
int Point::getTurn()
{
    return mTurn;
}

Point::Point() 
{
    mCheck = ' ';
}
Point::~Point() = default;