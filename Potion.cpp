#include "stdafx.h"
#include "Potion.h"
#include "TextGameInfo.h"
#include "Item.h"

Potion::Potion()
{

	this->healHP = TextGameInfo::potion::iHealHP + rand() % 5;
	this->healMP = TextGameInfo::potion::iHealMP + rand() % 5;
}

int Potion::getEffect()
{
	return healHP;
}

int Potion::getType()
{
	return -1;
}

string Potion::getName()
{
	return "Æ÷¼Ç";
}
