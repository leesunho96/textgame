#pragma once
#include "stdafx.h"
#include "TextGamePlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "UI.h"

#define BREAK 98
#define CONTINUE 99

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

void Inventory::pushWareHouse(Item* push)
{
	if (push->getName() == "HeavyArmor" || push->getName() == "LightArmor")
	{
		Armor* temp = new Armor(*(Armor*)push);
		wareHouse.push_back((Item*)temp);
	}
	else if (push->getName() == "포션")
	{
		Potion* temp = new Potion(*(Potion*)push);
		wareHouse.push_back((Item*)temp);
	}
	else
	{
		Weapon* temp = new Weapon(*(Weapon*)push);
		wareHouse.push_back((Item*)temp);
	}
	
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

bool Inventory::popWareHouse(int index)
{
	if (index - 1 < wareHouse.size())
	{
		wareHouse.erase(begin(wareHouse) + index - 1);
		return true;
	}
	else
	{
		UI::outofrangeErrorMessage();
		return false;
	}

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

Item* Inventory::getWareHouse(int index)
{
	return getItem(wareHouse, index);
}



void Inventory::open(TextGamePlayer* player)
{

	system("cls");
	while (true)
	{		
		int retflag1 = 0;
		int invensize = chooseInventory(retflag1);
		if (retflag1 == BREAK) break;
		if (retflag1 == CONTINUE) continue;

		int retflag2 = 0;
		if (retflag1 == 4)
		{
			openWareHouse(invensize, player, retflag2);
		}
		else
		{
			chooseWhattodo(invensize, retflag1, player, retflag2);
		}
		
		if (retflag2 == 3) continue;
	}
}

void Inventory::chooseWhattodo(int invensize, int whattodo, TextGamePlayer * player, int &retflag)
{
	retflag = 1;
	int index;
	cin >> index;
	if (index <= 0 || index > invensize)
	{
		retflag = 3; return;
	};
	UI::showInventoryWhattodo();
	int choice;
	cin >> choice;
	// temp = inven 선택, index : 해당 인벤에서의 index, choice = 사용/파기/인벤에 넣기/돌아가기
	if (whattodo == 1)
	{
		if (choice == 1)
			player->applyItem(weaponInventory[index - 1], index);
		else if (choice == 2)
			popWeaponInventory(index);
		else if (choice == 3)
		{
			Weapon* temp = new Weapon(weaponInventory[index - 1]);
			wareHouse.push_back((Item*)temp);
			popWeaponInventory(index);
		}
		else
		{
			retflag = CONTINUE; return;
		};
	}
	else if (whattodo == 2)
	{
		if (choice == 1)
			player->applyItem(armorInverntory[index - 1], index);
		else if (choice == 2)
			popArmorInventory(index);
		else if (choice == 3)
		{
			Armor* temp = new Armor(armorInverntory[index - 1]);
			wareHouse.push_back((Item*)temp);
			popArmorInventory(index);
		}
		else
		{
			retflag = CONTINUE; return;
		};
	}
	else if (whattodo == 3)
	{
		if (choice == 1)
			player->applyItem(potionInventory[index - 1], index);
		else if (choice == 2)
			popPotionInventory(index);
		else if (choice == 3)
		{
			Potion* temp = new Potion(potionInventory[index - 1]);
			wareHouse.push_back((Item*)temp);
			popPotionInventory(index);
		}
		else
		{
			retflag = CONTINUE; return;
		};
	}
}

int Inventory::chooseInventory(int &retflag)
{
	retflag = 1;
	system("cls");
	UI::showInventoryIntro();
	int temp, index;
	int invensize;
	UI::movecursor();
	cin >> temp;
	system("cls");
	if (temp == -1)
	{
		retflag = BREAK; return 0;
	};
	retflag = temp;
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
	case 4:
		UI::showWareHouse(wareHouse);
		invensize = wareHouse.size();
		retflag = 4;
		return invensize;
		break;
	default:
	{ retflag = temp; return invensize; };
	}
}

void Inventory::openWareHouse(int invensize, TextGamePlayer * player, int & retflag)
{
	retflag = 1;
	int index;
	// index
	cin >> index;
	if (index <= 0 || index > invensize)
	{
		retflag = 3; return;
	};
	UI::showWareHouseWhattodo();
	int choice;
	fflush(stdin);
	cin >> choice;

	switch (choice)
	{
	case 1:
	{// 인벤토리로 돌려놓기
		Item* temp = getWareHouse(index);
		if(popWareHouse(index))
		{
			if (temp->getName() == "포션")
			{
				potionInventory.push_back(*(Potion*)temp);
			}
			else if (temp->getName() == "HeavyArmor" || temp->getName() == "LightArmor")
			{
				armorInverntory.push_back(*(Armor*)temp);
			}
			else
			{
				weaponInventory.push_back(*(Weapon*)temp);
			}
			delete temp; 
		}
		break;
	}
	case 2:
	{// 파기
		Item* temp = getWareHouse(index);
		if (popWareHouse(index))
		{
			delete temp; 
		}
		break;
	}
	case 3:
		return;
	}
	// temp = inven 선택, index : 해당 인벤에서의 index, choice = 사용/파기/돌아가기


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

void Inventory::showWareHouse()
{
}




