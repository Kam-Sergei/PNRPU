#include <iostream>
#include <random>
using namespace std;

int n,a,m; //n-количество элементов в последовательности. m-первый максимальный элемент.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите количество элементов в последовательности" << endl;
	cin >> n;
	cout << "Введите последовательность:"<<endl;
	cin >> a;
	int max = a; //max-максимальное значение.
	m = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> a ;
		if (a > max)
		{
			max = a;
			m = i;
		}
	}
	cout << "Максимальное значение: " << max<<endl;
	cout << "Первый максимальный элемент: " << m;
	return 0;
}
