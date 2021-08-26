#include "stdafx.h"
#include "Armor.h"
#include "TextGameInfo.h"

Armor::Armor(int i)
{
	srand(time(NULL));
	this->itype = i;
	
	i == 1 ? this->iArmorDefense = TextGameInfo::LightArmor::iArmorDefence + rand() % 5 : this->iArmorDefense = TextGameInfo::HeavyArmor::iArmorDefence + rand() % 5;
}
