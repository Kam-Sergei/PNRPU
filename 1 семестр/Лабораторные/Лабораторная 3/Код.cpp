#include <iostream>
#include <string>
using namespace std;

int a[100];
int n, k, m;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ��������� � ������: n=";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i] = rand() % 100 - 50;
		cout << a[i] << " ";
	}
	int max = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[max])
		{
			max = i;
		}
	}
	cout << endl;
	cout << "�������� " << max << " (�������������) �������� �������:";
	cout << endl;
	for (int i = max; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	n = n - 1;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "������� ���������� ��������� ��� ���������� � ������: k=";
	cin >> k;
	for (int i = n + 1; i <= (n + k); i++)
	{
		a[i] = rand() % 100 - 50;
	}
	n = k + n;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "������� �� ������� ��������� ���� �������� ������ �����: m=";
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		a[n + i] = a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i + m];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 0)
		{
			cout << endl;
			cout << "������ ������������� �������= " << a[i] << endl;
			cout << "���������� ��������= " << i;
			i = n;
		}
	}
	cout << endl;
	int b = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[j] > a[j + 1])
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	cout << "������ ����� ���������� ������� �������:" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 0)
		{
			cout << endl;
			cout << "������ ������������� �������= " << a[i] << endl;
			cout << "���������� ��������= " << i;
			i = n;
		}
	}
	return 0;
}