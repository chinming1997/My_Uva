#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;
#define maxn 100005

int Generator[maxn] ;


int main()
{
	memset(Generator, 0, sizeof(Generator));

	for (int n = 1; n < 100001; n++)
	{
		int num = n;
		int ans = n;
		while (num)
		{
			ans += num % 10;
			num /= 10;
		}
		if(!Generator[ans]) Generator[ans] = n;
	}

	int t,q;
	cin >> t;
	while (t--)
	{
		cin >> q;
		cout << Generator[q] << endl;
	}

	system("pause");
	return 0;
}