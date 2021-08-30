#pragma once

class TextGamePlayer;

class Dungeon
{
	vector<TextGamePlayer> EnemyVector;
	TextGamePlayer* player;
	void invalidate();
	int maparr[19][14];
	pair<int, int> getActorLocation(int i, int j);
	void move();
	bool available(int ichoice);
public:
	Dungeon(TextGamePlayer* player);

	void run();


	void showEnemyNum();
};

