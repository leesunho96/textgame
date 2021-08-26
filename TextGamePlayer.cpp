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
