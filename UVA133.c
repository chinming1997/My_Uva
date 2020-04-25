#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
#include <iomanip>

using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005

int main()
{
	int N;
	int right;
	int left;

	while (cin >> N >> right >> left)
	{
		if (N == 0)
		{
			break;
		}
		bool num[25] = { false };
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			num[i] = true;
		}
		int first = 0;
		int last = N+1;

		while (count < N)
		{
			for (int n = 0; n < right; n++)
			{
				first++;
				if (first > N)
				{
					first = 0;
				}
				if (num[first] == false)
				{
					n -= 1;
				}
			}
			for (int j = 0; j < left; j++)
			{
				last--;
				if (last < 0)
				{
					last = N + 1;
				}
				if (num[last] == false)
				{
					j -= 1;
				}

			}
			if (first != last)
			{
				cout << setw(3) << first << setw(3) << last;
				num[first] = false;
				num[last] = false;
				count += 2;
			}
			else
			{
				cout << setw(3) << first;
				num[last] = false;
				count++;
			}
			if (count < N)
			{
				cout << ",";
			}
			
	
		}
		cout << endl;
	}


	system("pause");
	return 0;
}