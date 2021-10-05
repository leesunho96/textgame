#pragma once
class Item
{
	int test = 0;

public:
	virtual string getName() = 0;
	virtual int getType() = 0;
	virtual int getEffect() = 0;
	virtual int getWeight() = 0;
	virtual bool enhance() = 0;

	virtual ~Item();
};

