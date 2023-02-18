#ifndef __CONTROLL__
#define __CONTROLL__



#include "View.h"
#include "Model.h"

class Controller
{
private:
    Model mModel;
    View mView;
public:
    void run();
    void Click(int x, int y, char&);
    int checkResult(const int& x, const int& y, const unsigned char& value);
    void playGame(Player player1, Player player2);
    void update(std::vector<Player>& players);

    void showReplay();
    void exportFile();
    void showData();
    void removeFile();
    void imPort();


    Controller();
    ~Controller();
};





#endif