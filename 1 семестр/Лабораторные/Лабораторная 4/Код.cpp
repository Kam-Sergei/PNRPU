#include <iostream>
#include <string>
using namespace std;

int a[100];
int  n,k;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов массива: n=";
	cin >> n;
	k = n - 4;
	for (int i = 1; i <= n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl << "Удаление 5 первых элементов массива:" << endl;
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i+5];
	}
	for (int i = 1; i <= n-5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Добавление в конец 3 новых элементов массива:" << endl;
	for (int i = k ; i <= k+2; i++)
	{
		a[i] = rand() % 100;
	}
	for (int i = 1; i <= n -2; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}