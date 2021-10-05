#pragma once

class Inventory;
class TextGameInfo;
class Weapon;
class Armor;
class Potion;


struct baseStat
{
public:
	int iHP;
	int iAttack;
	int iMP;
	int iDefence;
	int iAvoidnce;
	baseStat()
	{
		this->iHP = 0;
		this->iAttack = 0;
		this->iMP = 0;
		this->iDefence = 0;
		this->iAvoidnce = 0;
	}
	baseStat(int iHP, int iAttack, int iMP, int iDefence, int iAvoidance)
	{
		this->iHP = iHP;
		this->iAttack = iAttack;
		this->iMP = iMP;
		this->iDefence = iDefence;
		this->iAvoidnce = iAvoidance;
	}
	void levelUP()
	{
		iHP += 10;
		iAttack += 5;
		iMP += 5;
		iDefence += 5;
		iAvoidnce += 3;
	}
};

class TextGamePlayer
{
	int ilevel;
	int iMaxExp;
	int iPresentExp;
	int iAttack;
	int iMaxHP;
	int iHp;
	int iMp;
	int iAvoidance;
	int iDefence;
	int iWeight;
	string sName;
	string sjob;
	int iMoney = 500;
	pair<int, int> location;
	int identity;
	Inventory *playerInventory;
	Weapon *applyWeapon = nullptr;
	Armor *applyArmor = nullptr;
	static vector<pair<int, int>> enemylocationlist;
	void initializeAttack();
	void initializeDefense();
	baseStat characterBaseStat;
	void initializeHP();
	
public:

	TextGamePlayer(int i, string sname);
	TextGamePlayer(int i, string sname, pair<int, int>location);
	
	
	int getAttack();
	int getHP();
	int getMP();
	int getAvoidance();
	int getDefence();
	int getMoney();

	int getWeaponInvenSize();
	int getArmorInvenSize();
	int getPotionInvenSize();


	bool useMoney(int money);
	string getName();
	string getJob();
	pair<int, int> getLocation();
	void setlocation(int input);
	bool applydamege(int iAttack);
	int getIendtity();
	void openInventory();

	void showWeaponInventory();
	void showArmorInventory();
	void showPotionInventory();

	void pushItem(Weapon input);
	void pushItem(Armor input);
	void pushItem(Potion input);
	void pushMoney(int input);

	void applyItem(Weapon input, int index);
	void applyItem(Potion input, int index);
	void applyItem(Armor input, int index);

	Armor getArmor(int index);
	Armor getArmor();
	Weapon getWeapon(int index);
	Weapon getWeapon();
	Potion getPotion(int index);

	void getEXP();
	void levelUP();

	int getWeight();
	int getLevel();
	void getItem();
};	
