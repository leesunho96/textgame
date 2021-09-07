#pragma once

class TextGameInfo;
class Potion;
class Weapon;
class Armor;

class Inventory {

public:
	Inventory(int input);
	vector<Potion> potionInventory;
	vector<Weapon> weaponInventory;
	vector<Armor> armorInverntory;
	void showInven();
};