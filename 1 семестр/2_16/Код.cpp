#include <iostream>
using namespace std;

int n, s; //n-���������� ���������. s-�����.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ���������� ��������� (n) : ";
	cin >> n;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			s += i;
		}
		else
		{
			s -= i;
		}
	}
	cout <<"����� (s) = "<< s;
	return 0;
}