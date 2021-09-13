#pragma once
#include "stdafx.h"
#include "TextGame.h"
#include "TextGamePlayer.h"
#include "UI.h"
#include "Dungeon.h"
#include "Item.h"
#include "Inventory.h"
#include "Store.h";



void TextGame::run()
{
	int temp;
	string sinput;
	TextGamePlayer* player = NULL;


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
			break;
		}
		case 2:
		{
			player->openInventory();
			break;
		}
		case 3:
		{
			Store* store = new Store();
			store->run(*player);
			delete store;
			break;
		}
		case 4:
		{
			exit(0);
		}
		}

	}
}


