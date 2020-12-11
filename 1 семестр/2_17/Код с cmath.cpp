#include <iostream>
#include<cmath>

using namespace std;

int n; //n-n.
float x, fact, y; //x-x. fact-факториал. y-значение многочлена.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите n : n = ";
	cin >> n;
	cout << "Введите x : x = ";
	cin >> x;
	y = 1;
	fact = 1;
	for (int i = 1; i < n; i++)
	{
		fact *= i;
		y += (pow(x, i) / fact);
	}
	cout << "Значение многочлена = " << y;
	return 0;
}
