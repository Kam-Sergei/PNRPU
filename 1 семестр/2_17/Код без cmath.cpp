#include <iostream>

using namespace std;

int n; //n-n.
float x, fact, y ,p; //x-x. fact-факториал. y-значение многочлена. p-x^i.

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
		p = 1;
		for (int j = 1; j <= i; j++)
		{
			p *= x;
		}
		y += (p / fact);
	}
	cout <<"Значение многочлена = "<< y;
	return 0;
}
