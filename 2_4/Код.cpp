#include <iostream>
using namespace std;

int n; //n-����� ���������.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ����� ���������"<<endl;
	cin >> n;
	int space = n / 2; //���������� " ".
	int star = 1;  //���������� "*".
	if ((n <= 3) or (n % 2 == 0))
	{
		cout << "������! (�� ����������� ������� ������)";
	}
	else
	{
		for (int i = 1; i <= (n + 1) / 2; i++)
		{
			for (int j = 1; j <= space; j++)
			{
				cout << " ";
			}
			space--;
			for (int j = 1; j <= star; j++)
			{
				cout << "*";
			}
			star += 2;
			cout << endl;
		}
	}
	return 0;
}