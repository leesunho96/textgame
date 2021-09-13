#pragma once
#include "stdafx.h"
#include "TextGameInfo.h"
#include "Potion.h"
#include "TextGamePlayer.h"

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
	return "����";
}

bool Potion::enhance()
{
	return false;
}

