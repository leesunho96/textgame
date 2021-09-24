#pragma once
#include "stdafx.h"
#include "TextGame.h"
#include "TextGamePlayer.h"
#include "UI.h"
#include "Dungeon.h"
#include "Item.h"
#include "Inventory.h"
#include "Store.h"
#include "Smithy.h"



void TextGame::run()
{
	int temp;
	string sinput;
	TextGamePlayer* player = NULL;
	Store* store = nullptr;
	bool isclear = true;

	UI::showStartScreen();
	getchar();
	while (true)
	{
		UI::showChooseJob();
		cin >> temp;
		if (temp < 4 && temp > 0)
		{
			break;
		}
	}
	UI::chooseName();
	cin >> sinput;
	player = new TextGamePlayer(temp, sinput);
	while (true)
	{
		system("cls");
		UI::showStatus(*player);
		UI::showWhattodo();
		cin >> temp;

		switch (temp)
		{
		case 1:
		{
			Dungeon* dungeon = new Dungeon(player);
			(*dungeon).run();
			isclear = true;
			break;
		}
		case 2:
		{
			player->openInventory();
			break;
		}
		case 3:
		{
			if (isclear)
			{
				if (store != nullptr)
				{
					delete store;
				}
				store = new Store();
				isclear = false;
			}
			store->run(*player);
			break;
		}
		case 4:
		{
			Smithy smithy;
			smithy.run(*player);
			break;
		}
		case 5:
			UI::showEquipment(*player);
			break;

		case 6:
			exit(0);
		}

	}
}


