#include <iostream>
using namespace std;

int n; //n-����� ������� ��������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ����� ��������" << endl;
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