
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

bool IsPrime(int number);

int main()
{
	int n = 1;
	while (n > 0)
	{
		cout << "enter n: ";
		
		cin >> n;


		int unsafeCount = 0; //begin at 3 since points (0,0), (0,1), (1,0)
		list<pair<int, int>> grid;

		//creating a triangular grid of test points. according to symmetry, we will test these points and double them for the number
		for (int y = 1; y <= n; y++)
		{
			if (y != 1 && !IsPrime(y))
			{
				for (int x = 1; x <= y; x++)
				{
					if (!(x % 2 == 0 && y % 2 == 0) && !(x % 3 == 0 && y % 3 == 0) && !(x % 5 == 0 && y % 5 == 0) && !(x % 7 == 0 && y % 7 == 0))
					{
						if (x == 1)
						{
							//check rise / run ==> y / x 
							unsafeCount += 1;
							//cout << "(" << x << ", " << y << "), ";
						}
						else if (y % x != 0)
						{
							unsafeCount += 1;
							//cout << "(" << x << ", " << y << "), ";
						}
					}
					if (x == y) cout << "(" << x << ", " << y << "), " << endl;
				}
			}
			else
			{
				unsafeCount += (y-1);
			}
			
		}
		cout << endl << ((unsafeCount - 1) * 2) + 4 << endl; // subtract 1 for (1,1) multiply by 2 for symmetry, add 4 for (0,0), (1,0), (0,1), (1,1)
	}

	cout << endl;
	system("PAUSE");
	return 0;
}


bool IsPrime(int number)
{	// Given:   num an integer > 1
	// Returns: true if num is prime
	// 			false otherwise.

	int i;

	for (i = 2; i<number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}