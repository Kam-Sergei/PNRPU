#include <iostream>
using namespace std;

int sum, n, p; //sum-����� ������������, n-���������� ������������, p-������������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ���������� ������������"<<endl;
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; i++)
	{
		p = 1;
		for (int j = i; j <= (i * 2); j++)
		{
			p = p * j;
		}
		sum = sum + p;
	}
	cout << "����� = " << sum;
	return 0;
}