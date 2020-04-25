#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
#include <iomanip>
#include <set>
using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005

int main()
{

	set<string> dic;
	string content;
	while (getline(cin, content))
	{
		
		string word = "";
		for (int i = 0; i < content.size(); i++)
		{
			if (isalpha(content[i]))
			{
				word += tolower(content[i]);
			}
			else
			{
				if (word != "")
				{
					dic.insert(word);
					word = "";
				}
			}
		}
		if (word != "")
		{
			dic.insert(word);
		}
	}
	for (set<string>::iterator it = dic.begin(); it != dic.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}