#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> getNext(string s)
{
	vector<int> next(s.length(), -1);
	next[1] = 0;

	for (int i = 1; i < s.length(); ++i)
	{
		if (next[i - 1] == -1 || s[i] == s[next[i - 1] + 1])
		{	
			next[i] = next[i - 1] + 1;
		}
		else
		{
			next[i] = 0;
		}
	}

	return next;
}

vector<int> getNext2(string ps)
{
	vector<int> next;

	// 初始条件
	int j = 0;
	int k = -1;
	next[0] = -1;

	// 根据已知的前j位推测第j+1位
	while (j < ps.length() - 1)
	{
		if (k == -1 || ps[j] == ps[k])
		{
			next[++j] = ++k;
		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

int main()
{
	string s;

	while (cin >> s)
	{
		vector<int> next = getNext(s);
		vector<int> next2 = getNext(s);

		for (auto i : next)
			cout << i << " ";
		cout << endl;

		for (auto i : next2)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
