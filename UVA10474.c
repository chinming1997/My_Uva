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
	int N, Q;
	int Case = 1;
	while (cin >> N >> Q)
	{
		int marmarbles[maxn];
		memset(marmarbles, 0, sizeof(marmarbles));
		if (N == 0)
		{
			break;
		}
		cout << "CASE# " << Case++ << ":" << endl;

		for (int i = 0; i < N; i++)
		{
			cin >> marmarbles[i];
		}
		sort(marmarbles, marmarbles + N);
		int query;
		for (int j = 0; j < Q; j++)
		{
			cin >> query;
			int *ptr = lower_bound(marmarbles, marmarbles + N, query);
			if (ptr == marmarbles + N || *ptr != query)
			{
				cout << query << " not found" << endl;
			}
			else
			{
				cout << query << " found at " << ptr - marmarbles + 1 << endl;
			}
		}

	}


	system("pause");
	return 0;
}