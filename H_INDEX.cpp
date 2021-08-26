#include "stdafx.h"

_inline ge

int solution(vector<int> citations) {
	int answer = 0;
	int n = citations.size();
	int h;
	sort(citations.begin(), citations.end());
	int iindex = n;
	int called;
	int notcalled;

	do 
	{
		h = citations[--iindex];
		for (size_t i = citations.size() - 1; i >= 0; i--)
		{
			if (citations[i] >= h)
				called++;
			else
				break;
		}
	} while (!(called >= h && notcalled <= h));
		
	return answer;
}


int main()
{
	vector<int> input = { 3, 0, 6, 1, 5 };

	cout << solution(input) << endl;
}