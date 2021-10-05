#pragma once

class TextGamePlayer;
class Item;

class Smithy
{
	Item* enhance_item = nullptr;
	Item* sacrificed_Item = nullptr;

	bool indexcheck(int type, Item* checkingItem);
public:
	~Smithy();
	bool run(TextGamePlayer& player);
	bool isSacrificeItemExist(int temp, TextGamePlayer & player, int &retflag);
};

