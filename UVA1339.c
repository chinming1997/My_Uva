#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005


int main()
{
	int input[26];
	int test[26];

	string str1 = "";
	string str2 = "";

	while (cin>> str1 >> str2)
	{
		bool flag = true;
		memset(input, 0, sizeof(input));
		memset(test, 0, sizeof(test));
		for (int i = 0; i < str1.size(); i++)
		{
			input[str1[i] - 'A']++;
			test[str2[i] - 'A']++;
		}
		sort(input, input + sizeof(input) / sizeof(int));
		sort(test, test + sizeof(test) / sizeof(int));
		for (int j = 25; j >= 0 ; j--)
		{
			if (input[j] != test[j])
			{
				flag = !flag;
				break;
			}
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	
	system("pause");
	return 0;
}