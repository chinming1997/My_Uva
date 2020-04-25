#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;
#pragma warning( disable : 4996 )

int main()
{
	char str[105];
	memset(str, 0, sizeof(str));
	int n;
	cin >> n;
	while (n--)
	{
		scanf("%s", str);
		int count = 0;
		int sum = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'O')
			{
				count++;
				sum += count;
			}
			else
			{
				count = 0;
			}
		}
		cout << sum << endl;

	}
	
	system("pause");
	return 0;
}