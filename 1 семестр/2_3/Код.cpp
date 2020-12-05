#include <iostream>
using namespace std;

int sum, n, p; //sum-сумма произведений, n-количество произведений, p-произведение.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите количество произведений"<<endl;
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		p = 1;
		for (int j = i; j <= (i * 2); j++)
		{
			p = p * j;
		}
		sum = sum + p;
	}
	cout << "Сумма = " << sum;
	return 0;
}