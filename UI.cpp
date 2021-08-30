#include "stdafx.h"
#include "TextGamePlayer.h"
#include "UI.h"
#include "TextGameInfo.h"



///¡â  ¢·  ¢¹ ¡ä ¡Ú | ¡á



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
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	gotoxy(98, 5);
	cout << "¡á";
	gotoxy(20, 6);
	cout << "¡á" << endl;
	gotoxy(98, 6);
	cout << "¡á" << endl;
	gotoxy(20, 7);
	cout << "¡á" << endl;
	gotoxy(98, 7);
	cout << "¡á" << endl;
	gotoxy(20, 8);
	cout << "¡á" << endl;
	gotoxy(98, 8);
	cout << "¡á" << endl;
	gotoxy(20, 9);
	cout << "¡á" << endl;
	gotoxy(98, 9);
	cout << "¡á" << endl;
	gotoxy(20, 10);
	cout << "¡á" << endl;
	gotoxy(98, 10);
	cout << "¡á" << endl;
	gotoxy(20, 11);
	cout << "¡á" << endl;
	gotoxy(98, 11);
	cout << "¡á" << endl;
	gotoxy(20, 12);
	cout << "¡á" << endl;
	gotoxy(98, 12);
	cout << "¡á" << endl;
	gotoxy(20, 13);
	cout << "¡á" << endl;
	gotoxy(98, 13);
	cout << "¡á" << endl;
	gotoxy(20, 14);
	cout << "¡á" << endl;
	gotoxy(98, 14);
	cout << "¡á" << endl;
	gotoxy(20, 15);
	cout << "¡á" << endl;
	gotoxy(98, 15);
	cout << "¡á" << endl;
	gotoxy(20, 16);
	cout << "¡á" << endl;
	gotoxy(98, 16);
	cout << "¡á" << endl;
	gotoxy(20, 17);
	cout << "¡á" << endl;
	gotoxy(98, 17);
	cout << "¡á" << endl;
	gotoxy(20, 18);
	cout << "¡á" << endl;
	gotoxy(98, 18);
	cout << "¡á" << endl;
	gotoxy(20, 19);
	cout << "¡á" << endl;
	gotoxy(98, 19);
	cout << "¡á" << endl;
	gotoxy(20, 20);
	cout << "¡á" ;
	gotoxy(26, 20);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
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



