#pragma once

class Inventory;

class TextGamePlayer
{
	int iAttack;
	int iHp;
	int iMp;
	int iAvoidance;
	int iDefence;
	string sName;
	string sjob;
	int iMoney = 0;
	pair<int, int> location;
	int identity;
	Inventory *playerInventory;

public:

	TextGamePlayer(int i, string sname);

	int getAttack();
	int getHP();
	int getMP();
	int getAvoidance();
	int getDefence();
	string getName();
	string getJob();
	pair<int, int> getLocation();
	void setlocation(int input);
	bool applydamege(int iAttack);
	int getIendtity();
	Inventory* getInventory();

};

