#include <iostream>
using namespace std;

int n; //n-длина катета.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите длину катета" << endl;
	cin >> n;
	if (n <= 2)
	{
		cout << "Ошибка! (не удовлетворяет условию задачи)";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <=i ; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
	return 0;
}
