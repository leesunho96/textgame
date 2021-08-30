#include "stdafx.h"
#include "Dungeon.h"
#include "UI.h"
#include "TextGamePlayer.h"

void Dungeon::invalidate()
{
	
	UI::showDungeonMap();
	for (size_t i = 0; i < Enemy.size(); i++)
	{
		Enemy.at(i).getLocation().first;
	}
}

Dungeon::Dungeon(TextGamePlayer & player)
{
	TextGamePlayer *tEnemy = NULL;
	srand(time(NULL));
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

	for (size_t i = 0; i < EnemyVector.size(); i++)
	{
		maparr[EnemyVector.at(i).first][EnemyVector.at[i].second] = Enemy;
	}

}

void Dungeon::run()
{
}

void Dungeon::showEnemyNum()
{
	cout << Enemy.size();
}
