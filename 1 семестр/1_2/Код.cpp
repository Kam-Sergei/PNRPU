#include <iostream>
#include <math.h>
using namespace std;

int a, b;  //a-�������, b-��������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "����� ������� � ��������." << endl;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "������! (�� 0 ������ ������)";
	}
	else
	{
		cout << (1.0 * a / b);
	}
	return 0;
}