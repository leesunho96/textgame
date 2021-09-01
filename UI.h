#pragma once
class UI
{

	static void movecursor();
public:

	static void showStartScreen();
	static void showChooseJob();
	static void chooseName();
	static void showStatus(TextGamePlayer &p);
	static void showWhattodo();
	static void showDungeonMap();
	static void showBattleMap(vector<int> pattern);

};

