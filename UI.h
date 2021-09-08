#pragma once

class TextGamePlayer;
class Item;
class Weapon;
class Armor;
class Potion;
class Inventory;

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
	static void showBattle();
	static void showInventory(vector<Weapon> &input);
	static void showInventory(vector<Armor> &input);
	static void showInventory(vector<Potion> &input);
	static void showInventoryIntro();

};

