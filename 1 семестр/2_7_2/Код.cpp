#include <iostream>
using namespace std;

int n; //n-длина стороны квадрата.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите длину квадрата" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
