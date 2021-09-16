#include "stdafx.h"
#include "Smithy.h"
#include "UI.h"
#include "TextGamePlayer.h"
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
#include "Potion.h"


void Smithy::run(TextGamePlayer & player)
{
	while (true)
	{
		UI::showInventoryIntro();
		int temp;
		cin >> temp;
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

		int index;
		cin >> index;
		Item* enhance_item;

		switch (index)
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


	}
}
