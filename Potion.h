#pragma once
#include "Item.h"

class Item;

class Potion : public Item
{
	int healHP;
	int healMP;

public:
	Potion();
	virtual int getEffect();
	virtual int getType();
	virtual string getName();
	virtual bool enhance();
};

