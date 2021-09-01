#include "stdafx.h"
#include "Dungeon.h"
#include "UI.h"
#include "TextGamePlayer.h"
#include <conio.h>

void Dungeon::invalidate()
{
	pair<int, int> temp;
	for (int i = 0; i < VERTICALSIZE; i++)
	{
		for (int j = 0; j < HORIZENTALSIZE; j++)
		{
			switch (maparr[i][j])
			{
			case PLAYER:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				cout << "★";
				break;
			case OPEN:
				cout << " ";
				break;
			case ENEMY:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				cout << "△";
				break;
			case LOCK:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				cout << "△";
				break;
			}
		}

	}

}

pair<int, int> Dungeon::getActorLocation(int i, int j)
{
	return make_pair(23 + 4 * i, 6 + j);
}

void Dungeon::move(int iinput)
{

	maparr[player->getLocation().first][player->getLocation().second] = OPEN;
	player->setlocation(iinput);
	maparr[player->getLocation().first][player->getLocation().second] = PLAYER;
}

bool Dungeon::available(int ichoice)
{
	switch (ichoice)
	{
	//좌
	case LEFT:
		if (player->getLocation().first - 1 >= 0)
			return true;
		else return false;				
		//우
	case RIGHT:
		if (player->getLocation().first  + 1 < VERTICALSIZE) return true;
		else return false;		
		//상
	case UP:
		if (player->getLocation().second -1 >= 0) return true;
		else return false;		
		//하
	case DOWN:
		if (player->getLocation().second + 1 < HORIZENTALSIZE) return true;
		else return false;
	}

	exit(0);
}

bool Dungeon::turn(int index)
{

	player->applydamege(EnemyVector[index].getAttack());
	EnemyVector[index].applydamege(player->getAttack());
	return false;
}

bool Dungeon::battle(int index)
{
	while (player->getHP() >= 0 && EnemyVector[index].getHP() >= 0)
	{
		turn(index);
	}

	if(player->getHP() <= 0)
		return false;
	return true;
}

int Dungeon::findEnemy(pair<int, int> Enemylocation)
{
	for (size_t i = 0; i < EnemyVector.size(); i++)
	{
		if (EnemyVector[i].getLocation() == player->getLocation())
			return i;
	}
}

Dungeon::Dungeon(TextGamePlayer *player)
{
	TextGamePlayer *tEnemy = NULL;
	srand(time(NULL));
	this->player = player;

	// 던전에 등장할 몹 초기화.
	for (size_t i = 0; i < 5; i++)
	{
		int itemp = rand() % 3 + 4;

		switch (itemp)
		{
		case 4:
			tEnemy = new TextGamePlayer(itemp, "Ogre");
			EnemyVector.push_back(*tEnemy);
			break;
		case 5:
			tEnemy = new TextGamePlayer(itemp, "Goblin");
			EnemyVector.push_back(*tEnemy);
			break;
		case 6:
			tEnemy = new TextGamePlayer(itemp, "Oak");
			EnemyVector.push_back(*tEnemy);
			break;
		}
	}

	for (size_t i = 0; i < VERTICALSIZE; i++)
	{
		for (size_t j = 0; j < HORIZENTALSIZE; j++)
		{
			maparr[i][j] = LOCK;
		}
	}



	//던전에 등장할 몹 위치 맵에 저장.
	for (size_t i = 0; i < EnemyVector.size(); i++)
	{
		pair<int, int> temp = EnemyVector.at(i).getLocation();
		maparr[temp.first][temp.second] = ENEMY;
	}

	//player 위치 반환받아서 던전 맵에 저장.
	pair<int, int> temp = player->getLocation();
	maparr[temp.first][temp.second] = PLAYER;


}

void Dungeon::run()
{
	system("cls");

	UI::showDungeonMap();
	UI::showStatus(*player);

	while (EnemyVector.size() != 0)
	{
		int temp;
		invalidate();

		temp = getch();
		if (temp == 224)
		{
			temp = getch();
		}

		if (available(temp))
		{
			move(temp);

			gotoxy(0, 50);

			for (size_t i = 0; i < VERTICALSIZE; i++)
			{
				for (size_t j = 0; j < HORIZENTALSIZE; j++)
				{
					cout << maparr[i][j] << "  ";
				}
				cout << endl;
			}

			if (maparr[player->getLocation().first][player->getLocation().second] == ENEMY)
			{				
				if (battle(findEnemy(player->getLocation())))
				{
					exit(0);
				}
			}
		}
		
	}

}

void Dungeon::showEnemyNum()
{
	cout << EnemyVector.size();
}
