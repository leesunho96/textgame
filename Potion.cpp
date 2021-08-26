#include "stdafx.h"
#include "Potion.h"
#include "TextGameInfo.h"


Potion::Potion()
{

	this->healHP = TextGameInfo::potion::iHealHP + rand() % 5;
	this->healMP = TextGameInfo::potion::iHealMP + rand() % 5;
}
