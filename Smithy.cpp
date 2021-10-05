#include "stdafx.h"
#include "Smithy.h"
#include "UI.h"
#include "TextGamePlayer.h"
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
#include "Potion.h"

// �ε��� ������ ������ false , ������ true ��ȯ. 1 : Weapon, 2 : Armor, 3 : Potion
bool Smithy::indexcheck(int type, Item* checkingItem)
{
	switch (type)
	{
	case 1:
	{
		Weapon temp = Weapon();
		if (*(Weapon*)(checkingItem) == temp)
		{
			return true;
		}
		return false;
	}
	case 2:
	{
		Armor temp = Armor();
		if (*(Armor*)(checkingItem) == temp)
		{
			return true;
		}
		return false; 
	}
	case 3:
	{
		Potion temp = Potion(0);
		if (*(Potion*)(checkingItem) == temp)
		{
			return true;
		}
		return false;
	}
	}
}

Smithy::~Smithy()
{
	if (enhance_item != nullptr)
	{
		delete enhance_item;
		enhance_item = nullptr;
	}
	if (sacrificed_Item != nullptr)
	{
		delete sacrificed_Item;
		sacrificed_Item = nullptr;
	}
}

bool Smithy::run(TextGamePlayer & player)
{
	// ��ȭ�� ����
	while (true)
	{
		system("cls");
		UI::showSmithyIntro();
		int temp;

		cin >> temp;
		if (temp == -1)
		{
			break;
		}
		if (temp < 1 || temp > 2)
		{
			cout << "���� ���� ���� �Է����ּ���." << endl;
			continue;
		}

		switch (temp)
		{
		case 1:
			player.showWeaponInventory();
			break;
		case 2:
			player.showArmorInventory();
			break;

		default:
			continue;
		}

		int index;
		cin >> index;

		switch (temp)
		{
		case 1:
			enhance_item = new Weapon(player.getWeapon(index));
			if (indexcheck(1, enhance_item))
			{
				UI::showIndexErrorMessage();
				return false;
			}
			break;
		case 2:
			enhance_item = new Armor(player.getArmor(index));
			if (indexcheck(2, enhance_item))
			{
				UI::showIndexErrorMessage();
				return false;
			}
			break;
		default:
			return false;
		}


		{
			int retflag;
			bool retval = isSacrificeItemExist(temp, player, retflag);
			if (retflag == 3)
			{
				system("cls");
				gotoxy(0, 0);
				cout << "������ ���� �������� �����ϴ�." << endl;
				touch();
				continue;
			}
			if (retflag == 1) return retval;
		}



		gotoxy(0, 29);
		cout << "������ ������.                              " << endl;
		cin >> index;

		switch (temp)
		{
		case 1:
			sacrificed_Item = new Weapon(player.getWeapon(index));
			if (indexcheck(1, enhance_item))
			{
				UI::showIndexErrorMessage();
				player.pushItem(*(Weapon*)enhance_item);
				return false;
			}
			break;
		case 2:
			sacrificed_Item = new Armor(player.getArmor(index));
			if (indexcheck(2, enhance_item))
			{
				UI::showIndexErrorMessage();
				player.pushItem(*(Armor*)enhance_item);
				return false;
			}
			break;
;
		default:
			return false;
		}

		if (enhance_item->enhance())
		{
			switch (temp)
			{
			case 1:
				player.pushItem(*(Weapon*)enhance_item);
				break;
			case 2:
				player.pushItem(*(Armor*)enhance_item);
				break;
			default:
				return false;
			}
			system("cls");
			gotoxy(0, 0);
			cout << "��ȭ�� �����߽��ϴ�" << endl;
		}
		else
		{
			system("cls");
			gotoxy(0, 0);
			cout << "��ȭ�� �����߽��ϴ�" << endl;
		}

		fflush(stdin);
		_getch();
	}
	return true;
}

bool Smithy::isSacrificeItemExist(int temp, TextGamePlayer & player, int &retflag)
{
	retflag = 1;
	int presentInvensize = 0;
	switch (temp)
	{
	case 1:
		player.showWeaponInventory();
		presentInvensize = player.getWeaponInvenSize();
		break;
	case 2:
		player.showArmorInventory();
		presentInvensize = player.getArmorInvenSize();
		break;
	case 3:
		player.showPotionInventory();
		presentInvensize = player.getPotionInvenSize();
		break;
	default:
		return false;
	}

	if (presentInvensize == 0)
	{

		switch (temp)
		{
		case 1:
			player.pushItem(*(Weapon*)enhance_item);
			break;
		case 2:
			player.pushItem(*(Armor*)enhance_item);
			break;
		case 3:
			player.pushItem(*(Potion*)enhance_item);
			break;
		}
		{ retflag = 3; return {}; };
	}
	retflag = 0;
	return {};
}
