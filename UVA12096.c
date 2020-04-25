#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<map>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<vector>
#include<stack>
#include <iterator>

using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef set<int> Set; // set<int> = Set
map <Set, int> IDCache;//把集合映射成ID
vector <Set> Setcache;//存放集合 

int ID(Set x)
{
	if (IDCache.count(x))
	{
		return IDCache[x];
	}
	Setcache.push_back(x);
	IDCache[x] = Setcache.size() - 1;
	return IDCache[x];
}

int main()
{
	int T;
	int n;
	cin >> T;
	while (T--)
	{
		stack <int> s; // 放ID
		cin >> n;
		char c = getchar();
		while (n--)
		{
			string op = "";
			getline(cin, op);
			if (op == "PUSH") s.push(ID(Set()));
			else if (op == "DUP") s.push(s.top());
			else
			{
				Set x1 = Setcache[s.top()];
				s.pop();
				Set x2 = Setcache[s.top()];
				s.pop();
				Set x;
				if (op == "UNION")
				{
					set_union(ALL(x1), ALL(x2), INS(x));
				}
				else if (op == "INTERSECT")
				{
					set_intersection(ALL(x1), ALL(x2), INS(x));
				}
				else // add
				{
					x = x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}

	return 0;
}