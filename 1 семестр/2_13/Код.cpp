#include <iostream>
using namespace std;

float a, b, c,d; //a,b,c-коэффициенты. d-дискриминант.

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите коэффициенты уравнения (a*x^2 + b*x + c = 0):" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	d = b * b - 4 * a * c;
	cout << "Дискриминант= " << d<<endl;
	if (d < 0)
	{
		cout << "Дискриминант < 0, следовательно корней нет.";
	}
	else if (d == 0)
		{
			cout << "Дискриминант = 0, следовательно уравнение имеет один корнь:"<<endl;
			cout << "x= " << (-1*b) / (2 * a);
		}
	else
	{
		cout << "Дискриминант >0, следовательно уравнение имеет два корня:" << endl;
		cout << "x(1)= " << (-1 * b + sqrt(d)) / (2 * a) << endl;
		cout << "x(2)= " << (-1 * b - sqrt(d)) / (2 * a);
	}
	return 0;
}
