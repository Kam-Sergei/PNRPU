#include <iostream>
using namespace std;

int n,s; //n-������������ �����. s-�����.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ������������ ����� n : ";
	cin >> n;
	s = 0;
	while (n > 0)
	{
		s = s + (n % 10);
		n = n / 10;
	}
	cout << "����� ���� ������ n = "<<s;
	return 0;
}