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
	bool buyPotion(TextGamePlayer& player);
	bool buyArmor(TextGamePlayer& player);
	bool buyWeapon(TextGamePlayer& player);

	bool buyMode(TextGamePlayer& player);
	bool sellMode(TextGamePlayer& player);
public:
	Store();
	Store(Store& store);
	Weapon* getWeapon();
	Armor* getArmor();
	Potion* getPotion();

	int run(TextGamePlayer& player);
};

