#include "stdafx.h"
#include "Character.h"

int Character::global = 20;

Character::Character()
	//:temp(10),test(hp)
{
	cout << "기본생성자 호출" << endl;
	initializeValueData("SGA", 10);	
	initializeAddressdata();

}

Character::Character(string name, int hp)
	:name(name) //temp(10), test(hp)
{
	cout << "파라미터 있는 생성자 호출" << endl;
	initializeValueData(name, hp);
	initializeAddressdata();


}

Character::Character(string name, int hp, int attack, int deffense)
{
	cout << "파라미터 있는 생성자 호출" << endl;
	initializeValueData(name, hp, attack, deffense);
	initializeAddressdata();
}

Character::Character(const Character & src)
	//:temp(10),test(hp)
{
	cout << "원본을 매개변수로 갖는 복사 생성자 호출" << endl;
	initializeValueData(src.name, src.hp, src.attack, src.deffense, src.size);
	initializeAddressdata();
	copyAddressdata(src);

	


}

Character & Character::operator=(const Character & rhs)
{
	cout << "대입 연산자 호출" << endl;
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
	// TODO: 여기에 반환 구문을 삽입합니다.
}

Character::~Character()
{
	cout << "소멸자" << endl;

	delete ptr;
}

void Character::Damage(int attack)
{
	hp -= attack;

	cout << attack << "의 피해를 입었다." << endl;

	cout << "현재 체력 : " << hp << endl;
}
void Character::initializeValueData(string name, int hp, int attack, int defence, int size)
{
	cout << "공통된 정적 변수 초기화 메소드 호출" << endl;
	this->name = name;
	this->hp = hp;
	this->attack = attack;
	this->deffense = defence;
	this->size = size;
}

void Character::initializeAddressdata()
{
	cout << "힙 영역 동적 메모리 할당 메소드 호출" << endl;
	ptr = new int[size] {0};

}

void Character::copyAddressdata(const Character& src)
{
	cout << "힙 영역 메모리 복사 메소드 호출" << endl;

	copy(src.ptr, src.ptr + size, this->ptr);

	//memcpy(this->ptr, src.ptr, _msize(src.ptr));
	
	//for (size_t i = 0; i < this->size; i++)
	//{
	//	this->ptr[i] = src.ptr[i];
	//}
	// 세가지 모두 동일한 효과를 갖지만, 속도는 for 문을 이용한 방식이 가장 늦고, 나머지 memcpy와 copy는 속도가 비슷함.

}

void Character::showstatus()
{
	cout << "===========================" << endl;
	cout << "이 클래스의 이름은 : " << name << endl;
	cout << "이 클래스의 HP는 : " << hp << endl;
	cout << "이 클래스의 공격력은 : " << attack << endl;
	cout << "이 클래스의 방어력은 : " << deffense << endl;
	cout << "이 클래스의 힙 영역에 할당된 int배열의 수는 : " << size << endl;
	cout << "이 클래스의 힙 영역에 할당된 메모리의 크기는 : " << _msize(ptr) << endl;
	cout << "이 클래스의 힙 영역에 저장된 데이터들은 : ";
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