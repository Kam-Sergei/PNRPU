#include <iostream>
#include<cmath>

using namespace std;

int a,b; //�,b-�������� ������������������.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "����� ������������������:" << endl;
	bool found1 = false;
	bool found2 = true;
	cin >> b;
	if (b == 0)
	{
		found1 = true;
	}
	while (found1 == false)
	{
		cin >> a;
		if (a == 0)
		{
			found1 = true;
		}
		if (a < b && a!=0)
		{
			found2 = false;
		}
		b = a;
	}
	if (found2 == true)
	{
		cout << "����� � ������������������ ����������� �� �����������";
	}
	else
	{
		cout << "����� � ������������������ �� ����������� �� �����������";
	}
	return 0;
}