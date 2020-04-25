#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005

char input[maxn];
char test[maxn];

int main()
{
	
	memset(input, 0, sizeof(input));
	memset(test, 0, sizeof(test));
	while (cin>>input>>test)
	{
		int index = 0;
		int count = 0;
		for (int i = 0; i < strlen(input); i++)
		{
			for (int j = index; j < strlen(test); j++)
			{
				if (input[i] == test[j])
				{
					index = ++j;
					count++;
					break;
				}
			}
		}
		if (count == strlen(input))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	
	system("pause");
	return 0;
}