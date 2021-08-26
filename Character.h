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

	//////// ������ ȣ��� ���� ���� ������ ���� ���� �ʱ�ȭ �Լ�, ���� ���� ���� �Լ��� �и���
	// ���� ����(name, hp, attack, defence, size)�� ���� �ʱ�ȭ 
	void initializeValueData(string name = "NULL", int hp = 100, int attack = 10, int defence = 10, int size = 5);

	// ���� ����(ptr)�� new�� �̿��Ͽ� �޸� �Ҵ�
	void initializeAddressdata();

	// ������ �Ҵ��� �޸𸮿� ������ �� ���� �޸� ����
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