#include <iostream>
#include<cmath>

using namespace std;
int k; // k-количество элементов, совпадающих с максимальным.
float n, a; //n-количество элементов в последовательности. а-элемент последовательности.

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите количество элементов в последовательности n : n= ";
	cin >> n;
	int i = 1;
	float max = 0; //max-максимальный элемент последовательности.
	cout << "ѕоследовательность:" << endl;
	while (i <= n)
	{
		a = sin(n + i / n);
		cout << a << " ";
		if (i == 1)
		{
			max = a;
			k = 1;
		}
		else if (a > max)
		{
			max = a;
			k = 1;
		}
		else if (a == max)
		{
			k = k + 1;
		}
		i++;
	}
	cout <<endl<<"ћаксимальное значение в последовательности: " << max << endl;
	cout << " оличество элементов, совпадающих с максимальным: " <<k<<endl;
	return 0;
}