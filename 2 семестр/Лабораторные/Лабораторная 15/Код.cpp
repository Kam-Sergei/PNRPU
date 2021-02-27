#include <iostream>
#include <windows.h>
#include<string>
using namespace std;

struct items
{
	string name;   //название предмета
	float weight;  //вес предмета
};

void ShellSort(items* a, int n)
{//Сортировка Шелла
	int b = n / 2;
	while (b > 0)
	{
		for (int i = 0; i < n - b; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j].weight < a[j + b].weight)
				{
					float d = a[j].weight;
					a[j].weight = a[j + b].weight;
					a[j + b].weight = d;
					string f = a[j].name;
					a[j].name = a[j + b].name;
					a[j + b].name = f;
					j -= b;
				}
				else
					j = -1;
			}
		}
		b /= 2;
	}
}

void HoaraSort(items* arr, int left, int right)
{//Сортировка Хоара
	float d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i].weight > arr[(left + right) / 2].weight && i < right)
			i++;
		while (arr[j].weight < arr[(left + right) / 2].weight && j > left)
			j--;
		if (i <= j)
		{
			d = arr[i].weight;
			arr[i].weight = arr[j].weight;
			arr[j].weight = d;
			f = arr[i].name;
			arr[i].name = arr[j].name;
			arr[j].name = f;
			i++;
			j--;
		}
		if (i < right)
		{
			HoaraSort(arr, i, right);
		}
		if (j > left)
		{
			HoaraSort(arr, left, j);
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите количество предметов: ";
	cin >> n;
	cout << "Введите предметы: "<<endl;
	cin.ignore();
	items* st = new items[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Название предмета: ";
		cout << " ";
		getline(cin,st[i].name);
		cout << " Вес предмета: ";
		cin >> st[i].weight;
		cin.ignore();
	}
	int a;
	cout <<endl<< "Операции:"<<endl;
	cout << "1 - сортировка Шелла "<<endl;
	cout << "2 - сортировка Хоара"<<endl;
	cout << "Введите операцию: ";
	cin >>a;
	switch (a)
	{
	case 1: ShellSort(st, n); break;
	case 2: HoaraSort(st, 0, n - 1);; break;
	default: cout << "ОШИБКА!!! Неизвестная операция. Сортировка не выполнена." << endl;
	}
	cout << endl << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Название предмета: "  << st[i].name << endl;
		cout << " Вес предмета: "  << st[i].weight << endl;
	}
}