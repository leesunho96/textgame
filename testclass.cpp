#include "stdafx.h"
#include "testclass.h"

testclass::testclass()
{
	a = new int[5]{0, };
}

void testclass::printclass()
{
	for (size_t i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
}

testclass::~testclass()
{
	
}
