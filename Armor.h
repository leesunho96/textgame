#pragma once
#include "Item.h"

class Armor : public Item
{
	int iArmorDefense;
	int itype;
	string sName;


public:
	Armor(int i);
	virtual int getEffect();
	virtual int getType();
	virtual string getName();
	virtual bool enhance();
};

