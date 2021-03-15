#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
int n;
string key;

struct inform
{
	string fio;
	string passport;
	string number;
};

string correct(string str)
{
	int d = str.size();
	if (str[0] == '+' && str[1] == '7')
	{
		str[0] = 8;
		for (int i = 1; i < d; i++)
		{
			str[i] = str[i + 1];
		}
		d--;
	}
	for (int i = 0; i < d; i++)
	{
		while (str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')' || str[i] == ' ')
		{
			for (int j = i; j < d; j++)
			{
				str[j] = str[j + 1];
			}
			d--;
		}
	}
	str.resize(d);
	return str;
}

bool Knut_Morris_Pratt(string str)
{
	int stl = str.size();
	int ctl = key.size();
	if (stl != 0 && ctl != 0 && stl > ctl)
	{
		int  i, j = 0, k = -1;
		int* pf = new int[1000];
		pf[0] = -1;
		while (j < ctl - 1)
		{
			while (k >= 0 && key[j] != key[k])
			{
				k = pf[k];
			}
			j++;
			k++;
			if (key[j] == key[k])
			{
				pf[j] = pf[k];
			}
			else
			{
				pf[j] = k;
			}
		}
		i = 0;
		j = 0;
		while (j < ctl && i < stl)
		{
			while (j >= 0 && str[i] != key[j])
			{
				j = pf[j];
			}
			i++;
			j++;
		}
		delete[] pf;
		if (j == ctl)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Boer_Moor(string str)
{
	int stl = str.size();
	int ctl = key.size();
	if (stl != 0 && ctl != 0 && stl > ctl)
	{
		int  i, pos;
		int  bmt[256];
		for (i = 0; i < 256; i++)
		{
			bmt[i] = ctl;
		}
		for (i = ctl - 1; i >= 0; i--)
		{
			if (bmt[(short)(key[i])] == ctl)
			{
				bmt[(short)(key[i])] = ctl - i - 1;
			}
		}
		pos = ctl - 1;
		while (pos < stl)
			if (key[ctl - 1] != str[pos])
			{
				pos = pos + bmt[(short)(str[pos])];
			}
			else
			{
				for (i = ctl - 2; i >= 0; i--)
				{
					if (key[i] != str[pos - ctl + i + 1])
					{
						pos += bmt[(short)(str[pos - ctl + i + 1])] - 1;
						break;
					}
					else if (i == 0)
					{
						return true;
					}
				}
			}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите количество элементов: ";
	cin >> n;
	inform* st = new inform[n];
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "Введите ФИО: ";
		getline(cin, st[i].fio);
		cout << "Введите № паспорта: ";
		getline(cin, st[i].passport);
		cout << "Введите № телефона: ";
		getline(cin, st[i].number);
		st[i].number = correct(st[i].number);
	}
	cout << endl << "Поиск осуществляется по № телефона:"<<endl;
	cout << "Введите ключ для поиска: ";
	cin >> key;
	key = correct(key);
	cout << endl << "Операции:" << endl;
	cout << "1 - поиск алгоритмом Кнута Морриса Пратта" << endl;
	cout << "2 - поиск алгоритмом Боера-Мура " << endl;
	int a;
	cout << "Введите операцию: ";
	cin >> a;
	cout << endl;
	bool l;
	bool p = 0;
	if (a != 1 && a != 2)
	{
		cout << "ОШИБКА!!! Неизвестная операция. Поиск не выполнен." << endl;
		exit(0);
	}
	else if (a == 1)
	{
		cout << "Результат поиска:"<<endl;
		for (int i = 0; i < n; i++)
		{
			l = Knut_Morris_Pratt(st[i].number);
			if (l != 0)
			{
				cout << "ФИО: " << st[i].fio << endl;
				cout << "№ паспорта: " << st[i].passport << endl;
				cout << "№ телефона: " << st[i].number << endl;
				p = 1;
			}
		}
	}
	else
	{
		cout << "Результат поиска:"<<endl;
		for (int i = 0; i < n; i++)
		{
			l = Boer_Moor(st[i].number);
			if (l != 0)
			{
				cout << "ФИО: " << st[i].fio << endl;
				cout << "№ паспорта: " << st[i].passport << endl;
				cout << "№ телефона: " << st[i].number << endl;
				p = 1;
			}
		}
	}
	if (p == 0)
	{
		cout << "Элемент с заданным ключом не найден" << endl;
	}
	return 0;
}