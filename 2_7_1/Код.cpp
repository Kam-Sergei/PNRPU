#include <iostream>
#include <math.h>
using namespace std;

int n; //n-количество звЄздочек.
float k; //k - длина стороны квадрата.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬ведите количество звЄздочек" << endl;
	cin >> n;
	k = sqrt(n);
	if (1.0*k*k != n)
	{
		cout << "ќшибка! (не верное количество звЄздочек)";
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}