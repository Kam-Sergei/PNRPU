#include <iostream>

using namespace std;

int n; //n-����������� �����.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ����������� ����� n: ";
	cin >> n;
	cout << "�������� ������� ���� ����� n: ";
	while (n > 0)
	{
		cout << n % 10;
		n = n / 10;
	}
	return 0;
}