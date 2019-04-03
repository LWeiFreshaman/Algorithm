#include <iostream>

using namespace std;

char a[8]{0};

bool checkResult(int pos)
{
	for (int i = 0; i < pos; ++i)
	{
		if (a[i] == a[pos] || abs(a[i] - a[pos]) == pos - i)
			return false;
	}
	return true;
}

int eightQueenSimple()
{
	int number = 0;

	for (a[0] = 0; a[0] < 8; ++a[0])
		for (a[1] = 0; a[1] < 8; ++a[1])
			for (a[2] = 0; a[2] < 8; ++a[2])
				for (a[3] = 0; a[3] < 8; ++a[3])
					for (a[4] = 0; a[4] < 8; ++a[4])
						for (a[5] = 0; a[5] < 8; ++a[5])
							for (a[6] = 0; a[6] < 8; ++a[6])
								for (a[7] = 0; a[7] < 8; ++a[7])
								{
									int j = 1;
									for (int i = 1; i < 8; ++i)
									{
										if (!checkResult(i))
										{
											j = 0;
											break;
										}
									}

									if (j == 1)
									{
										for (int i = 0; i < 8; ++i)
										{
											cout << static_cast<int>(a[i]) << " ";
										}
										cout << endl;
										++number;
									}
								}

	return number;
}

int main()
{
	cout << eightQueenSimple() << endl;

	return 0;
}
