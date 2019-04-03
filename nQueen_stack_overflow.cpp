#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int number = 0;

struct Queen
{
	Queen(int xx, int yy) : x(xx), y(yy) { }
	bool operator==(const Queen& q);
	bool operator!=(const Queen& q);
	Queen& operator=(const Queen& q);
	int x;
	int y;
};

bool Queen::operator==(const Queen& q)
{
	return (q.x == x || q.y == y || abs(q.y - y) == abs(q.x - x));
}

bool Queen::operator!=(const Queen& q)
{
	return !(*this == q);
}

Queen& Queen::operator=(const Queen& q)
{
	x = q.x;
	y = q.y;

	return *this;
}

void _nQueen(vector<Queen> result, Queen& q, int n)
{
	if (q.x == 0 && q.y == n)
		return;

	while (q.y < n)
	{
		//if (find_if(result.begin(), result.end(), [q](Queen value){ return value == q; }) != result.end())
		if (find(result.begin(), result.end(), q) != result.end())
		{
			++q.y;
		}
		else 
		{
			break;
		}
	}
	if (q.y < n)
	{
		result.push_back(q);
		if (result.size() == n)
		{		
			++number;
			q = result.back();
			++q.y;
			result.pop_back();
			_nQueen(result, q, n);
		}
		else 
		{
			++q.x; q.y = 0;
			_nQueen(result, q, n);
		}
	}
	else
	{
		q = result.back();
		++q.y;
		result.pop_back();
		_nQueen(result, q, n);
	}

}

int nQueen(int n)
{
	int i = 0;
	vector<Queen> result;
	Queen q(0, 0);

	_nQueen(result, q, n);

	return number;
}

int main()
{
	cout << nQueen(9) << endl;

	return 0;
}