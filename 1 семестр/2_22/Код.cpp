#include <iostream>
#include<cmath>

using namespace std;
int j; // j-����� ������������� �������� � ������������������.
float n, z, a; //n-���������� ��������� � ������������������. z-�����. �-������� ������������������.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ��������� � ������������������ n : n= ";
	cin >> n;
	int i = 1;
	float max=0; //max-������������ ������� ������������������.
	cout << "������������������:"<<endl;
	while (i <= n)
	{
		a = sin(n + i / n);
		cout << a<<" ";
		if (i == 1)
		{
			max = a;
			j = i;
		}
		else if (a > max)
		{
			max = a;
			j = i;
		}
		i++;
	}
	cout <<endl<< "����� ������������� �������� � ������������������: "<<j<<endl;
	cout << "������������ �������� � ������������������: "<<max<<endl;
	return 0;
}