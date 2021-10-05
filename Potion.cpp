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

Potion::Potion(int input)
{
	healHP = 0;
	healMP = 0;
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

bool Potion::enhance()
{
	return false;
}

int Potion::getWeight()
{
	return 0;
}

bool Potion::operator==(const Potion& target)
{
	return (this->healHP == target.healHP) && (this->healMP == target.healMP) ? true : false;
}

Potion::~Potion()
{
}

