#pragma once

class TextGamePlayer;

class Dungeon
{
	vector<TextGamePlayer> EnemyVector;

	void invalidate();

	int maparr[19][14] = { UNLOCK,  };

public:
	Dungeon(TextGamePlayer &player);

	void run();


	void showEnemyNum();
};

