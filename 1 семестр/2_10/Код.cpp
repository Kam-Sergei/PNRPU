#include <iostream>
#include <random>
using namespace std;

int n,a,m; //n-���������� ��������� � ������������������. m-������ ������������ �������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ���������� ��������� � ������������������" << endl;
	cin >> n;
	cout << "������� ������������������:"<<endl;
	cin >> a;
	int max = a; //max-������������ ��������.
	m = 1;
	for (int i = 2; i <= n; i++)
	{
		cin >> a ;
		if (a > max)
		{
			max = a;
			m = i;
		}
	}
	cout << "������������ ��������: " << max<<endl;
	cout << "������ ������������ �������: " << m;
	return 0;
}