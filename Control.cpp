#include "Control.h"
#include <fstream>

void Controller::run()
{
    mModel.getPlayers().clear();
    while(true)
    {
        mView.showMenu();
        int chose;
        std::cout << "Enter number: ";
        std::cin >> chose;
        system("cls");
        switch (chose)
        {
            case 1:
            {
                Player player1;
                Player player2;
                std::string name1;
                std::string name2;
                std::cout << "Enter name for 1st player: ";
                std::cin >> name1;
                std::cout << "Enter name for 2nd player: ";
                std::cin >> name2;
                player1.setName(name1);
                player2.setName(name2);
                playGame(player1, player2);
                break;
            }
            case 2:
            {
                return;

            }
            break;
            default:
            break;

        }

    }
}
void Controller::Click(int x, int y, char& XO)
{
	int m = x * 4 + 2;
	int n = y * 2 + 1;
	std::cout << XO;
	if (x < mView.getTablesize() && y < mView.getTablesize() && mView.getFinish() == false) {
		if (mModel.getBoard()[x][y].getCheck() == ' ') {
			if (XO == 'O') {
				XO = 'X';
				mView.gotoXY(m, n);
				mModel.setCurrentTurn();
				mModel.getBoard()[x][y].setTurn(mModel.getCurrentTurn());
				std::cout << XO;
				
			}
			else {
				XO = 'O';
				mView.gotoXY(m, n);
				mModel.setCurrentTurn();
				mModel.getBoard()[x][y].setTurn(mModel.getCurrentTurn());
				std::cout << XO;
			
			}

		}mModel.getBoard()[x][y].setCheck(XO);
	}
}
int Controller::checkResult(const int& x, const int& y, const unsigned char& value)
{
	if (x < mView.getTablesize() && y < mView.getTablesize())
	{
        int count1{0};
        int count2{0};
        int count3{0};
        int count4{0};
        int count5{0};
        int count6{0};
        int count7{0};
        int count8{0};
        int i = x;
        int j = y;
		while (j < mView.getTablesize() && mModel.getBoard()[i][j].getCheck() == value)
		{
			count1++;
			j++;
			if (count1 == 4)
			{
				return 1;
			}
		}
		i = x, j = y;
		while (j >= 0 && mModel.getBoard()[i][j].getCheck() == value)
		{
			count2++;
			j--;
			if (count2 == 4)
			{
				return 1;
			}
		}
		//Ki?m tra ???ng ngang
		i = x, j = y;
		while (i < mView.getTablesize() && mModel.getBoard()[i][j].getCheck() == value)
		{
			count3++;
			i++;
			if (count3 ==4)
			{
				return 1;
			}
		}
		i = x, j = y;
		while (i >= 0 && mModel.getBoard()[i][j].getCheck() == value)
		{
			count4++;
			i--;
			if (count4 == 4)
			{
				return 1;
			}
		}
		//Ki?m tra ???ng ch�o ch�nh
		i = x, j = y;
		while (i < mView.getTablesize() && j < mView.getTablesize() && mModel.getBoard()[i][j].getCheck() == value)
		{
			count5++;
			i++;
			j++;
			if (count5 == 4)
			{
				return 1;
			}
		}

		i = x, j = y;
		while (i >= 0 && j >= 0 && mModel.getBoard()[i][j].getCheck() == value)
		{
			count6++;
			j--;
			i--;
			if (count6 == 4)
			{
				return 1;
			}
		}
		//Ki?m tra ???ng ch�o ph?
		i = x, j = y;
		while (i < mView.getTablesize() && j >= 0 && mModel.getBoard()[i][j].getCheck() == value)
		{
			count7++;
			i++;
			j--;
			if (count7 == 4)
			{
				return 1;
			}
		}

		i = x, j = y;
		while (i >= 0 && j < mView.getTablesize() && mModel.getBoard()[i][j].getCheck() == value)
		{
			count8++;
			j++;
			i--;
			if (count8 == 4)
			{
				return 1;
			}
		}
		return 0;
	}
}
void Controller::playGame(Player player1, Player player2)
{
	system("cls");
	
	mModel.getBoard().clear();
	mModel.getCurrentTurn();
	mView.setFinish(false);
	mView.showTable();
	mView.gotoXY(5, 2 * mView.getTablesize() + 1);
	std::cout << player1.getName() << " turn: X" << "\t\t" << player2.getName() << " turn: O";
	mModel.setBoard(mView.getTablesize());
	char XO = 'O';
	while (true) {

		COORD xy = mView.checkClick();

		Click(xy.X / 4, xy.Y / 2, XO);
		if (checkResult(xy.X / 4, xy.Y / 2, XO) == 1) {
			if (XO == 'X') {
				mView.gotoXY(0, 2 * mView.getTablesize() + 3);
				std::cout << "CONGRATULATION player " << player1.getName();
				player1.setWinMatch(player1.getWinMatch() + 1);
				player2.setLoseMatch(player2.getLoseMatch() + 1);
				mView.setFinish(true);
			}
			else {
				mView.gotoXY(0, 2 * mView.getTablesize() + 3);
				std::cout << "CONGRATULATION player " << player2.getName();
				player2.setWinMatch(player2.getWinMatch() + 1);
				player1.setLoseMatch(player1.getLoseMatch() + 1);
				mView.setFinish(true);
			}
		}
		if (checkResult(xy.X / 4, xy.Y / 2, XO) == 2) {
			mView.gotoXY(0, 2 * mView.getTablesize() + 3);
			std::cout << "Draw";
			mView.setFinish(true);
		}
		mView.gotoXY(50, 1);
		std::cout << "QUIT";
		if ((xy.X < 55 && xy.X > 50) && (xy.Y < 2 && xy.Y > 0)) {
			system("cls");
			return;
		
		}
		if (mView.getFinish() == true) {
			mView.gotoXY(50, 3);
			std::cout << "PLAY AGAIN";
			if ((xy.X < 60 && xy.X >50) && (xy.Y < 4 && xy.Y > 2)) {
				/*HANDLE       hStdOutput = NULL;
				mView.cls(hStdOutput);*/
				playGame(player1, player2);
				return;
			}
		}
		if (mView.getFinish() == true) {
			mView.gotoXY(50, 5);
			std::cout << "REPLAY";
			if ((xy.X < 57 && xy.X > 50) && (xy.Y < 6 && xy.Y > 4)) {
				system("cls");
				this->showReplay();
				return;
			}
		}
		if (mView.getFinish() == true) {
			mView.gotoXY(50, 7);
			std::cout << "SAVE";
			if ((xy.X < 55 && xy.X > 50) && (xy.Y < 8 && xy.Y > 6)) {
				system("cls");
				mModel.getPlayers().push_back(player1);
				mModel.getPlayers().push_back(player2);
				this->update(mModel.getPlayers());
				this->exportFile();
				return;
			}
		}
	}
}
void Controller::update(std::vector<Player> &players)
{
    for(int i = 0; i < players.size() - 1; i++)
    {
        for(int j = i + 1; j < players.size(); j++)
        {
            if(players[i].getName() == players[j].getName())
            {
                players[i].setWinMatch(players[i].getWinMatch() + players[j].getWinMatch());
				players[i].setLoseMatch(players[i].getLoseMatch() + players[j].getLoseMatch());
				players[i].setDrawmatch(players[i].getDrawmatch() + players[j].getDrawmatch());
				players.erase(players.begin() + j);
				j--;
            }
        }
    }
}


void Controller::showReplay()
{
	if(mModel.getCurrentTurn() != 0)
	{
		system("cls");
		for(int i = 0; i < mView.getTablesize()*4 + 1; i++)
		{
			std::cout << '-';
		}
		std::cout << '\n';
		for(int i = 0; i < mView.getTablesize(); i++)
		{
			for( int j = 0; j < mView.getTablesize(); j)
			{
				std::cout << '|' << ' ' << ' ' << ' ';
			}
			std::cout << "|\n";
			for( int i = 0; i < mView.getTablesize()*4 + 1; i++)
			{
				std::cout << '-';
			}
		}
		std::cout << '\n';
		for(int k = 0; k <= mModel.getCurrentTurn(); k++)
		{
			for(int i = 0; i< mModel.getBoard().size(); i++)
			{
				for(int j = 0; j < mModel.getBoard().size(); j++)
				{
					if(k == mModel.getBoard()[i][j].getTurn())
					{
						mView.gotoXY(i*4 + 2, j*2 +1);
						std::cout << mModel.getBoard()[i][j].getCheck();
						Sleep(600);
					}
				}
			}
			if(mModel.getCurrentTurn() /2 == 0)
			{
				mView.gotoXY(0,2*mView.getTablesize() + 2);
				std::cout << "O is the winner!\n";
			}
			else
			{
				mView.gotoXY(0,2*mView.getTablesize() + 2);
				std::cout << "X is the winner!\n";
			}
		}
	}
	else
	{
		std::cout << "Not matching!\n";
		system("pause");
	}
}
void Controller::exportFile()
{
	std::ofstream ofs("Infor.ini");
	for(int i = 0;i < mModel.getPlayers().size();i++)
	{
		mModel.getPlayers()[i].ExportInfor(ofs);
	}
	ofs.close();
}

void Controller::showData()
{
	std::fstream ifs;
	ifs.open("Infor.ini", std::ios::in);
	char name[25];
	char win[25];
	char lose[5];
	char draw[5];
	char account[25];
	std::cout << "\n Type your account:";
	std::cin.ignore(100,'\n');
	std::cin.getline(account, 25);
	int x = 0;	
	while(!ifs.eof())
	{
		ifs.getline(name,25,' ');
		ifs.getline(win,5,' ');
		ifs.getline(lose,5,' ');
		ifs.getline(draw,5);
		if(strcmp(name, account) == 0)
		{
			std::cout << "\t\tInfor player:\n";
			std::cout << "Account: " << name << "\n";
			std::cout << "Win: " << win << "\n";
			std::cout << "Lose: " << lose << "\n";
			std::cout << "Drawn: " << draw << "\n";
			x = 1;
			break;
		}
	}
	if(x == 0)
	{
		std::cout << "\n Data not found!\n";

	}
	ifs.close();
}
void Controller::removeFile()
{
	if(remove("Infor.ini") == 0)
	{
		perror("Error removing");
	}
	else
	{
		puts("Removing successfully");
	}
}
void Controller::imPort()
{
	mModel.getPlayers().clear();
	std::vector<std::string> lines;
	std::string line;
	std::ifstream ifs("Infor.ini", std::ios::in);
	if (!ifs.is_open()) {
		std::cerr << "Load data error!\n";
		return;
	}
	while (getline(ifs, line)) {
		lines.push_back(line);//L?u t?ng d�ng nh? m?t ph?n t? v�o vector lines.
	}

	for (int i = 0; i < lines.size(); i++)
	{
		char str[25];
		char name[20];
		int win(0), lost(0), draw(0);
		strcpy_s(str, lines[i].c_str());
		sscanf_s(str, " %s  %d  %d  %d", name, 20, &win, &lost, &draw);
		// unique_ptr<Player> temp(new Player);
		Player temp;
		temp.setName(std::string(name));
		temp.setWinMatch(win);
		temp.setLoseMatch(lost);
		temp.setDrawmatch(lost);
		mModel.getPlayers().push_back(temp);
		//cout << lines[i] << endl;
	}
	ifs.close();
}

Controller::Controller() = default;
Controller::~Controller() = default;