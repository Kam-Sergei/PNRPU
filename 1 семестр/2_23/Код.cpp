#include <iostream>
#include<cmath>

using namespace std;
int k; // k-���������� ���������, ����������� � ������������.
float n, a; //n-���������� ��������� � ������������������. �-������� ������������������.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ��������� � ������������������ n : n= ";
	cin >> n;
	int i = 1;
	float max = 0; //max-������������ ������� ������������������.
	cout << "������������������:" << endl;
	while (i <= n)
	{
		a = sin(n + i / n);
		cout << a << " ";
		if (i == 1)
		{
			max = a;
			k = 1;
		}
		else if (a > max)
		{
			max = a;
			k = 1;
		}
		else if (a == max)
		{
			k = k + 1;
		}
		i++;
	}
	cout <<endl<<"������������ �������� � ������������������: " << max << endl;
	cout << "���������� ���������, ����������� � ������������: " <<k<<endl;
	return 0;
}