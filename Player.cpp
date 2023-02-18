#include "Player.h"
#include <iostream>
#include <string>

void Player::setName(std::string& name)
{
    mName = name;
}

std::string Player::getName()
{
    return mName;
}

void Player::setWinMatch(int win)
{
    mWinMatch = win;
}
int Player::getWinMatch()
{
    return mWinMatch;
}

void Player::setDrawmatch(int draw)
{
    mDrawmatch = draw;
}
int Player::getDrawmatch()
{
    return mDrawmatch;
}

void Player::setLoseMatch(int lose)
{
    mLoseMatch = lose;
}
int Player::getLoseMatch()
{
    return mLoseMatch;
}

void Player::setTotalMatch(int total)
{
    mtotalMatch = total;
}
int Player::getTotalMatch()
{
    return mtotalMatch;
}

float Player::winRate()
{
    return (float(mWinMatch) / float(mtotalMatch));
}
void Player::showInfo()
{

}

void Player::ExportInfor(std::ofstream& ofs)
{
    ofs << this->getName() << " " << this->getWinMatch() << " " << this->getLoseMatch() << " " << this->getDrawmatch() << '\n';
}

Player::Player()
{
    mName = "";
    mWinMatch = mDrawmatch = mLoseMatch = 0;
    mtotalMatch = mWinMatch + mDrawmatch + mLoseMatch;

}
Player::~Player() = default;