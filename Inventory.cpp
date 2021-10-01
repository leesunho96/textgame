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
			potionInventory.push_back(Potion());
		}

		weaponInventory.push_back(Weapon(rand() % 6 + 1));
		weaponInventory.push_back(Weapon(rand() % 6 + 1));
		armorInverntory.push_back(Armor(rand() % 2 + 1));
		armorInverntory.push_back(Armor(rand() % 2 + 1));



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
			weaponInventory.push_back(Weapon(input));
			break;
		case 7:
		case 8:
			armorInverntory.push_back(Armor(input % 6));
			break;
		case 9:
			potionInventory.push_back(Potion());
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
	popInventory(potionInventory, index);
}

void Inventory::popWeaponInventory(int index)
{
	popInventory(weaponInventory, index);
}

void Inventory::popArmorInventory(int index)
{
	popInventory(armorInverntory, index);
}

Potion Inventory::getPotion(int index)
{	
	Potion temp = getItem(potionInventory, index);
	return temp == Potion(0) ? temp : Potion(0);
}

Weapon Inventory::getWeapon(int index)
{
	return getItem(weaponInventory, index);
}

Armor Inventory::getArmor(int index)
{
	return getItem(armorInverntory, index);
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



