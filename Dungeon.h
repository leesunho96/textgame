#pragma once

class TextGamePlayer;

class Dungeon
{
	vector<TextGamePlayer> Enemy;

public:
	Dungeon(TextGamePlayer &player);

	void showEnemyNum();
};

