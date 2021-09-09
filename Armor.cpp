#pragma once
#include "stdafx.h"
#include "Armor.h"
#include "TextGameInfo.h"


class TextGameInfo;

Armor::Armor(int i)
{
	srand(time(NULL));
	this->itype = i;
	
	i == 1 ? this->iArmorDefense = TextGameInfo::LightArmor::iArmorDefence + rand() % 5 : this->iArmorDefense = TextGameInfo::HeavyArmor::iArmorDefence + rand() % 5;
}

int Armor::getEffect()
{
	return iArmorDefense;
}

int Armor::getType()
{
	return itype;
}

string Armor::getName()
{
	return sName;
}

bool Armor::enhance()
{
	if ((rand() % 100) > 30)
	{
		iArmorDefense += rand() % 4 + 1;
	}
	else
	{
		return false;
	}
}

