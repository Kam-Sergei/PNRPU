#include <iostream>
using namespace std;

int n, z; //n-натуралльное число. z-цифра.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬ведите натуралльное число (n) : ";
	cin >> n;
	cout << "¬ведите цифру (z) : ";
	cin >> z;
	while (n > 0)
	{
		if (n%10==z)
			{
			cout << "÷ифра "<< z <<" входит в число";
			n = 0;
			}
		else
		{
			n = n / 10;
			if (n==0)
				{
					cout << "÷ифра " << z << " не входит в число";
				}
		}
	}
	return 0;
}