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

void Dungeon::move()
{
	if (available(_getch()))
	{

	}
}

bool Dungeon::available(int ichoice)
{
	switch (ichoice)
	{
	//좌
	case 75:
		if (player->getLocation().first - 1 >= 0)
		{
			
			return true;
		}
		else return false;				
		//우
	case 77:
		if (player->getLocation().first  + 1 < VERTICALSIZE) return true;
		else return false;
		
		//상
	case 72:
		if (player->getLocation().second -1 >= 0) return true;
		else return false;		
		//하
	case 80:
		if (player->getLocation().second + 1 < HORIZENTALSIZE) return true;
		else return false;
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
		invalidate();
		move();
	}

}

void Dungeon::showEnemyNum()
{
	cout << EnemyVector.size();
}
