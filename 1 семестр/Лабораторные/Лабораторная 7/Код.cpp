#include <iostream>

using namespace std;
int n,a,b;
void f(int n)
{
	if (n % a != 0 or n % b != 0)
	{
		n++;
		f(n);
	}
	else
	{
		cout <<"НОК ("<<a<<";"<<b<<") = "<< n;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите первое число a: a = ";
	cin >> a;
	cout << "Введите второе число b : b = ";
	cin >> b;
	n = 1;
	f(n);
	return 0;
}
