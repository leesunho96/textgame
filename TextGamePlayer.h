#pragma once



class Inventory;
class TextGameInfo;
class Weapon;
class Armor;
class Potion;


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
	void initializeAttack();
	void initializeDefense();
	int iMaxHP;

public:

	TextGamePlayer(int i, string sname);
	
	int getAttack();
	int getHP();
	int getMP();
	int getAvoidance();
	int getDefence();
	int getMoney();
	bool useMoney(int money);
	string getName();
	string getJob();
	pair<int, int> getLocation();
	void setlocation(int input);
	bool applydamege(int iAttack);
	int getIendtity();
	void openInventory();


	void pushItem(Weapon input);
	void pushItem(Armor input);
	void pushItem(Potion input);

	void applyItem(Weapon input, int index);
	void applyItem(Potion input, int index);
	void applyItem(Armor input, int index);
};	
