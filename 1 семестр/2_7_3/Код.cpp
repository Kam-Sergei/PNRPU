#include <iostream>
using namespace std;

int n; //n-����� ������� ��������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ����� ������� ��������" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "* ";
	}
	cout << endl;
	for (int i = 1; i <= n-2; i++)
	{
		cout << "* ";
		for (int j = 1; j <= n-2; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "* ";
	}
	return 0;
}