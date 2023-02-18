#ifndef __MODEL__
#define __MODEL__


#include "Player.h"
#include "Point.h"
#include <vector>


class Model
{
private:
    std::vector<std::vector<Point>> mBoard;
    std::vector<Player> mPlayers;
    std::vector<Player> mManagers;
    int mCurrentTurn{0};
public:
    std::vector<std::vector<Point>>& getBoard();
    void setBoard(int board);
    
    void setPlayerManager(std::vector<Player> players);
    std::vector<Player>& getPlayerManager();

    void setPlayers(std::vector<Player> players);
    std::vector<Player>& getPlayers();

    void setCurrentTurn();
    int getCurrentTurn();

    Model();
    ~Model();
};





#endif