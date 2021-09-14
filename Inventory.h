#pragma once


class Potion;
class Weapon;
class Armor;
class TextGamePlayer;
class Item;

class Inventory {

	void inventoryApply(TextGamePlayer* player, Item* input);

public:
	Inventory(int input);
	vector<Potion> potionInventory;
	vector<Weapon> weaponInventory;
	vector<Armor> armorInverntory;

	void pushInventory(Potion& push);
	void pushInventory(Weapon& push);
	void pushInventory(Armor& push);
	
	void popPotionInventory(int index);
	void popWeaponInventory(int index);
	void popArmorInventory(int index);

	void open(TextGamePlayer* player);

	void showWeaponInventory();
	void showArmorInventory();
	void showPotionInventory();
};