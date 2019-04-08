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

int find(string s, string p)
{
	int i = 0, j = 0;

	vector<int> next = getNext(p);

	while (i < s.length() && j < p.length())
	{
		if (s[i] == p[j])
		{
			++i;
			++j;
		}
		else
		{
			if (next[j] == -1)
			{
				i++;
				j = 0;
			}
			else 
				j = next[j];
		}
	}

	if (j == p.length())
		return i - p.length();
	else
		return -1;
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
	string s, p;

	while (cin >> s >> p)
	{
		cout << find(s, p) << endl;
	}

	return 0;
}
