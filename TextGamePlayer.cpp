#pragma once
#include "stdafx.h"
#include "TextGamePlayer.h"
#include "TextGameInfo.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

void TextGamePlayer::setlocation(int input)
{
	switch (input)
	{
	case UP:
		location.second--;
		break;
	case DOWN:
		location.second++;
		break;
	case LEFT:
		location.first--;
		break;
	case RIGHT:
		location.first++;
		break;
	default:
		break;
	}
}

bool TextGamePlayer::applydamege(int iAttack)
{
	gotoxy(0, 1);
	srand(time(NULL));
	if (rand() % 10 < iAvoidance)
	{
		cout << sName << "�� ȸ���Ͽ����ϴ�." << endl;
		getch();
		return false;
	}
	else
	{
		iHp = iHp + (iDefence - iAttack);
		cout << sName << "�� " << -iDefence + iAttack << "�� ���ظ� �Ծ����ϴ�." << endl;
		getch();
		return true;
	}
}

int TextGamePlayer::getIendtity()
{
	return identity;
}

void TextGamePlayer::openInventory()
{
	playerInventory->open(this);
}

void TextGamePlayer::pushItem(Weapon input)
{
	playerInventory->pushInventory(input);
}

void TextGamePlayer::pushItem(Armor input)
{
	playerInventory->pushInventory(input);
}

void TextGamePlayer::pushItem(Potion input)
{
	playerInventory->pushInventory(input);
}

void TextGamePlayer::applyItem(Weapon input, int index)
{
	if (applyWeapon != nullptr)
	{
		playerInventory->pushInventory(*applyWeapon);
		delete applyWeapon;
	}
	initializeAttack();
	this->iAttack += input.getEffect();
	playerInventory->popWeaponInventory(index);
	applyWeapon = new Weapon(input);
}

void TextGamePlayer::applyItem(Potion input, int index)
{
	this->iHp += input.getEffect();
	if (iHp > iMaxHP)
	{
		iHp = iMaxHP;
	}
	playerInventory->popPotionInventory(index);
}

void TextGamePlayer::applyItem(Armor input, int index)
{
	if (applyArmor != nullptr)
	{
		playerInventory->pushInventory(*applyArmor);
		delete applyArmor;
	}
	initializeDefense();
	this->iDefence += input.getEffect();
	this->iAvoidance += input.getAvoidance();
	playerInventory->popArmorInventory(index);
	applyArmor = new Armor(input);
}

void TextGamePlayer::initializeAttack()
{
	if (sjob == "WORRIER")
	{
		this->iAttack = TextGameInfo::Worrier::iAttack;
	}
	else if (sjob == "ROGUE")
	{
		this->iAttack = TextGameInfo::Rogue::iAttack;
	}
	else
	{
		this->iAttack = TextGameInfo::Mage::iAttack;
	}
}

void TextGamePlayer::initializeDefense()
{
	if (sjob == "WORRIER")
	{
		this->iDefence = TextGameInfo::Worrier::iDefence;
		this->iAvoidance = TextGameInfo::Worrier::iavoidance;
	}
	else if (sjob == "ROGUE")
	{
		this->iDefence = TextGameInfo::Rogue::iDefence;
		this->iAvoidance = TextGameInfo::Rogue::iavoidance;
	}
	else
	{
		this->iDefence = TextGameInfo::Mage::iDefence;
		this->iAvoidance = TextGameInfo::Mage::iavoidance;
	}
}

TextGamePlayer::TextGamePlayer(int i, string sname)
{
	{

		// ĳ���� Ÿ���� �Է¹޾Ƽ� �ش�Ǵ� �������� �ʱ�ȭ.
		// �÷��̾��� ��� 1 ~ 3, ���ϰ�� 4 ~ 6

		switch (i)
		{
		case 1:
			iHp = TextGameInfo::Worrier::iHP;
			iMp = TextGameInfo::Worrier::iMP;
			iAttack = TextGameInfo::Worrier::iAttack;
			iDefence = TextGameInfo::Worrier::iDefence;
			iAvoidance = TextGameInfo::Worrier::iavoidance;
			sName = sname;
			sjob = "WORRIER";
			break;
		case 2:
			iHp = TextGameInfo::Rogue::iHP;
			iMp = TextGameInfo::Rogue::iMP;
			iAttack = TextGameInfo::Rogue::iAttack;
			iDefence = TextGameInfo::Rogue::iDefence;
			iAvoidance = TextGameInfo::Rogue::iavoidance;
			sName = sname;
			sjob = "ROGUE";
			break;
		case 3:
			iHp = TextGameInfo::Mage::iHP;
			iMp = TextGameInfo::Mage::iMP;
			iAttack = TextGameInfo::Mage::iAttack;
			iDefence = TextGameInfo::Mage::iDefence;
			iAvoidance = TextGameInfo::Mage::iavoidance;
			sName = sname;
			sjob = "MAGE";
			break;

		case 4:
			iHp = TextGameInfo::Ogre::iHP;
			iMp = TextGameInfo::Ogre::iMP;
			iAttack = TextGameInfo::Ogre::iAttack;
			iDefence = TextGameInfo::Ogre::iDefence;
			iAvoidance = TextGameInfo::Ogre::iavoidance;
			sName = "OGRE";
			sjob = "WORRIER";
			break;
		case 5:
			iHp = TextGameInfo::Goblin::iHP;
			iMp = TextGameInfo::Goblin::iMP;
			iAttack = TextGameInfo::Goblin::iAttack;
			iDefence = TextGameInfo::Goblin::iDefence;
			iAvoidance = TextGameInfo::Goblin::iavoidance;
			sName = "GOBLIN";
			sjob = "ROGUE";
			break;
			break;
		case 6:
			iHp = TextGameInfo::Oak::iHP;
			iMp = TextGameInfo::Oak::iMP;
			iAttack = TextGameInfo::Oak::iAttack;
			iDefence = TextGameInfo::Oak::iDefence;
			iAvoidance = TextGameInfo::Oak::iavoidance;
			sName = "OAK";
			sjob = "MAGE";
			break;

		}


		// ���� ��� ������ġ�� ����, �÷��̾� �� ��� 0,0���� ����
		switch ((int)(i / 4))
		{
		case 0:
			location = make_pair(0, 0);
			identity = PLAYER;
			break;
		case 1:
			location = make_pair(rand() % VERTICALSIZE, rand() % HORIZENTALSIZE);
			identity = ENEMY;
			break;
		}

		playerInventory = new Inventory((int)(i / 4));
		iMaxHP = iHp;

	}

}

int TextGamePlayer::getAttack()
{
	return iAttack;
}

int TextGamePlayer::getHP()
{
	return iHp;
}

int TextGamePlayer::getMP()
{
	return iMp;
}

int TextGamePlayer::getAvoidance()
{
	return iAvoidance;
}

int TextGamePlayer::getDefence()
{
	return iDefence;
}

int TextGamePlayer::getMoney()
{
	return iMoney;
}

bool TextGamePlayer::useMoney(int money)
{
	if (iMoney >= money)
	{
		iMoney -= money;
		return true;
	}
	else
	{
		return false;
	}
}

string TextGamePlayer::getName()
{
	return sName;
}

string TextGamePlayer::getJob()
{
	return sjob;
}

pair<int, int> TextGamePlayer::getLocation()
{
	return location;
}
