#include <iostream>
using namespace std;

float a, max, min; //a-������� ������������������.
int n; //n-���������� ������������� ��������� � ������������������. 
                
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ���������� ������������� ��������� � ������������������" << endl;
	cin >> n;
	cout << "������� ������������������"<<endl;
	cin >> a;
	float max = a; //max-������������ �������.
	float min = a; //min-����������� �������.
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	cout << "����� ������������� � ������������ ��������� = " << max + min;
	return 0;
}