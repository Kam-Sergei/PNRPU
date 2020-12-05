#include <iostream>
using namespace std;

int n; //n-длина стороны куба.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬ведите длину стороны куба" << endl;
	cin >> n;
	int h = (n+1) / 2;
	if (n <= 4)
	{
		cout << "ќшибка! (не удовлетвор€ет условию задачи)";
	}
	else
	{
		for (int i = 1; i < h; i++)
		{
			cout << " ";
		}
		for (int i = 1; i <= n; i++)
		{
			cout << "* ";
		}
		cout << endl;
		for (int i = 1; i <= h - 2; i++)
		{
			for (int j = 1; j <= (h - i - 1); j++)
			{
				cout << " ";
			}
			cout << "*";
			for (int j = 1; j <= n - 2; j++)
			{
				cout << "  ";
			}
			cout << " " << "*";
			for (int j = 1; j < i; j++)
			{
				cout << " ";
			}
			cout << "*";
			cout << endl;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << "* ";
		}
		for (int i = 1; i < h - 2; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
		for (int i = 1; i <= n - h; i++)
		{
			cout << "*";
			for (int j = 1; j <= 2 * n - 3; j++)
			{
				cout << " ";
			}
			cout << "*";
			for (int j = 1; j <= h - 2; j++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}
		for (int i = 1; i <= h - 2; i++)
		{
			cout << "*";
			for (int j = 1; j <= 2 * n - 3; j++)
			{
				cout << " ";
			}
			cout << "*";
			for (int j = 1; j <= h-i-2;j++)
			{
				cout << " ";
			}
			cout << "*"<<endl;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << "* ";
		}
	}
	return 0;
}