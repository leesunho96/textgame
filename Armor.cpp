#pragma once
#include "stdafx.h"
#include "Armor.h"
#include "TextGameInfo.h"



class TextGameInfo;

Armor::Armor()
{
	itype = 0;
}

Armor::Armor(int i)
{
	srand(time(NULL));
	this->itype = i;
	if (i != 0)
	{
		i == 1 ? this->iArmorDefense = TextGameInfo::LightArmor::iArmorDefence + rand() % 5 : this->iArmorDefense = TextGameInfo::HeavyArmor::iArmorDefence + rand() % 5;
		i == 1 ? this->iAvoidance = TextGameInfo::LightArmor::iAvoidance : this->iAvoidance = TextGameInfo::HeavyArmor::iavoidance;
		i == 1 ? this->iWeight = TextGameInfo::LightArmor::iWeight : this->iWeight = TextGameInfo::HeavyArmor::iWeight;
		if (itype == 1)
			this->sName = "LightArmor";
		else
			this->sName = "HeavyArmor";
	}
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
	srand(time(NULL));

	if ((rand() % 100) > 30)
	{
		iArmorDefense += rand() % 4 + 1;
		return true;
	}
	else
	{
		return false;
	}
}

int Armor::getWeight()
{
	return iWeight;
}

int Armor::getAvoidance()
{
	return iAvoidance;
}

bool Armor::operator==(const Armor & temp)
{
	return 	this->itype == temp.itype ? true : false;
}


