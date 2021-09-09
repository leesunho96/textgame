#pragma once

class Weapon;
class Armor;
class Potion;
class TextGamePlayer;


class Store
{
	Weapon* weapon = nullptr;
	Armor* armor = nullptr;
	Potion* potion = nullptr;
	int cost = 100;
public:
	Store();
	Store(Store& store);
	bool buyPotion(TextGamePlayer& player);
	bool buyArmor(TextGamePlayer& player);
	bool buyWeapon(TextGamePlayer& player);
	Weapon* getWeapon();
	Armor* getArmor();
	Potion* getPotion();
};

