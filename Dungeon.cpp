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
}

bool Dungeon::turn(int index)
{
	static bool temp = true;
	system("cls");
	UI::showStatus(*player);
	UI::showStatus(EnemyVector.at(index));
	getch();
	if (temp)
	{
		gotoxy(0, 0);
		cout << "�÷��̾��� ����" << endl;

		int result = moveIcon();
		if (result < 30 || result > 70)
		{
			result = 1;
		}
		else if (result <= 70 && result >= 30)
		{
			result = 2;
		}

		switch (result)
		{
		case 1:
			EnemyVector[index].applydamege(player->getAttack());			
			break;
		case 2:
			EnemyVector[index].applydamege((int)(player->getAttack() * 1.5));			
			break;
		}

	}
	else
	{
		gotoxy(0, 0);
		cout << EnemyVector[index].getName() << "�� ����" << endl;
		getch();
		int result = rand() % 101;

		if (result < 30 || result > 70)
		{
			result = 1;
		}
		else if (result <= 70 && result >= 30)
		{
			result = 2;
		}
		switch (result)
		{
		case 1:
			player->applydamege(EnemyVector[index].getAttack());
			break;
		case 2:
			player->applydamege((int)(EnemyVector[index].getAttack() * 1.5));
			break;
		}
	}

	if (temp == true){temp = false;}
	else { temp = true; }

	return false;
}

void Dungeon::battle(int index)
{
	system("cls");

	while (player->getHP() >= 0 && EnemyVector[index].getHP() >= 0)
	{
		turn(index);
	}

	EnemyVector.erase(begin(EnemyVector) + index);

	system("cls");

}

int Dungeon::findEnemy(pair<int, int> Enemylocation)
{
	for (size_t i = 0; i < EnemyVector.size(); i++)
	{
		if (EnemyVector[i].getLocation() == playerlocaiton)
			return i;
	}
}

int Dungeon::moveIcon()
{
	int i = 1;
	bool isfront = true;
	UI::showBattle();
	while (!_kbhit())
	{
		setBackgroundColor();
		gotoxy(i + 10, 10);
		cout << "  ";
		gotoxy(i + 10, 11);
		cout << "  ";
		gotoxy(i + 10, 12);
		cout << "  ";
		gotoxy(i + 10, 13);
		cout << "  ";
		gotoxy(i + 10, 14);
		cout << "  ";
		gotoxy(i + 10, 15);
		cout << "  ";
		Sleep(10);
		UI::showBattle();
		if (i == 0)
			isfront = true;
		if (i == 100)
			isfront = false;
		if (isfront)
		{
			i++;
		}
		else
		{
			i--;
		}

	}
	setBackgroundBlack();
	return i;
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
		fflush(stdin);
		temp = getch();
		if (temp == 224)
		{
			temp = getch();
		}

		if (available(temp))
		{
			if (move(temp))
			{
				battle(findEnemy(playerlocaiton));
				if (player->getHP() <= 0)
				{
					gotoxy(0, 0);
					cout << "����� �׾����ϴ�." << endl;
					exit(0);
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
