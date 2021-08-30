#include "stdafx.h"
#include "TextGamePlayer.h"
#include "TextGameInfo.h"


TextGamePlayer::TextGamePlayer(int i, string sname)
{
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

	switch ((int)(i / 4))
	{
	case 1:
		location = make_pair(0, 0);
		break;
	case 2:
		location = make_pair(rand() %  )
		break;
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
