#include <iostream>
using namespace std;

int a, b, c; //a-������ �����, b-������ �����, c-������ �����.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "����� ������, ������ � ������ �����." << endl;
	cin >> a >> b >> c;
	(a > b ? (a > c ? cout << "������������ �����- " << a :
		cout << "������������ �����- " << c) : (b > c ? cout << "������������ �����- " << b :
			cout << "������������ �����- " << c));
	return 0;
}