#pragma once
#include "stdafx.h"
#include "TextGamePlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "UI.h"


void Inventory::inventoryApply(TextGamePlayer* player, Item* item)
{
	int temp;
	UI::showInventoryWhattodo();
	cin >> temp;
}

Inventory::Inventory(int input)
{
	switch (input)
	{
	case 0:
		for (size_t i = 0; i < 5; i++)
		{
			potionInventory.push_back(*(new Potion()));
		}

		weaponInventory.push_back(*(new Weapon(rand() % 6 + 1)));
		weaponInventory.push_back(*(new Weapon(rand() % 6 + 1)));
		armorInverntory.push_back(*(new Armor(rand() % 2 + 1)));
		armorInverntory.push_back(*(new Armor(rand() % 2 + 1)));



		break;
	case 1:
		int input = rand() % 9;
		
		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			weaponInventory.push_back(*(new Weapon(input)));
			break;
		case 7:
		case 8:
			armorInverntory.push_back(*(new Armor(input % 6)));
			break;
		case 9:
			potionInventory.push_back(*(new Potion()));
			break;
		}
	}
}

void Inventory::pushInventory(Potion & push)
{
	potionInventory.push_back(push);
}

void Inventory::pushInventory(Weapon & push)
{
	weaponInventory.push_back(push);
}

void Inventory::pushInventory(Armor & push)
{
	armorInverntory.push_back(push);
}

void Inventory::popPotionInventory(int index)
{
	potionInventory.erase(begin(potionInventory) + index - 1);
}

void Inventory::popWeaponInventory(int index)
{
	weaponInventory.erase(begin(weaponInventory) + index - 1);
}

void Inventory::popArmorInventory(int index)
{
	armorInverntory.erase(begin(armorInverntory) + index - 1);
}

Potion Inventory::getPotion(int index)
{
	
	try {

		if (index - 1 < potionInventory.size())
		{
			return potionInventory.at(index - 1);
		}
		else
		{
			throw out_of_range("orr");
		}
	}
	catch (std::out_of_range& oor)
	{
		return Potion(0);
	}
	//return Potion(0);
}

Weapon Inventory::getWeapon(int index)
{
	try {
		if (index - 1 < weaponInventory.size())
		{
			return weaponInventory.at(index - 1);
		}
		else
		{
			throw out_of_range("orr");
		}
	}
	catch (std::out_of_range& oor)
	{
		return Weapon();
	}
	return Weapon();
}

Armor Inventory::getArmor(int index)
{
	try {
		if (index - 1 < armorInverntory.size())
		{
			return armorInverntory.at(index - 1);
		}
		else
		{
			throw out_of_range("orr");
		}
	}
	catch (std::out_of_range& oor)
	{
		return Armor();
	}	
}

void Inventory::open(TextGamePlayer* player)
{

	system("cls");
	while (true)
	{
		system("cls");
		UI::showInventoryIntro();
		int temp, index;
		int invensize;
		UI::movecursor();
		cin >> temp;
		system("cls");
		if (temp == -1)
			break;
		switch (temp)
		{
		case 1:
			UI::showInventory(weaponInventory);
			invensize = weaponInventory.size();
			break;
		case 2:
			UI::showInventory(armorInverntory);
			invensize = armorInverntory.size();
			break;
		case 3:
			UI::showInventory(potionInventory);
			invensize = potionInventory.size();
			break;
		default:
			continue;
		}
		cin >> index;
		if (index <= 0 || index > invensize)
			continue;
		UI::showInventoryWhattodo();
		int choice;
		cin >> choice;
		// temp = inven 선택, index : 해당 인벤에서의 index, choice = 사용/파기/돌아가기
		if (temp == 1)
		{
			if (choice == 1)
				player->applyItem(weaponInventory[index - 1], index);
			else if (choice == 2)
				popWeaponInventory(index);
			else
				continue;
		}
		else if (temp == 2)
		{
			if (choice == 1)
				player->applyItem(armorInverntory[index - 1], index);
			else if (choice == 2)
				popArmorInventory(index);
			else
				continue;
		}
		else if (temp == 3)
		{
			if (choice == 1)
				player->applyItem(potionInventory[index - 1], index);
			else if (choice == 2)
				popPotionInventory(index);
			else
				continue;
		}


		

	}
}

void Inventory::showWeaponInventory()
{
	UI::showInventory(weaponInventory);
}

void Inventory::showArmorInventory()
{
	UI::showInventory(armorInverntory);
}

void Inventory::showPotionInventory()
{
	UI::showInventory(potionInventory);
}



