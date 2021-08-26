#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int a = 0;

	cout << "구구단 출력(for 이용)" << endl;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << "*" << j << " = " << i * j <<  "    ";
		}
		cout << endl;

	}

	cout << "구구단 출력(while 이용)" << endl;
	int i = 1, j = 0;
	while (i++ < 9 )
	{
		while (j++ < 9)
		{
			cout << i << "*" << j << " = " << i * j << "    ";
		}
		j = 0;
		cout << endl;
	}

	cout << "입력받아서 구구단 출력(for 이용) : ";
	int iinputNum;
	cin >> iinputNum;

	for (int i = 1; i < 10; i++)
	{
		cout << iinputNum << "*" << i << " = " << i * iinputNum << "  ";
	}
	cout << endl;

	cout << "입력받아서 구구단 출력(while 이용) : ";
	cin >> iinputNum;
	i = 0;
	while (i++ < 9)
	{
		cout << iinputNum << "*" << i << " = " << i * iinputNum << "  ";
	}
	
	return 0;
}