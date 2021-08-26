#include<iostream>
#include<cstdio>
#include <string>
using namespace std;

enum class job{
	warrier = 1, rogue, mage, demonhunter, holyknight, warlock
};
enum class heropower {
	getarmor = 1, getweapon, usemaginc, getattack, summonminnion, drawcard
};
enum class grade {
	bronze = 1, silver, gold, platinum, legend
};
enum class gender {
	male = 1, female
};
enum class country {
	korea = 1, japan, china, usa, uk
};

typedef struct player {
	job sjob;
	heropower sheropower;
	grade sgrade;
	gender sgender;
	country scountry;
}player;


int main()
{
	player player1;

	int iinputdata;


	cout << "choose your job. (warrier = 1, rogue = 2, mage = 3, demonhunter = 4, holyknight = 5, warlock = 6) : ";
	cin >> iinputdata;

	switch ((job)iinputdata)
	{
	case (job)1:
		player1.sjob = (job)1;
		cout << "you choose warrier" << endl;
		break;
	case (job)2:
		player1.sjob = (job)2;
		cout << "you choose rogue" << endl;
		break;
	case (job)3:
		player1.sjob = (job)3;
		cout << "you choose mage" << endl;
		break;
	case (job)4:
		player1.sjob = (job)4;
		cout << "you choose demonhunter" << endl;
		break;
	case (job)5 :
		player1.sjob = (job)5;
		cout << "you choose holyknight" << endl;
		break;
	case (job)6:
		player1.sjob = (job)6;
		cout << "you choose warlock" << endl;
		break;
	default :
		cout << "범위를 벗어났습니다. 올바른 범위를 입력하세요." << endl;
		break;
	}

	cout << "choose your heropower (getarmor = 1, getweapon = 2, usemagic = 3, getattack = 4, summonminnion = 5, drawcard = 6)";
	cin >> iinputdata;

	switch ((heropower)iinputdata)
	{
	case (heropower)1:
		player1.sheropower = (heropower)1;
		cout << "you choose getarmor" << endl;
		break;
	case (heropower)2:
		player1.sheropower = (heropower)2;
		cout << "you choose getweapon" << endl;
		break;
	case (heropower)3:
		player1.sheropower = (heropower)3;
		cout << "you choose usemagic" << endl;
		break;
	case (heropower)4:
		player1.sheropower = (heropower)4;
		cout << "you choose getattack" << endl;
		break;
	case (heropower)5:
		player1.sheropower = (heropower)5;
		cout << "you choose summonminnion" << endl;
		break;
	case (heropower)6:
		player1.sheropower = (heropower)6;
		cout << "you choose drawcard" << endl;
		break;
	default:
		cout << "범위를 벗어났습니다. 올바른 범위를 입력하세요." << endl;
		break;
	}
	cout << "write your highest grade (bronze = 1, silver = 2, gold = 3, platinum = 4, legend = 5)";
	cin >> iinputdata;

	switch ((grade)iinputdata)
	{
	case (grade)1:
		player1.sgrade = (grade)1;
		cout << "play hard. you are in bronze class" << endl;
		break;
	case (grade)2:
		player1.sgrade = (grade)2;
		cout << "not bad. you are in silver" << endl;
		break;
	case (grade)3:
		player1.sgrade = (grade)3;
		cout << "great. you are in gold" << endl;
		break;
	case (grade)4:
		player1.sgrade = (grade)4;
		cout << "wow! you are in platinum" << endl;
		break;
	case (grade)5:
		player1.sgrade = (grade)5;
		cout << "wonderful! you are legend" << endl;
		break;	
	default:
		cout << "범위를 벗어났습니다. 올바른 범위를 입력하세요." << endl;
		break;
	}
	cout << "are you male or female? (male = 1, female = 2)";
	cin >> iinputdata;

	switch ((gender)iinputdata)
	{
	case (gender)1:
		player1.sgender = (gender)1;
		cout << "you are male" << endl;
		break;
	case (gender)2:
		player1.sgender = (gender)2;
		cout << "you are female" << endl;
		break;
		
	default:
		cout << "범위를 벗어났습니다. 올바른 범위를 입력하세요." << endl;
		break;
	}
	cout << "where are you from? (korea = 1, japan = 2, china = 3, usa = 4, uk = 5)";
	cin >> iinputdata;

	switch ((country)iinputdata)
	{
	case (country)1:
		player1.scountry = (country)1;
		cout << "you are from korea." << endl;
		break;
	case (country)2:
		player1.scountry = (country)2;
		cout << "you are from japan" << endl;
		break;
	case (country)3:
		player1.scountry = (country)3;
		cout << "you are from china" << endl;
		break;
	case (country)4:
		player1.scountry = (country)4;
		cout << "you are from usa" << endl;
		break;
	case (country)5:
		player1.scountry = (country)5;
		cout << "you are from uk" << endl;
		break;
	default:
		cout << "범위를 벗어났습니다. 올바른 범위를 입력하세요." << endl;
		break;
	}

	cout << "===============================================================================" << endl;
	cout << "let's check your status" << endl;
	cout << "you choose ";
	switch ((int)player1.sjob)
	{
	case 1:
		cout << "warrier" << endl;
		break;
	case 2:
		cout << "rogue" << endl;
		break;
	case 3:
		cout << "mage" << endl;
		break;
	case 4:
		cout << "demonhunter" << endl;
		break;
	case 5:
		cout << "holyknight" << endl;
		break;
	case 6:
		cout << "warlock" << endl;
		break;
	default: cout << "error" << endl;		
	}
	cout << "you choose ";
	switch ((int)player1.sheropower)
	{
	case 1:
		cout << "getarmor" << endl;
		break;
	case 2:
		cout << "getweapon" << endl;
		break;
	case 3:
		cout << "use magic" << endl;
		break;
	case 4:
		cout << "getattack" << endl;
		break;
	case 5:
		cout << "summonminnion" << endl;
		break;
	case 6:
		cout << "drawcard" << endl;
		break;
	default: cout << "error" << endl;
	}
	cout << "your highest grade is  ";
	switch ((int)player1.sgrade)
	{
	case 1:
		cout << "bronze" << endl;
		break;
	case 2:
		cout << "silver" << endl;
		break;
	case 3:
		cout << "gold" << endl;
		break;
	case 4:
		cout << "platinum" << endl;
		break;
	case 5:
		cout << "legend" << endl;
		break;
	
	default: cout << "error" << endl;
	}
	cout << "you are ";
	switch ((int)player1.sgender)
	{
	case 1:
		cout << "male" << endl;
		break;
	case 2:
		cout << "female" << endl;
		break;
	default: cout << "error" << endl;
	}
	cout << "you lives in ";
	switch ((int)player1.scountry)
	{
	case 1:
		cout << "korea" << endl;
		break;
	case 2:
		cout << "japan" << endl;
		break;
	case 3:
		cout << "china" << endl;
		break;
	case 4:
		cout << "usa" << endl;
		break;
	case 5:
		cout << "uk" << endl;
		break;

	default: cout << "error" << endl;
	}
	cout << "===============================================================================" << endl;
} 