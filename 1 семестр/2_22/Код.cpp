#include <iostream>
#include<cmath>

using namespace std;
int j; // j-номер максимального элемента в последовательности.
float n, z, a; //n-количество элементов в последовательности. z-число. а-элемент последовательности.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите количество элементов в последовательности n : n= ";
	cin >> n;
	int i = 1;
	float max=0; //max-максимальный элемент последовательности.
	cout << "ѕоследовательность:"<<endl;
	while (i <= n)
	{
		a = sin(n + i / n);
		cout << a<<" ";
		if (i == 1)
		{
			max = a;
			j = i;
		}
		else if (a > max)
		{
			max = a;
			j = i;
		}
		i++;
	}
	cout <<endl<< "Ќомер максимального значени€ в последовательности: "<<j<<endl;
	cout << "ћаксимальное значение в последовательности: "<<max<<endl;
	return 0;
}