#include "stdafx.h"
#include "Store.h"
#include "TextGamePlayer.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "UI.h"

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
	if (player.getMoney() > cost && potion != nullptr)
	{
		player.pushItem(*potion);
		delete potion;
		potion = nullptr;
		return true;
	}

	return false;
}

bool Store::buyArmor(TextGamePlayer &player)
{
	if (player.getMoney() > cost && armor != nullptr)
	{
		player.pushItem(*armor);
		delete armor;
		armor = nullptr;
		return true;
	}
	return false;
}

bool Store::buyWeapon(TextGamePlayer &player)
{

	if (player.getMoney() > cost && weapon != nullptr)
	{
		player.pushItem(*weapon);

		delete weapon;
		weapon = nullptr;
		return true;
	}
	return false;
}

bool Store::buyMode(TextGamePlayer & player)
{

	return false;
}

bool Store::sellMode(TextGamePlayer & player)
{
	
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



int Store::run(TextGamePlayer & player)
{
	while (true)
	{
		UI::showStore(*this);
		UI::WriteText();
		cout << "무엇을 할까요? " << endl;
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			UI::WriteText();
			cout << "무엇을 살까요?" << endl;
			UI::movecursor();
			cout << "                   ";
			UI::movecursor();
			int temp2;
			cin >> temp2;
			if (temp2 == 1)
				buyWeapon(player);
			else if (temp2 == 2)
				buyArmor(player);
			else if (temp2 = 3)
				buyPotion(player);
			else
				continue;
			break;
		case 2:
			system("cls");
			UI::showInventoryIntro();
			cin >> temp;
			if (temp == 1)
			{
				player.showWeaponInventory();
			}
			else if (temp == 2)
			{
				player.showArmorInventory();
			}
			else if (temp = 3)
			{
				player.showPotionInventory();
			}
			else
				continue;

			UI::WriteText();
			cout << "어떤 아이템을 팔까요?" << endl;
			int index;
			cin >> index;

			if (temp == 1)
			{
				player.showWeaponInventory();
			}
			else if (temp == 2)
			{
				player.showArmorInventory();
			}
			else if (temp = 3)
			{
				player.showPotionInventory();
			}
			else
				continue;
			break;
		case 3:
			return 0;
		default:
			return 0;
		}
	}
}
