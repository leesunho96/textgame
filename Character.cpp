#include "stdafx.h"
#include "Character.h"

int Character::global = 20;

Character::Character()
	//:temp(10),test(hp)
{
	cout << "�⺻������ ȣ��" << endl;
	initializeValueData("SGA", 10);	
	initializeAddressdata();

}

Character::Character(string name, int hp)
	:name(name) //temp(10), test(hp)
{
	cout << "�Ķ���� �ִ� ������ ȣ��" << endl;
	initializeValueData(name, hp);
	initializeAddressdata();


}

Character::Character(string name, int hp, int attack, int deffense)
{
	cout << "�Ķ���� �ִ� ������ ȣ��" << endl;
	initializeValueData(name, hp, attack, deffense);
	initializeAddressdata();
}

Character::Character(const Character & src)
	//:temp(10),test(hp)
{
	cout << "������ �Ű������� ���� ���� ������ ȣ��" << endl;
	initializeValueData(src.name, src.hp, src.attack, src.deffense, src.size);
	initializeAddressdata();
	copyAddressdata(src);

	


}

Character & Character::operator=(const Character & rhs)
{
	cout << "���� ������ ȣ��" << endl;
	if (this == &rhs)
	{
		return *this;
	}
	delete[] ptr;

	ptr = nullptr;
	initializeValueData(rhs.name, rhs.hp, rhs.attack, rhs.deffense, rhs.size);
	initializeAddressdata();
	copyAddressdata(rhs);

	return *this;
}

Character & Character::operator+(const Character & rhs)
{
	
	name += rhs.name;

	return *this;
}

Character & Character::operator+(const string & rhs)
{
	name += rhs;

	return *this;
}

Character & Character::operator+=(const string & rhs)
{
	this->name = this->name + rhs;

	return *this;
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}

Character::~Character()
{
	cout << "�Ҹ���" << endl;

	delete ptr;
}

void Character::Damage(int attack)
{
	hp -= attack;

	cout << attack << "�� ���ظ� �Ծ���." << endl;

	cout << "���� ü�� : " << hp << endl;
}
void Character::initializeValueData(string name, int hp, int attack, int defence, int size)
{
	cout << "����� ���� ���� �ʱ�ȭ �޼ҵ� ȣ��" << endl;
	this->name = name;
	this->hp = hp;
	this->attack = attack;
	this->deffense = defence;
	this->size = size;
}

void Character::initializeAddressdata()
{
	cout << "�� ���� ���� �޸� �Ҵ� �޼ҵ� ȣ��" << endl;
	ptr = new int[size] {0};

}

void Character::copyAddressdata(const Character& src)
{
	cout << "�� ���� �޸� ���� �޼ҵ� ȣ��" << endl;

	copy(src.ptr, src.ptr + size, this->ptr);

	//memcpy(this->ptr, src.ptr, _msize(src.ptr));
	
	//for (size_t i = 0; i < this->size; i++)
	//{
	//	this->ptr[i] = src.ptr[i];
	//}
	// ������ ��� ������ ȿ���� ������, �ӵ��� for ���� �̿��� ����� ���� �ʰ�, ������ memcpy�� copy�� �ӵ��� �����.

}

void Character::showstatus()
{
	cout << "===========================" << endl;
	cout << "�� Ŭ������ �̸��� : " << name << endl;
	cout << "�� Ŭ������ HP�� : " << hp << endl;
	cout << "�� Ŭ������ ���ݷ��� : " << attack << endl;
	cout << "�� Ŭ������ ������ : " << deffense << endl;
	cout << "�� Ŭ������ �� ������ �Ҵ�� int�迭�� ���� : " << size << endl;
	cout << "�� Ŭ������ �� ������ �Ҵ�� �޸��� ũ��� : " << _msize(ptr) << endl;
	cout << "�� Ŭ������ �� ������ ����� �����͵��� : ";
	for (size_t i = 0; i < size; i++)
	{
		cout << ptr[i] << "  ";
	}
	cout << endl << "===========================" << endl;
}

//
//Character::Character2::Character2()
//{
//}
//////////////////////////////////////////