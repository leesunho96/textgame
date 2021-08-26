#include <iostream>
#include <cstdio>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

typedef struct Unit {
	int num;
	int attack;
	int hp;
	int def;
}Unit;



int main()
{
	Unit marine[12];
	srand(time(NULL));

	for (size_t i = 0; i < 12; i++)
	{
		marine[i].attack = rand() % 10;
		marine[i].def = 5;
		marine[i].hp = rand() % 10 + 50;
		marine[i].num = (int)i;
	}

	/*for (size_t i = 0; i < 12; i++)
	{
		int temp1 = rand() % 12;		
		swap(marine[i], marine[temp1]);
	}*/

	for (size_t i = 0; i < 12; i++)
	{
		int temp1 = rand() % 12;
		int temp2 = rand() % 12;
		Unit mTemp = marine[temp1];
		marine[temp1] = marine[temp2];
		marine[temp2] = mTemp;

	}

	for (size_t i = 0; i < 12; i++)
	{
		cout << "=================================================" << endl;
		cout << "marine " << i << " 번호 : " << marine[i].num << endl;
		cout << "marine " << i << " 공격력 : " << marine[i].attack << endl;
		cout << "marine " << i << " 방어력 : " << marine[i].def << endl;
		cout << "marine " << i << " 체력 : " << marine[i].hp << endl;
		cout << "=================================================" << endl << endl;
	}
	return 0;
}