#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int number = 0;
vector<int> result;

bool isValid(int q)
{
	for (int i = 0; i < result.size(); ++i)
	{
		if (q == result[i] || labs(result.size() - i) == labs(q - result[i]))
			return false;
	}
	return true;
}

void _nQueen(int n)
{
	if (result.size() == n)
	{
		[] () {for (auto i : result ) { cout << i << " "; } cout << endl; }();
		result.pop_back();
		++number;
		return;
	}

	for (int q = 0; q < n; ++q)
	{
		if (isValid(q))
		{
			result.push_back(q);
			_nQueen(n);
		}
	}
	result.pop_back();
}

int nQueen(int n)
{
	if (n < 2)
		return 1;

	_nQueen(n);

	return number;
}

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		int n = atoi(argv[1]); 
		cout << nQueen(n) << endl;
	}
	else 
	{
		cout << nQueen(8) << endl;
	}

	return 0;
}
