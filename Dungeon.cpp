#include "stdafx.h"
#include "Dungeon.h"
#include "TextGamePlayer.h"

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
			Enemy.push_back(*tEnemy);
			break;
		case 5:
			tEnemy = new TextGamePlayer(itemp, "Goblin");
			Enemy.push_back(*tEnemy);
			break;
		case 6:
			tEnemy = new TextGamePlayer(itemp, "Oak");
			Enemy.push_back(*tEnemy);
			break;
		}
	}

}

void Dungeon::showEnemyNum()
{
	cout << Enemy.size();
}
