#pragma once
#include "Item.h"

class Armor : public Item
{
	int iArmorDefense;
	int iAvoidance;
	int itype;
	string sName;
	int iWeight;


public:
	Armor();
	Armor(int i);
	virtual int getEffect();
	virtual int getType();
	virtual string getName();
	virtual bool enhance();
	virtual int getWeight();


	int getAvoidance();


};

