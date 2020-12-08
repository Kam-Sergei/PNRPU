#include <iostream>
using namespace std;

float a, max, min; //a-элемент последовательности.
int n; //n-количество положительных элементов в последовательности. 
                
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "¬ведите количество положительных элементов в последовательности" << endl;
	cin >> n;
	cout << "¬ведите последовательность"<<endl;
	cin >> a;
	float max = a; //max-максимальный элемент.
	float min = a; //min-минимальный элемент.
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	cout << "—умма максимального и минимального элементов = " << max + min;
	return 0;
}