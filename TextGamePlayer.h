#pragma once

class TextGamePlayer
{
	int iAttack;
	int iHp;
	int iMp;
	int iAvoidance;
	int iDefence;
	string sName;
	string sjob;

public:

	TextGamePlayer(int i, string sname);
	int getAttack();
	int getHP();
	int getMP();
	int getAvoidance();
	int getDefence();
	string getName();
	string getJob();

};

