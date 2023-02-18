#include "Model.h"

std::vector<std::vector<Point>>& Model::getBoard()
{
    return mBoard;
}
void Model::setBoard(int board)
{
    for(int i = 0; i < board; i++)
    {
        std::vector<Point> points;
        for(int j = 0; j < board; j++)
        {
            Point a;
            points.push_back(a);
        }
        mBoard.push_back(points);
    }
}


void Model::setPlayerManager(std::vector<Player> players)
{
    mManagers = players;
}
std::vector<Player>& Model::getPlayerManager()
{
    return mManagers;
}

void Model::setPlayers(std::vector<Player> players)
{
    mPlayers = players;
}
std::vector<Player>& Model::getPlayers()
{
    return mPlayers;
}

void Model::setCurrentTurn()
{
    mCurrentTurn++;
}
int Model::getCurrentTurn()
{
    return mCurrentTurn;
}

Model::Model() = default;
Model::~Model() = default;