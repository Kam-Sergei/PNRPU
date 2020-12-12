#include <iostream>
#include<cmath>

using namespace std;

float n,z, a ; //n-количество элементов в последовательности. z-число. а-элемент последовательности.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите количество элементов в последовательности n : n= ";
	cin >> n;
	cout << "¬ведите z : z = ";
	cin >> z;
	int i = 1;
	bool found = false;
	while (i<=n && found==false)
	{
		a = sin(n + i / n);
		if (a == z)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found==true)
	{
		cout << "Ёлемент равный " << z << " есть в последовательности";
	}
	else
	{
		cout << "Ёлемента равного " << z << " нет в последовательности";
	}
	return 0;
}