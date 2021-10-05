#pragma once


class Potion;
class Weapon;
class Armor;
class TextGamePlayer;
class Item;

class Inventory {

	void chooseWhattodo(int invensize, int whattodo, TextGamePlayer * player, int &retflag);
	int chooseInventory(int &retflag);
	void openWareHouse(int invensize, TextGamePlayer * player, int &retflag);

	template <class t1>
	void popInventory(vector<t1> &input, int index);

	template <class t2>
	t2 getItem(vector<t2> &input, int index);

	void inventoryApply(TextGamePlayer* player, Item* input);

public:
	Inventory(int input);
	vector<Potion> potionInventory;
	vector<Weapon> weaponInventory;
	vector<Armor> armorInverntory;
	vector<Item*> wareHouse;


	void pushInventory(Potion& push);
	void pushInventory(Weapon& push);
	void pushInventory(Armor& push);
	void pushWareHouse(Item* push);
	
	void popPotionInventory(int index);
	void popWeaponInventory(int index);
	void popArmorInventory(int index);
	bool popWareHouse(int index);


	Potion getPotion(int index);
	Weapon getWeapon(int index);
	Armor getArmor(int index);
	Item* getWareHouse(int index);


	void open(TextGamePlayer* player);

	void showWeaponInventory();
	void showArmorInventory();
	void showPotionInventory();
	void showWareHouse();
};

template<class t1>
inline void Inventory::popInventory(vector<t1>& input, int index)
{

	if (index - 1 < input.size())
	{
		input.erase(begin(input) + index - 1);
	}
	else
	{
		UI::outofrangeErrorMessage();
	}

}

template<class t2>
inline t2 Inventory::getItem(vector<t2>& input, int index)
{
	if (index - 1 < input.size())
	{
		return input.at(index - 1);
	}
	else
	{
		UI::outofrangeErrorMessage();
		return t2();
	}
}

