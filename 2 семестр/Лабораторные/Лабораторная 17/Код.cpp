#include <iostream>
#include<string>
#include <windows.h>
#include <ctime>
#include <math.h>
using namespace std;
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
int get(string str) {
	int value = 0;
	int j = 1;
	for (auto i : str) {
		value += i * j;
		j++;
	}
	return value;
}
int hash_t(string str, int size)
{
	double f;
	return int(size * modf(get(str) * 0.803523421, &f));
}
void make_table(int n, int size, info* st2)
{
	int* table = new int[size];
	int hashn = size;
	for (int i = 0; i < size; i++)
	{
		table[i] = -1;
	}
	int collis = 0;
	for (int k = 0; k < n; k++)
	{
		int num;
		int hash = hash_t(st2[k].number, hashn);
		if (table[hash] == -1)
		{
			table[hash] = k;
		}
		else
		{
			num = hash;
			while (num < size && table[num] != -1)
			{
				collis++;
				num++;
			}
			if (num >= size)
			{
				size *= 2;
				int* table2 = new int[size];
				for (int i = 0; i < size / 2; i++)
				{
					table2[i] = table[i];
				}
				for (int i = size / 2; i < size; i++)
				{
					table2[i] = -1;
				}
				delete[]table;
				table = table2;
			}
			if (table[num] == -1)
			{
				table[num] = k;
			}
		}
	}
	cout << "Число колизий: " << collis << endl;
	cout << "Введите ключ для поиска: ";
	string key;
	cin.ignore();
	getline(cin, key);
	int hashkey = hash_t(key, hashn);
	if (st2[table[hashkey]].number == key)
	{
		cout << "Элемент найден: " << endl;
		st2[table[hashkey]].Show();
	}
	else
	{
		while (st2[table[hashkey]].number != key && hashkey < size)
		{
			hashkey++;
		}
		if (st2[table[hashkey]].number == key)
		{
			cout << "Элемент найден: " << endl;
			st2[table[hashkey]].Show();
		}
		else
			cout << "Такого элемента не найдено";
	}
	bool p = 0;
	cout << "Хотите удалить элемент? (0/1)" << endl;
	cin >> p;
	if (p)
	{
		info* st = new info[n - 1];
		for (int i = 0; i < table[hashkey]; i++) {
			st[i] = st2[i];

		}
		for (int i = table[hashkey]; i < n - 1; i++) {
			st[i] = st2[i + 1];
		}
		delete[]st2;
		cout << "После удаления: " << endl;
		for (int i = 0; i < n - 1; i++)
		{
			st[i].Show();
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int n, size;
	string key;
	cout << "Кол-во элементов: ";
	cin >> n;
	cout << "Размер таблицы: ";
	cin >> size;
	info* st = new info[n];
	int* table = new int[size];
	for (int i = 0; i < n; i++)
	{
		st[i].Random();
		st[i].Show();
	}
	make_table(n, size, st);

}
