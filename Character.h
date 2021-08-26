#pragma once

class Character
{

public:
	
	Character();
	 
	Character(string name, int hp);
	Character(string name, int hp, int attack, int deffense = 10);

	Character(const Character& src);
	//Character(const Character& src) = default;
	//Character(const Character& src) = delete;

	Character& operator=(const Character& rhs);
	//Character& operator=(const Character& rhs) = default;
	//Character& operator=(const Character& rhs) = delete;

	Character& operator+(const Character& rhs);
	Character& operator+(const string& rhs);
	Character& operator+=(const string& rhs);

	~Character();

	string GetName() { return name; }
	void SetName(string name) { this->name = name; }

	int GetDef() { return deffense; }

	void Damage(int attack);

	//class Character2
	//{
	//public:
	//	Character2();
	//};


private:

	//////// 생성자 호출시 각각 정적 영역과 동적 영역 초기화 함수, 동적 영역 복하 함수를 분리함
	// 정적 영역(name, hp, attack, defence, size)에 대한 초기화 
	void initializeValueData(string name = "NULL", int hp = 100, int attack = 10, int defence = 10, int size = 5);

	// 동적 영역(ptr)에 new를 이용하여 메모리 할당
	void initializeAddressdata();

	// 위에서 할당한 메모리에 원본의 힙 영역 메모리 복사
	void copyAddressdata(const Character &src);
	
	
	
	string name;
	int hp;
	int attack;
	int deffense;

	//const int temp;
	//int& test;

	int size;
	int* ptr;


public:
	static int global;
	void showstatus();


};
/////////////////////////////
class Character2
{

};