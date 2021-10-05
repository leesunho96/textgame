#pragma once

class TextGamePlayer;
class Item;
class Weapon;
class Armor;
class Potion;
class Inventory;
class Store;

class UI
{

public:

	static void WriteText();
	static void movecursor();
	static void showStartScreen();
	static void showChooseJob();
	static void chooseName();
	static void showStatus(TextGamePlayer &p);
	static void showEquipment(TextGamePlayer &p);
	static void showWhattodo();
	static void showWareHouseWhattodo();
	static void showDungeonMap();
	static void showBattleMap(vector<int> pattern);
	static void showBattle();

	static void showInventory(vector<Weapon> &input);
	static void showInventory(vector<Armor> &input);
	static void showInventory(vector<Potion> &input);
	static void showWareHouse(vector<Item*> &input);

	static void showInventoryWhattodo();

	static void showInventoryIntro();
	static void showSmithyIntro();
	static void showStore(Store& store);


	static void showIndexErrorMessage();
	static void outofrangeErrorMessage();
};

