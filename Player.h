#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include <fstream>


class Player
{
private:
    std::string mName;
    int mWinMatch;
    int mLoseMatch;
    int mDrawmatch;
    int mtotalMatch;
public:
    void setName(std::string& name);
    std::string getName();

    void setWinMatch(int win);
    int getWinMatch();

    void setDrawmatch(int draw);
    int getDrawmatch();

    void setLoseMatch(int lose);
    int getLoseMatch();

    void setTotalMatch(int total);
    int getTotalMatch();

    float winRate();
    void showInfo();

    void ExportInfor(std::ofstream& ofs);

    Player();
    ~Player();
};





#endif