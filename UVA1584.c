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
		scanf("%s", &str);
		int leng = strlen(str);
		int min = 0;//目前最小的字典序是從哪裡開始

		for (int i = 1; i < leng; i++)
		{
			for (int j = 0; j < leng ; j++)
			{
				if (str[(i + j) % leng] < str[(j + min) % leng])
				{
					min = i;
					break;
				}
				else if (str[(i + j) % leng] == str[(j + min) % leng])
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		for (int x = 0; x < leng; x++)
		{
			printf("%c", str[(x + min) % leng]);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}