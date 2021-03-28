#include <iostream>
#include<string>
#include<cstring>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <random>
#include <stdio.h>
using namespace std;
int n, nf, nf2, num = -1;
string key;

struct info
{
	string fio;
	string passport;
	string number;
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\n№Паспорт: " << passport
			<< "\n№Телефон: " << number << endl;
	}
	void Random()
	{
		string names[] = { "Aleksadr", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "Valentin", "Mark" };
		string secnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
		string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
		fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		string pas;
		for (int i = 0; i < 10; i++)
		{
			pas.push_back(rand() % 10 + 48);
		}
		passport = pas;
		string phone;
		for (int i = 0; i < 10; i++)
		{
			phone.push_back(rand() % 10 + 48);
		}
		number = phone;
	}
};
void menu(info* st);

void savetofile(info* st)
{
	nf = n;
	ofstream F1("F1.txt", ios_base::out);
	if (!F1.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	F1 << nf << "\n";
	for (int i = 0; i < n; i++)
	{
		F1 << st[i].fio << "\n";
		F1 << st[i].passport << "\n";
		F1 << st[i].number << "\n";
	}
	F1.close();
}

void extraction(info* st)
{
	ifstream F1("F1.txt", ios_base::in);
	if (!F1.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	F1 >> nf;
	string names;
	string secnames;
	string thirdnames;
	for (int i = 0; i < nf; i++)
	{
		F1 >> names;
		F1 >> secnames;
		F1 >> thirdnames;
		st[i].fio = names + " " + secnames + " " + thirdnames;
		F1 >> st[i].passport;
		F1 >> st[i].number;
	}
	F1.close();
	for (int i = 0; i < nf; i++)
	{
		st[i].Show();
	}
	n = nf;
	menu(st);
}

void del(info* st)
{
	if (num == -1)
	{
		cout << "Ошибка: нет номера элеиента для выполнения задачи!" << endl;
		menu(st);
	}
	nf2 = n;
	ofstream F2("F2.txt", ios_base::out);
	if (!F2.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	F2 << nf2 << "\n";
	for (int i = 0; i < n; i++)
	{
		F2 << st[i].fio << "\n";
		F2 << st[i].passport << "\n";
		F2 << st[i].number << "\n";
	}
	F2.close();
	for (int i = num; i < n - 1; i++)
	{
		st[i].fio = st[i + 1].fio;
		st[i].passport = st[i + 1].passport;
		st[i].number = st[i + 1].number;
	}
	n = n - 1;
	for (int i = 0; i < n; i++)
	{
		st[i].Show();
	}
	num = -1;
	menu(st);
}

void add(info* st)
{
	if (num == -1)
	{
		cout << "Ошибка: нет номера элеиента для выполнения задачи!" << endl;
		menu(st);
	}
	nf2 = n;
	ofstream F2("F2.txt", ios_base::out);
	if (!F2.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	F2 << nf2 << "\n";
	for (int i = 0; i < n; i++)
	{
		F2 << st[i].fio << "\n";
		F2 << st[i].passport << "\n";
		F2 << st[i].number << "\n";
	}
	F2.close();
	n = n + 1;
	info* st2 = new info[n];
	int i = n;
	for (int i = 0; i < num; i++)
	{
		st2[i].fio = st[i].fio;
		st2[i].passport = st[i].passport;
		st2[i].number = st[i].number;
	}
	st2[num].Random();
	for (int i = num + 1; i < n; i++)
	{
		st2[i].fio = st[i - 1].fio;
		st2[i].passport = st[i - 1].passport;
		st2[i].number = st[i - 1].number;
	}
	for (int i = 0; i < n; i++)
	{
		st2[i].Show();
	}
	num = -1;
	menu(st2);
}

void extraction2(info* st)
{
	ifstream F2("F2.txt", ios_base::in);
	if (!F2.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}
	F2 >> nf2;
	string names;
	string secnames;
	string thirdnames;
	for (int i = 0; i < nf2; i++)
	{
		F2 >> names;
		F2 >> secnames;
		F2 >> thirdnames;
		st[i].fio = names + " " + secnames + " " + thirdnames;
		F2 >> st[i].passport;
		F2 >> st[i].number;
	}
	F2.close();
	for (int i = 0; i < nf2; i++)
	{
		st[i].Show();
	}
	n = nf2;
	menu(st);
}

void search1(info* st)
{
	if (key.size() == 0)
	{
		cout << "Ошибка: нет ключа для поиска!" << endl;
		menu(st);
	}
	int key1 = key.size();
	for (int i = 0; i < n; i++)
	{
		int st1 = st[i].number.size();
		string str = st[i].number;
		if (key1 <= st1 && st1 != 0)
		{
			for (int j = 0; j <= st1 - key1; j++)
			{
				for (int k = 0; k < key1; k++)
				{
					if (key[k] != str[k + j])
					{
						break;
					}
					else if (k == key1 - 1)
					{
						num = i;
						break;
					}
				}
			}
			if (num != -1)
			{
				st[num].Show();
				i = n;
			}
		}
	}
	if (num == -1)
	{
		cout << "Элемент не найден." << endl;
	}
}

void search2(info* st)
{
	if (key.size() == 0)
	{
		cout << "Ошибка: нет ключа для поиска!" << endl;
		menu(st);
	}
	if (key.size() == 10)
	{
		for (int i = 0; i < n; i++)
		{
			int st1 = st[i].number.size();

			if (st[i].number == key)
			{
				num = i;
			}
			if (num != -1)
			{
				st[num].Show();
				i = n;
			}
		}
		if (num == -1)
		{
			cout << "Элемент не найден." << endl;
		}
	}
	else
	{
		cout << "Ошибка: количество элементов в ключе поиска не равно 10! " << endl;
		cout << "Рекомендуем искать методом прямого поиска в строке." << endl;
	}
}

int get_value(string str)
{
	int value = 0;
	int j = 1;
	for (auto i : str) {
		value += i * j;
		j++;
	}
	return value;
}

int InterpolSearch(int* A, int n, unsigned int key)
{
	int mid, left = 0, right = n - 1;
	while (A[left] <= key && A[right] >= key)
	{
		mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
		if (A[mid] < key) left = mid + 1;
		else if (A[mid] > key) right = mid - 1;
		else return mid;
	}
	if (A[left] == key) return left;
	else return -1;
}

void search3(info* st)
{
	if (key.size() == 0)
	{
		cout << "Ошибка: нет ключа для поиска!" << endl;
		menu(st);
	}
	if (key.size() == 10)
	{
		info* st2 = new info[n];
		for (int i = 0; i < n; i++)
		{
			st2[i].number = st[i].number;
		}
		string b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (st2[j].number > st2[j + 1].number)
				{
					b = st2[j].number;
					st2[j].number = st2[j + 1].number;
					st2[j + 1].number = b;
				}
			}
		}
		int ind = -1;
		int* A = new int[n];
		int key1 = get_value(key);
		for (int i = 0; i < n; i++)
		{
			A[i] = get_value(st2[i].number);
		}
		ind = InterpolSearch(A, n, key1);
		if (ind == -1)
		{
			cout << "Элемент не найден." << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (st2[ind].number == st[i].number)
				{
					num = i;
					st[num].Show();
					i = n;
				}
			}
		}
	}
	else
	{
		cout << "Ошибка: количество элементов в ключе поиска не равно 10! " << endl;
		cout << "Рекомендуем искать методом прямого поиска в строке." << endl;
	}
}

void menu(info* st)
{
	cout << "Операции" << endl;
	cout << "1 - ввод ключа для поиска" << endl;
	cout << "2 - прямой поиск подстроки в строке" << endl;
	cout << "3 - линейный поиск" << endl;
	cout << "4 - интерполяционный поиск" << endl;
	cout << "5 - сохранение в файл" << endl;
	cout << "6 - извлечение из файла" << endl;
	cout << "7 - отмена прошлой операции" << endl;
	cout << "8 - добавление элемента перед элементом с заданным ключом" << endl;
	cout << "9 - удаление элемента по заданному ключу" << endl;
	cout << "0 - выход" << endl;
	cout << "Введите операцию: ";
	int a;
	cin >> a;
	switch (a)
	{
	case 1: cout << "Введие ключ для поиска по номеру телефона:"; cin >> key; break;
	case 2:search1(st); break;
	case 3:search2(st); break;
	case 4:search3(st); break;
	case 5:savetofile(st); break;
	case 6:extraction(st); break;
	case 7:extraction2(st); break;
	case 8:add(st); break;
	case 9:del(st); break;
	case 0:exit(0); break;
	default: cout << "Неизвестная операция. Повторите попытку." << endl;
	}
	menu(st);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	cout << "Введите количество элементов: ";
	cin >> n;
	info* st = new info[n];
	for (int i = 0; i < n; i++)
	{
		st[i].Random();
		st[i].Show();
	}
	menu(st);
	return(0);
}
