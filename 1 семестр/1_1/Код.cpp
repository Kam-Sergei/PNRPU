#include <iostream>
using namespace std;

int a, b, c; //a-первое число, b-второе число, c-третье число.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введи первое, второе и третье число." << endl;
	cin >> a >> b >> c;
	(a > b ? (a > c ? cout << "Максимальное число- " << a :
		cout << "Максимальное число- " << c) : (b > c ? cout << "Максимальное число- " << b :
			cout << "Максимальное число- " << c));
	return 0;
}
