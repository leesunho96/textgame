#pragma once
#include "Item.h"

class Weapon : public Item
{
	int itype;
	int iAttack;
	int iUseStamina;
	int iUseMana;
	int iWeight;

public:
	Weapon();
	Weapon(int itype);
	virtual string getName();
	virtual int getType();
	virtual int getEffect();
	virtual bool enhance();	
	virtual int getWeight();
	
};

