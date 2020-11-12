#include <iostream>
#include <math.h>
using namespace std;

int a, b;  //a-делимое, b-делитель.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬веди делимое и делитель." << endl;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "ќшибка! (на 0 делить нельз€)";
	}
	else
	{
		cout << (1.0 * a / b);
	}
	return 0;
}