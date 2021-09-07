#pragma once

class TextGamePlayer;

class Dungeon
{
	vector<TextGamePlayer> EnemyVector;
	TextGamePlayer* player;
	void invalidate();
	int maparr[19][14];
	pair<int, int> getActorLocation(int i, int j);
	bool move(int iinput);
	bool available(int ichoice);
	bool turn(int index);
	void battle(int index);
	int findEnemy(pair<int, int> Enemylocation);
	pair<int, int> playerlocaiton;
	int moveIcon();



public:
	Dungeon(TextGamePlayer* player);

	void run();


	void showEnemyNum();
};

