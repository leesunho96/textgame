#pragma once
class UI
{

	static void movecursor();
public:

	static void gotoxy(int x, int y);
	static void showStartScreen();
	static void showChooseJob();
	static void chooseName();
	static void showStatus(TextGamePlayer p);
	static void showWhattodo();
};

