#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;
#pragma warning( disable : 4996 )

bool period(char str[], int len)
{
	int i;
	for (i = len; i < strlen(str); i++)
	{
		if (str[i] != str[i%len])
		{
			break;
		}
	}
	if (i == strlen(str))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	char str[105];
	memset(str, 0, sizeof(str));
	int n;
	cin >> n;
	while (n--)
	{
		scanf("%s", str);
		int ans = 0;
		for (int j = 1; j <= strlen(str) / 2; j++)
		{
			if (strlen(str) % j == 0)
			{
				if (period(str, j))
				{
					ans = j;
					break;
				}
			}
		}
		if (!ans)
		{
			cout << strlen(str) << endl;
		}
		else
		{
			cout << ans << endl;
		}
		if (n) {cout<<endl;}
	}
	
	system("pause");
	return 0;
}