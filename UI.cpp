#include "stdafx.h"
#include "TextGamePlayer.h"
#include "UI.h"
#include "TextGameInfo.h"



///��  ��  �� �� �� | ��



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
	getchar();
	system("cls");

}

void UI::showStatus(TextGamePlayer p)
{
	gotoxy(80, 15);
	cout << "==========================" << endl;
	gotoxy(80, 16);
	cout << "Name : " << p.getName() << endl;
	gotoxy(80, 17);
	cout << "Job :" << p.getJob() << endl;
	gotoxy(80, 18);
	cout << "HP : " << p.getHP() << endl;
	gotoxy(80, 19);
	cout << "MP : " << p.getMP() << endl;
	gotoxy(80, 20);
	cout << "Attack : " << p.getAttack() << endl;
	gotoxy(80, 21);
	cout << "Defence : " << p.getDefence() << endl;
	gotoxy(80, 22);
	cout << "==========================" << endl;

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


	for (size_t j = 0; j < 14; j++)
	{
	for (size_t i = 1; i < 20; i++)
		{

			gotoxy(19 + 4 * i, 6 + j);
			cout << "��";
		}

	}
	
	movecursor();
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



