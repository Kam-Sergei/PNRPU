#include <iostream>

using namespace std;
int n,a,b; //n-n.
void f(int n)
{
	if (n % a != 0 or n % b != 0)
	{
		n++;
		f(n);
	}
	else
	{
		cout <<"��� ("<<a<<";"<<b<<") = "<< n;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ������ ����� a: a = ";
	cin >> a;
	cout << "������� ������ ����� b : b = ";
	cin >> b;
	n = 1;
	f(n);
	return 0;
}