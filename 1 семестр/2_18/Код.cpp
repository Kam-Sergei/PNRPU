#include <iostream>

using namespace std;

int n; //n-натуральное число.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите натуральное число n: ";
	cin >> n;
	cout << "Обратный порядок цифр числа n: ";
	while (n > 0)
	{
		cout << n % 10;
		n = n / 10;
	}
	return 0;
}