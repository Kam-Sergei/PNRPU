# include <iostream>

using namespace std;

int a1, a2, b1, b2;
float a, b;

float f(int a1, int a2, int b1, int b2)
{
	return ((a1 * 1.0 / b1) - (a2 * 1.0 / b2));
}

float f(float a, float b)
{
	return a - b;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Вычитание десятичных дробей:" << endl;
	cout << "Введите уменьшаемое: ";
	cin >> a;
	cout << "Введите вычитаемое: ";
	cin >> b;
	cout << "Разность = ";
	cout << f(a, b)<<endl<<endl;
	cout << "Вычитание обыкновенных дробей:" << endl;
	cout << "Уменьшаемое: "<<endl;
	cout << "Введите делимое: ";
	cin >> a1;
	cout << "Введите делитель: ";
	cin >> b1;
	cout << "Вычитаемое: " << endl;
	cout << "Введите делимое: ";
	cin >> a2;
	cout << "Введите делитель: ";
	cin >> b2;
	cout << "Разность = ";
	cout << f(a1, a2, b1, b2) << endl;
	return 0;
}
