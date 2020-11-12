#include <iostream>
using namespace std;

int n; //n-длина основания.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите длину основания"<<endl;
	cin >> n;
	int space = n / 2; //количество " ".
	int star = 1;  //количество "*".
	if ((n <= 3) or (n % 2 == 0))
	{
		cout << "Ошибка! (не выполняется условие задачи)";
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