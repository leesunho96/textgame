#include "stdafx.h"
#include "TextGame.h"
#include "TextGamePlayer.h"
#include "UI.h"


void TextGame::run()
{
	int temp;
	string sinput;
	TextGamePlayer* player = NULL;


	UI::showStartScreen();
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
	system("cls");
	UI::showStatus(*player);
	UI::showWhattodo();
	cin >> temp;

	

}


