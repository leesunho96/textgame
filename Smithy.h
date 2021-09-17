#pragma once

class TextGamePlayer;
class Item;

class Smithy
{
	Item* enhance_item = nullptr;
	Item* sacrificed_Item = nullptr;
public:
	~Smithy();
	void run(TextGamePlayer& player);
};

