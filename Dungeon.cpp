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
				cout << "��";
				break;
			case OPEN:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				printf("  ");
				break;
			case ENEMY:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				cout << "��";
				break;
			case LOCK:
				temp = getActorLocation(i, j);
				gotoxy(temp.first, temp.second);
				cout << "��";
				break;
			}
		}

	}

}

pair<int, int> Dungeon::getActorLocation(int i, int j)
{
	return make_pair(23 + 4 * i, 6 + j);
}

bool Dungeon::move(int iinput)
{

	maparr[playerlocaiton.first][playerlocaiton.second] = OPEN;

	switch (iinput)
	{
	case UP:
		playerlocaiton.second--;
		break;
	case DOWN:
		playerlocaiton.second++;
		break;
	case RIGHT:
		playerlocaiton.first++;
		break;
	case LEFT:
		playerlocaiton.first--;
		break;
	default:
		break;
	}
	if (maparr[playerlocaiton.first][playerlocaiton.second] == ENEMY)
	{
		return true;
	}
	return false;
}

bool Dungeon::available(int ichoice)
{
	switch (ichoice)
	{
	//��
	case LEFT:
		if (playerlocaiton.first - 1 >= 0) return true;
		else return false;				
		//��
	case RIGHT:
		if (playerlocaiton.first  + 1 < VERTICALSIZE) return true;
		else return false;		
		//��
	case UP:
		if (playerlocaiton.second -1 >= 0) return true;
		else return false;		
		//��
	case DOWN:
		if (playerlocaiton.second + 1 < HORIZENTALSIZE) return true;
		else return false;
	}

	exit(0);
}

bool Dungeon::turn(int index)
{
	UI::showStatus(*player);
	UI::showStatus(EnemyVector.at(index));
	cin;
	gotoxy(0, 0);
	cout << "�÷��̾��� ����" << endl;
	player->applydamege(EnemyVector[index].getAttack());
	UI::showStatus(EnemyVector.at(index));
	cin;
	cout << "���� ����" << endl;
	EnemyVector[index].applydamege(player->getAttack());
	UI::showStatus(*player);
	return false;
}

bool Dungeon::battle(int index)
{
	system("cls");

	while (player->getHP() >= 0 && EnemyVector[index].getHP() >= 0)
	{
		cin;
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
		if (EnemyVector[i].getLocation() == playerlocaiton)
			return i;
	}
}

Dungeon::Dungeon(TextGamePlayer *player)
{
	TextGamePlayer *tEnemy = NULL;
	srand(time(NULL));
	this->player = player;

	// ������ ������ �� �ʱ�ȭ.
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
		free(tEnemy);
 	}

	for (size_t i = 0; i < VERTICALSIZE; i++)
	{
		for (size_t j = 0; j < HORIZENTALSIZE; j++)
		{
			maparr[i][j] = LOCK;
		}
	}



	//������ ������ �� ��ġ �ʿ� ����.
	for (size_t i = 0; i < EnemyVector.size(); i++)
	{
		pair<int, int> temp = EnemyVector[i].getLocation();
		maparr[temp.first][temp.second] = ENEMY;
	}

	//player ��ġ ��ȯ�޾Ƽ� ���� �ʿ� ����.
	playerlocaiton = player->getLocation();
	maparr[playerlocaiton.first][playerlocaiton.second] = PLAYER;
}

void Dungeon::run()
{
	// ȭ�� �ʱ�ȭ.
	system("cls");

	// ���� �� ��� �ϰ�, �÷��̾� �������ͽ� ���


	//��� �� ������ �ش� ���� Ŭ����.
	while (EnemyVector.size() != 0)
	{
		int temp;
		// ȭ�� ���� �Լ�.
		invalidate();
		UI::showDungeonMap();
		UI::showStatus(*player);

		temp = getch();
		if (temp == 224)
		{
			temp = getch();
		}

		if (available(temp))
		{
			if (move(temp))
			{
				if (!battle(findEnemy(playerlocaiton)))
				{					
					break;
				}
				else
				{
					continue;
				}
			}
			maparr[playerlocaiton.first][playerlocaiton.second] = PLAYER;
		}
		
	}

}

void Dungeon::showEnemyNum()
{
	cout << EnemyVector.size();
}
