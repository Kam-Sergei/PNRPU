# include <iostream>

using namespace std;

int a1, a2, b1, b2;
float a, b;

float f(int a1, int a2, int b1, int b2)
{
	return ((a1 * 1.0 / b1) - (a2 * 1.0 / b2));
}

float f(float a, float b)
{
	return a - b;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "��������� ���������� ������:" << endl;
	cout << "������� �����������: ";
	cin >> a;
	cout << "������� ����������: ";
	cin >> b;
	cout << "�������� = ";
	cout << f(a, b)<<endl<<endl;
	cout << "��������� ������������ ������:" << endl;
	cout << "�����������: "<<endl;
	cout << "������� �������: ";
	cin >> a1;
	cout << "������� ��������: ";
	cin >> b1;
	cout << "����������: " << endl;
	cout << "������� �������: ";
	cin >> a2;
	cout << "������� ��������: ";
	cin >> b2;
	cout << "�������� = ";
	cout << f(a1, a2, b1, b2) << endl;
	return 0;
}