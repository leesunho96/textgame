#pragma once
#include "stdafx.h"
#include "Weapon.h"
#include "TextGameInfo.h"
#include "Item.h"

Weapon::Weapon(int itype)
{
	srand(time(NULL));
	this->itype = itype;
	switch (itype)
	{
	case 1:
		this->iAttack = TextGameInfo::OneHandedSword::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::OneHandedSword::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::OneHandedSword::iUsemana;		
		break;
	case 2:
		this->iAttack = TextGameInfo::TwoHandedSword::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::TwoHandedSword::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::TwoHandedSword::iUsemana;
		break;
	case 3:
		this->iAttack = TextGameInfo::ShortSword::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::ShortSword::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::ShortSword::iUsemana;
		break;
	case 4:
		this->iAttack = TextGameInfo::Niddle::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::Niddle::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::Niddle::iUsemana;
		break;
	case 5:
		this->iAttack = TextGameInfo::Staff::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::Staff::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::Niddle::iUsemana;
		break;
	case 6:
		this->iAttack = TextGameInfo::Wand::iAttack + rand() % 5;
		this->iUseStamina = TextGameInfo::Wand::iUsemana - rand() % 3;
		this->iUseMana = TextGameInfo::Wand::iUsemana;
		break;
	default:
		cout << "���� ���� ���� ����" << endl;
		exit(1);
	}
}

string Weapon::getName()
{
	switch (itype)
	{
	case 1:
		return "�Ѽհ�";
	case 2:
		return "�μհ�";
	case 3:
		return "�ܰ�";
	case 4:
		return "�ٴ�";
	case 5:
		return "������";
	case 6:
		return "�ϵ�";
	}
}

int Weapon::getType()
{
	return itype;
}

int Weapon::getEffect()
{
	return iAttack;
}




