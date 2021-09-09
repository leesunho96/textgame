#pragma once
class Item
{
public:
	virtual string getName() = 0;
	virtual int getType() = 0;
	virtual int getEffect() = 0;
	virtual bool enhance() = 0;
};

