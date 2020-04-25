#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning( disable : 4996 )
#define maxn 10005


int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 0)
		{
			break;
		}
		cout << "Round " << n << endl;
		int strokes = 7;
		int count = 0;
		
		int letter[26];
		memset(letter, 0, sizeof(letter));

		string ans;
		string guest;
		char c = getchar();
		getline(cin, ans);
		getline(cin, guest);
		int leng = 0;

		for (int j = 0; j < ans.size(); j++)
		{
			if (!letter[ans[j] - 'a'])
			{
				letter[ans[j] - 'a'] ++;
				leng++;//需要猜幾個英文單字
			} 
		}

		for (int n = 0; n < guest.size(); n++)
		{
			bool check = false;//有無猜到

			if (letter[guest[n] - 'a'] > 0)
			{
				count++;
				check = true;
				letter[guest[n] - 'a']--;
			}
			else if(!check)
			{
				strokes--;
			}
			if (count == leng || strokes==0)
			{
				break;
			}
		}

		if (strokes == 0)
		{
			cout << "You lose."<<endl;
		}
		else if (strokes != 0 && count != leng)
		{
			cout << "You chickened out." << endl;
		}
		else 
		{
			cout << "You win." << endl;
		}
		

	}
	
	
	system("pause");
	return 0;
}