#pragma once
#include "stdafx.h"
#include "Inventory.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "UI.h"


Inventory::Inventory(int input)
{
	switch (input)
	{
	case 0:
		for (size_t i = 0; i < 5; i++)
		{
			potionInventory.push_back(*(new Potion()));
		}
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

