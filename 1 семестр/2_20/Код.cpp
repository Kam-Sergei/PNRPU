#include <iostream>
#include<cmath>

using namespace std;

float n,z, a ; //n-���������� ��������� � ������������������. z-�����. �-������� ������������������.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ��������� � ������������������ n : n= ";
	cin >> n;
	cout << "������� z : z = ";
	cin >> z;
	int i = 1;
	bool found = false;
	while (i<=n && found==false)
	{
		a = sin(n + i / n);
		if (a == z)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found==true)
	{
		cout << "������� ������ " << z << " ���� � ������������������";
	}
	else
	{
		cout << "�������� ������� " << z << " ��� � ������������������";
	}
	return 0;
}