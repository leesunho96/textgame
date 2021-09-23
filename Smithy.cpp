#include "stdafx.h"
#include "Smithy.h"
#include "UI.h"
#include "TextGamePlayer.h"
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
#include "Potion.h"


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

void Smithy::run(TextGamePlayer & player)
{	
	// 강화할 종류
	while (true)
	{
		system("cls");
		UI::showInventoryIntro();
		int temp;

		cin >> temp;
		if (temp == -1)
		{
			break;
		}
		if (temp < 1 || temp > 3)
		{
			cout << "범위 내의 수를 입력해주세요." << endl;
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
		case 3:
			player.showPotionInventory();
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
			break;
		case 2:
			enhance_item = new Armor(player.getArmor(index));
			break;
		case 3:
			enhance_item = new Potion(player.getPotion(index));
			break;
		default:
			return;
		}

		switch (temp)
		{
		case 1:
			player.showWeaponInventory();
			break;
		case 2:
			player.showArmorInventory();
			break;
		case 3:
			player.showPotionInventory();
			break;
		default:
			return;
		}

		gotoxy(0, 29);
		cout << "제물을 고르세요.                              " << endl;
		cin >> index;

		switch (temp)
		{
		case 1:
			sacrificed_Item = new Weapon(player.getWeapon(index));
			break;
		case 2:
			sacrificed_Item = new Armor(player.getArmor(index));
			break;
		case 3:
			sacrificed_Item = new Potion(player.getPotion(index));
			break;
		default:
			return;
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
			case 3:
				player.pushItem(*(Potion*)enhance_item);
				break;
			default:
				return;
			}
			system("cls");
			gotoxy(0, 0);
			cout << "강화를 성공했습니다" << endl;
		}
		else
		{
			system("cls");
			gotoxy(0, 0);
			cout << "강화를 실패했습니다" << endl;
		}

		fflush(stdin);
		_getch();
	}
}
