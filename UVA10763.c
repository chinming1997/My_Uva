#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<map>
#include<string>
#include<algorithm>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005


int main()
{
	int num;
	while (cin >> num)
	{
		if (num == 0) break;
		map<int, int>location;

		int p1, p2;
		while (num--)
		{
			cin >> p1 >> p2;
			location[p1]--;
			location[p2]++;
		}
		bool sucess = true;
		for (auto p : location)
		{
			if (p.second!=0)
			{
				sucess = false;
				break;
			}
		}
		if (!sucess)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}

	return 0;
}