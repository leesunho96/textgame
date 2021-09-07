#pragma once

class Weapon : public Item
{
	int itype;
	int iAttack;
	int iUseStamina;
	int iUseMana;

public:
	Weapon(int itype);
	virtual string getName();
	virtual int getType();
	virtual int getEffect();
};

