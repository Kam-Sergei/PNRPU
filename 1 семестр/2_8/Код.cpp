#include <iostream>
using namespace std;

int n; //n-����� ������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ����� ������" << endl;
	cin >> n;
	if (n <= 2)
	{
		cout << "������! (�� ������������� ������� ������)";
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