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

///��  ��  �� �� �� | ��



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
	cout << "4. Exit Game" << endl;
	movecursor();

}

void UI::showDungeonMap()
{
	gotoxy(20, 5);
	cout << "��������������������������������������" << endl;
	gotoxy(98, 5);
	cout << "��";
	gotoxy(20, 6);
	cout << "��" << endl;
	gotoxy(98, 6);
	cout << "��" << endl;
	gotoxy(20, 7);
	cout << "��" << endl;
	gotoxy(98, 7);
	cout << "��" << endl;
	gotoxy(20, 8);
	cout << "��" << endl;
	gotoxy(98, 8);
	cout << "��" << endl;
	gotoxy(20, 9);
	cout << "��" << endl;
	gotoxy(98, 9);
	cout << "��" << endl;
	gotoxy(20, 10);
	cout << "��" << endl;
	gotoxy(98, 10);
	cout << "��" << endl;
	gotoxy(20, 11);
	cout << "��" << endl;
	gotoxy(98, 11);
	cout << "��" << endl;
	gotoxy(20, 12);
	cout << "��" << endl;
	gotoxy(98, 12);
	cout << "��" << endl;
	gotoxy(20, 13);
	cout << "��" << endl;
	gotoxy(98, 13);
	cout << "��" << endl;
	gotoxy(20, 14);
	cout << "��" << endl;
	gotoxy(98, 14);
	cout << "��" << endl;
	gotoxy(20, 15);
	cout << "��" << endl;
	gotoxy(98, 15);
	cout << "��" << endl;
	gotoxy(20, 16);
	cout << "��" << endl;
	gotoxy(98, 16);
	cout << "��" << endl;
	gotoxy(20, 17);
	cout << "��" << endl;
	gotoxy(98, 17);
	cout << "��" << endl;
	gotoxy(20, 18);
	cout << "��" << endl;
	gotoxy(98, 18);
	cout << "��" << endl;
	gotoxy(20, 19);
	cout << "��" << endl;
	gotoxy(98, 19);
	cout << "��" << endl;
	gotoxy(20, 20);
	cout << "��" ;
	gotoxy(26, 20);
	cout << "��������������������������������������" << endl;
	movecursor();
}

void UI::showBattleMap(vector<int> pattern)
{
	//��  ��  �� ��
	for (size_t i = 1; i <= pattern.size(); i++)
	{
		gotoxy(10 * i, 20);
		switch (pattern.at(pattern.size() - 1))
		{
		case UP:
			cout << "��";
			break;
		case DOWN:
			cout << "��";
			break;
		case RIGHT:
			cout << "��";
			break;
		case LEFT:
			cout << "��";
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
	cout << "���� LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "Ÿ�� : " << temp.getType() << endl;
		cout << "�̸� : " << temp.getName() << endl;
		cout << "ȿ�� : " << temp.getEffect() << endl;
 	}
	cout << "==========================="<< endl;

	gotoxy(0, 29);
	cout << "�������� �����ϼ���." << endl;
}

void UI::showInventory(vector<Armor>& input)
{
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "�� LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "Ÿ�� : " << temp.getType() << endl;
		cout << "�̸� : " << temp.getName() << endl;
		cout << "ȿ�� : " << temp.getEffect() << endl;
 	}
	cout << "===========================" << endl;
	gotoxy(0, 29);
	cout << "�������� �����ϼ���." << endl;
}

void UI::showInventory(vector<Potion>& input)
{
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "���� LIST" << endl;
	for (auto& temp : input)
	{		
		cout << "�̸� : " << temp.getName() << endl;
		cout << "ȿ�� : " << temp.getEffect() << endl;
 	}
	cout << "===========================" << endl;
	gotoxy(0, 20);
	cout << "�������� �����ϼ���." << endl;
}

void UI::showInventoryWhattodo()
{
	system("cls");
	gotoxy(50, 5);
	cout << "===========================" << endl;
	gotoxy(50, 6);
	cout << "������ �ұ��?" << endl;
	gotoxy(50, 7);
	cout << "1. ����ϱ�" << endl;
	gotoxy(50, 8);
	cout << "2. �ı��ϱ�" << endl;
	gotoxy(50, 9);
	cout << "-1 : ���ư���" << endl;
	gotoxy(50, 10);
	cout << "===========================" << endl;
	movecursor();
}

void UI::showInventoryIntro()
{
	gotoxy(50, 5);
	cout << "===========================" << endl;
	gotoxy(50, 6);
	cout << "� �κ��丮�� �����?" << endl;
	gotoxy(50, 7);
	cout << "1. ���� �κ��丮" << endl;
	gotoxy(50, 8);
	cout << "2. �� �κ��丮" << endl;
	gotoxy(50, 9);
	cout << "3. ���� �κ��丮" << endl;
	gotoxy(50, 10);
	cout << "-1 : ���ư���" << endl;
	gotoxy(50, 11);
	cout << "===========================" << endl;
}

void UI::showStore(Store & store)
{
	system("cls");
	gotoxy(0, 0);
	cout << "===========================" << endl;
	cout << "1. ���� ";
	if (store.getWeapon() != nullptr) cout << "�̸� : " << store.getWeapon()->getName() << " ���ݷ� : " << store.getWeapon()->getEffect() << endl;
	else cout << "�ȸ�" << endl;
	cout << "2. �� ";
	if (store.getArmor() != nullptr) cout << "�̸� : " << store.getArmor()->getName() << " ���� : " << store.getArmor()->getEffect() << ", ȸ�Ƿ� : " << store.getArmor()->getAvoidance() << endl;
	else cout << "�ȸ�" << endl;
	cout << "3. ���� ";
	if (store.getPotion() != nullptr) cout << "�̸� : " << store.getPotion()->getName() << " ȸ���� : " << store.getPotion()->getEffect() << endl;
	else cout << "�ȸ�" << endl;
	cout << "===========================" << endl;
	cout << "1. �����ϱ�" << endl;
	cout << "2. �Ǹ��ϱ�" << endl;
	cout << "3. ���ư���" << endl;
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



