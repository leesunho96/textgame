#pragma once
#include "stdafx.h"
#include "TextGamePlayer.h"
#include "UI.h"
#include "TextGameInfo.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Store.h"

///△  ◁  ▷ ▽ ★ | ■



void UI::WriteText()
{
	gotoxy(0, 29);
}

void UI::movecursor()
{
	gotoxy(0, 30);
}
void UI::showStartScreen()
{
	system("cls");
	gotoxy(50, 10);
	cout << "TextGame" << endl;
	gotoxy(49, 15);
	cout << "Made by LSH" << endl;
	gotoxy(50, 20);
	cout << "GAME START" << endl;
	gotoxy(45, 22);
	cout << "press any button to start" << endl;
	movecursor();

}

void UI::showStatus(TextGamePlayer &p)
{
	if (p.getIendtity() == PLAYER)
	{
		gotoxy(80, 22);
		cout << "==========================" << endl;
		gotoxy(80, 23);
		cout << "Name : " << p.getName() << endl;
		gotoxy(80, 24);
		cout << "Job :" << p.getJob() << endl;
		gotoxy(80, 25);
		cout << "HP : " << p.getHP() << endl;
		gotoxy(80, 26);
		cout << "MP : " << p.getMP() << endl;
		gotoxy(80, 27);
		cout << "Attack : " << p.getAttack() << endl;
		gotoxy(80, 28);
		cout << "Defence : " << p.getDefence() << endl;
		gotoxy(80, 29);
		cout << "Weight : " << p.getWeight();
		gotoxy(80, 30);
		cout << "==========================" << endl;
		movecursor();
	}
	else
	{
		gotoxy(0, 22);
		cout << "==========================" << endl;
		gotoxy(0, 23);
		cout << "Name : " << p.getName() << endl;
		gotoxy(0, 24);
		cout << "Job :" << p.getJob() << endl;
		gotoxy(0, 25);
		cout << "HP : " << p.getHP() << endl;
		gotoxy(0, 26);
		cout << "MP : " << p.getMP() << endl;
		gotoxy(0, 27);
		cout << "Attack : " << p.getAttack() << endl;
		gotoxy(0, 28);
		cout << "Defence : " << p.getDefence() << endl;
		gotoxy(0, 29);
		cout << "Weight : " << p.getWeight();
		gotoxy(0, 30);
		cout << "==========================" << endl;
		movecursor();
	}
}

void UI::showWhattodo()
{
	gotoxy(50, 10);
	cout << "What to do?" << endl;
	gotoxy(50, 11);
	cout << "1. Go to Dungeon" << endl;
	gotoxy(50, 12);
	cout << "2. Open Inventory" << endl;
	gotoxy(50, 13);
	cout << "3. Go to Store" << endl;
	gotoxy(50, 14);
	cout << "4. GO to Smithy" << endl;
	gotoxy(50, 15);
	cout << "4. Exit Game" << endl;
	movecursor();

}

void UI::showDungeonMap()
{
	gotoxy(20, 5);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	gotoxy(98, 5);
	cout << "■";
	gotoxy(20, 6);
	cout << "■" << endl;
	gotoxy(98, 6);
	cout << "■" << endl;
	gotoxy(20, 7);
	cout << "■" << endl;
	gotoxy(98, 7);
	cout << "■" << endl;
	gotoxy(20, 8);
	cout << "■" << endl;
	gotoxy(98, 8);
	cout << "■" << endl;
	gotoxy(20, 9);
	cout << "■" << endl;
	gotoxy(98, 9);
	cout << "■" << endl;
	gotoxy(20, 10);
	cout << "■" << endl;
	gotoxy(98, 10);
	cout << "■" << endl;
	gotoxy(20, 11);
	cout << "■" << endl;
	gotoxy(98, 11);
	cout << "■" << endl;
	gotoxy(20, 12);
	cout << "■" << endl;
	gotoxy(98, 12);
	cout << "■" << endl;
	gotoxy(20, 13);
	cout << "■" << endl;
	gotoxy(98, 13);
	cout << "■" << endl;
	gotoxy(20, 14);
	cout << "■" << endl;
	gotoxy(98, 14);
	cout << "■" << endl;
	gotoxy(20, 15);
	cout << "■" << endl;
	gotoxy(98, 15);
	cout << "■" << endl;
	gotoxy(20, 16);
	cout << "■" << endl;
	gotoxy(98, 16);
	cout << "■" << endl;
	gotoxy(20, 17);
	cout << "■" << endl;
	gotoxy(98, 17);
	cout << "■" << endl;
	gotoxy(20, 18);
	cout << "■" << endl;
	gotoxy(98, 18);
	cout << "■" << endl;
	gotoxy(20, 19);
	cout << "■" << endl;
	gotoxy(98, 19);
	cout << "■" << endl;
	gotoxy(20, 20);
	cout << "■" ;
	gotoxy(26, 20);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	gotoxy(0, 21);
	cout << "Press Space bar While green bar is in Right Place" << endl;
	cout << "move with Directional Key" << endl;
	cout << "Press \"I\" if you want to open Inventory" << endl;
	movecursor();
}

void UI::showBattleMap(vector<int> pattern)
{
	//△  ◁  ▷ ▽
	for (size_t i = 1; i <= pattern.size(); i++)
	{
		gotoxy(10 * i, 20);
		switch (pattern.at(pattern.size() - 1))
		{
		case UP:
			cout << "△";
			break;
		case DOWN:
			cout << "▽";
			break;
		case RIGHT:
			cout << "◁";
			break;
		case LEFT:
			cout << "▷";
			break;
		}
		pattern.pop_back();

	}

}

void UI::showBattle()
{
	setBackgroundGray();
	gotoxy(10, 10);
	cout << "                                                                                                       ";
	gotoxy(10, 11);
	cout << "                                                                                                       ";
	gotoxy(10, 12);
	cout << "                                                                                                       ";
	gotoxy(10, 13);
	cout << "                                                                                                       ";
	gotoxy(10, 14);
	cout << "                                                                                                       ";
	gotoxy(10, 15);
	cout << "                                                                                                       ";
	setBackgroundGreen();
	gotoxy(55, 10);
	cout << "      ";
	gotoxy(55, 11);
	cout << "      ";
	gotoxy(55, 12);
	cout << "      ";
	gotoxy(55, 13);
	cout << "      ";
	gotoxy(55, 14);
	cout << "      ";
	gotoxy(55, 15);
	cout << "      ";
	setBackgroundBlack();
}

void UI::showInventory(vector<Weapon>& input)
{
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "무기 LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "타입 : " << temp.getType() << endl;
		cout << "이름 : " << temp.getName() << endl;
		cout << "효과 : " << temp.getEffect() << endl;
 	}
	cout << "==========================="<< endl;

	gotoxy(0, 29);
	cout << "아이템을 선택하세요." << endl;
}

void UI::showInventory(vector<Armor>& input)
{
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "방어구 LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "타입 : " << temp.getType() << endl;
		cout << "이름 : " << temp.getName() << endl;
		cout << "효과 : " << temp.getEffect() << endl;
 	}
	cout << "===========================" << endl;
	gotoxy(0, 29);
	cout << "아이템을 선택하세요." << endl;
}

void UI::showInventory(vector<Potion>& input)
{
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "포션 LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "이름 : " << temp.getName() << endl;
		cout << "효과 : " << temp.getEffect() << endl;
 	}
	cout << "===========================" << endl;
	gotoxy(0, 20);
	cout << "아이템을 선택하세요." << endl;
}

void UI::showInventoryWhattodo()
{
	system("cls");
	gotoxy(50, 5);
	cout << "===========================" << endl;
	gotoxy(50, 6);
	cout << "무엇을 할까요?" << endl;
	gotoxy(50, 7);
	cout << "1. 사용하기" << endl;
	gotoxy(50, 8);
	cout << "2. 파기하기" << endl;
	gotoxy(50, 9);
	cout << "-1 : 돌아가기" << endl;
	gotoxy(50, 10);
	cout << "===========================" << endl;
	movecursor();
}

void UI::showInventoryIntro()
{
	gotoxy(50, 5);
	cout << "===========================" << endl;
	gotoxy(50, 6);
	cout << "어떤 인벤토리를 열까요?" << endl;
	gotoxy(50, 7);
	cout << "1. 무기 인벤토리" << endl;
	gotoxy(50, 8);
	cout << "2. 방어구 인벤토리" << endl;
	gotoxy(50, 9);
	cout << "3. 포션 인벤토리" << endl;
	gotoxy(50, 10);
	cout << "-1 : 돌아가기" << endl;
	gotoxy(50, 11);
	cout << "===========================" << endl;
}

void UI::showStore(Store & store)
{
	system("cls");
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "1. 무기 ";
	if (store.getWeapon() != nullptr) cout << "이름 : " << store.getWeapon()->getName() << " 공격력 : " << store.getWeapon()->getEffect() << endl;
	else cout << "팔림" << endl;
	cout << "2. 방어구 ";
	if (store.getArmor() != nullptr) cout << "이름 : " << store.getArmor()->getName() << " 방어력 : " << store.getArmor()->getEffect() << ", 회피력 : " << store.getArmor()->getAvoidance() << endl;
	else cout << "팔림" << endl;
	cout << "3. 포션 ";
	if (store.getPotion() != nullptr) cout << "이름 : " << store.getPotion()->getName() << " 회복력 : " << store.getPotion()->getEffect() << endl;
	else cout << "팔림" << endl;
	cout << "===========================" << endl;
	cout << "1. 구매하기" << endl;
	cout << "2. 판매하기" << endl;
	cout << "3. 돌아가기" << endl;
	cout << "===========================" << endl;

}








void UI::showChooseJob()
{
	system("cls");
	gotoxy(50, 10);
	cout << "choose your jobs" << endl;
	gotoxy(50, 12);
	cout << "1. Worrier" << endl;
	gotoxy(50, 14);
	cout << "2. Rogue" << endl;
	gotoxy(50, 16);
	cout << "3. Mage" << endl;
	movecursor();
}

void UI::chooseName()
{
	system("cls");
	gotoxy(50, 10);
	cout << "Write Your Name" << endl;
	movecursor();
}



