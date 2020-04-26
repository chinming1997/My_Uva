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
#include<iterator>
#include<math.h>
using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005

int binToDec(string s) { 
	int ret = 0;
	for (auto ch : s) ret = ret * 2 + (ch - '0');
	return ret;
}

int main()
{
	vector<string>bsv;
	map<string, char>mp;
	for (int i = 1; i < 8; i++) //長度1~7
	{
		int num = 0;//從0開始
		int count = pow(2, i) - 1;//有幾個
		for (int j = 0; j < count; j++)
		{
			int temp = num;
			string code = "";
			do
			{
				code += (temp % 2) + '0';
				temp /= 2;

			} while (temp != 0);
			reverse(code.begin(), code.end());
			code = string(i - code.size(), '0') + code;
			bsv.push_back(code);
			num += 1;
		}
	}
	string head = "";
	string message = "";
	string s = "";
	string t = "";

	getline(cin, head);
	while (true)
	{
		while (getline(cin, s) && (s[0] == '0' || s[0] == '1')) message += s; //把切散的訊息拼接起來
		if (message.empty()) break; //結束

		for (int i = 0; i < head.size(); i++)
		{
			mp[bsv[i]] = head[i];//建立對映的字典
		}
		int end = 0;
		while (end < message.size())
		{
			t = message.substr(end,3);//切出前三個當做leng的判斷
			end += 3;
			if (t == "000")break;
			else
			{
				int leng = binToDec(t);
				while (end < message.size())
				{
					t = message.substr(end, leng);
					end += leng;
					if (t == string(leng, '1')) break; // leng個1表示此section結束
					else cout << mp[t];
				}
			}
		}
		cout << endl;
		head = s;//getline已讀入
		mp.clear();
		message.clear();
	}


	system("pause");
	return 0;
}