#include "stdafx.h"
#include "Store.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "TextGamePlayer.h"

Store::Store()
{
	weapon = new Weapon(rand() % 6 + 1);
	armor = new Armor(rand() % 6 + 1);
	potion = new Potion();
}

Store::Store(Store & store)
{
	this->weapon = new Weapon(*(store.weapon));
	this->potion = new Potion(*(store.potion));
	this->armor = new Armor(*(store.armor));
}

bool Store::buyPotion(TextGamePlayer &player)
{
	if (player.getMoney() > cost)
	{
		player.getInventory().pushInventory(*potion);
		delete potion;
		potion = nullptr;
		return true;
	}

	return false;
}

bool Store::buyArmor(TextGamePlayer &player)
{
	if (player.getMoney() > cost)
	{
		*(player.getInventory).pushInventory(*armor);
		delete armor;
		armor = nullptr;
		return true;
	}
	return false;
}

bool Store::buyWeapon(TextGamePlayer &player)
{

	if (player.getMoney() > cost)
	{
		*(player.getInventory).pushInventory(*weapon);
		delete weapon;
		weapon = nullptr;
		return true;
	}
	return false;
}

Weapon* Store::getWeapon()
{

	return weapon;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

Armor * Store::getArmor()
{
	return armor;
}

Potion * Store::getPotion()
{
	return potion;
}
