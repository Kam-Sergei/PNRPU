#include <iostream>
using namespace std;

int n,s; //n-натуралльное число. s-сумма.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬ведите натуралльное число n : ";
	cin >> n;
	s = 0;
	while (n > 0)
	{
		s = s + (n % 10);
		n = n / 10;
	}
	cout << "—умма цифр чисела n = "<<s;
	return 0;
}