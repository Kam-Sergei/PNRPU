#include <iostream>
using namespace std;

int n, z; //n-������������ �����. z-�����.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ������������ ����� (n) : ";
	cin >> n;
	cout << "������� ����� (z) : ";
	cin >> z;
	while (n > 0)
	{
		if (n%10==z)
			{
			cout << "����� "<< z <<" ������ � �����";
			n = 0;
			}
		else
		{
			n = n / 10;
			if (n==0)
				{
					cout << "����� " << z << " �� ������ � �����";
				}
		}
	}
	return 0;
}