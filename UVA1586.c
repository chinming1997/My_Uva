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
		
		int total = 0;
		double now = 0;
		double sum = 0;
		bool code = false;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				total *= 10;
				total += str[i] - '0';
			}
			else 
			{
				if (code)
				{
					if(total) sum += total * now;
					else sum += now;
					total = 0;
				}
				if(str[i] == 'C') { now = 12.01; }
				else if(str[i] == 'H') { now = 1.008; }
				else if(str[i] == 'O') { now = 16.00; }
				else { now = 14.01; }
				code = true;
			}
		}
		if (code)
		{
			if (total) sum += total * now;
			else sum += now;
		}

		printf("%.3lf\n",sum);
	}
	
	system("pause");
	return 0;
}