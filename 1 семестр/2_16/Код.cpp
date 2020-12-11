#include <iostream>
using namespace std;

int n, s; //n-количество слагаемых. s-сумма.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите количество слагаемых (n) : ";
	cin >> n;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			s += i;
		}
		else
		{
			s -= i;
		}
	}
	cout <<"Сумма (s) = "<< s;
	return 0;
}
