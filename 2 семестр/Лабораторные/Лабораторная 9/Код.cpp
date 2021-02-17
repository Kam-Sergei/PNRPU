#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool print(string str)
{
	char a[255];
	a[0] = NULL;
	int b = 0;
	int n = 1;
	for (auto c : str)
	{
		if (a[0] == NULL)
		{
			a[0] = c;
		}
		if (b == 1)
		{
			a[n] = c;
			n++;
		}
		if (c == ' ')
		{
			b = 1;
		}
		else
		{
			b = 0;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
				return 1;
		}
	}
	return 0;
}




int main()
{
	setlocale(LC_ALL, "Rus");
	int n1;
	cout << "Введите количество строк: ";
	cin >> n1;
	cin.ignore();
	ofstream F1("F1.txt");
	if (!F1.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	string str;
	cout << "Введите строки: "<<endl;
	for (int i = 0; i < n1; i++)
	{
		cout << " ";
		getline(cin, str);
		F1 << str << "\n";
	}
	F1.close();
	ifstream f1;
	f1.open("F1.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	cout << "Содержание файла F1:"<<endl;
	for (int i = 0; i < n1; i++)
	{
		cout << " ";
		getline(f1, str);
		cout << str << endl;
	}
	f1.close();
	f1.clear();
	ofstream F2("F2.txt");
	if (!F2.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	


	f1.open("F1.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	int n2=0;
	for (int i = 0; i < n1; i++)
	{
		getline(f1, str);
		bool f = print(str);
		if (f == 0)
		{
			F2 << str << "\n";
			n2++;
		}
	}
	F2.close();
	f1.close();
	f1.clear();
	f1.open("F2.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	cout << "Содержание файла F2:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cout << " ";
		getline(f1, str);
		cout << str << endl;
	}
	f1.close();
	f1.clear();

	ifstream f2; 
	f2.open("F2.txt");
	if (!f2.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	int Short = 100;
	for (int i = 0; i < n2; i++)
	{
		getline(f2, str);
		int d = 0;
		for (auto c : str)
		{
			if (c != ' ')
			{
				d++;
			}
			if (c == ' ')
			{
				if (d < Short)
				{
					Short = d;
				}
				d = 0;
			}
		}
		if (d < Short)
		{
			Short = d;
		}
	}
	f2.close();
	f2.clear();
	cout << "Длина самого короткого слова в файле F2: ";
	cout << Short << endl;

	f2.open("F2.txt");
	if (!f2.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	char a[255];
	cout << "Самое/(ые) короткое/(ие) слово/(а) в файле F2: ";
	for (int i = 0; i < n2; i++)
	{
		getline(f2, str);
		int d = 0;
		for (auto c : str)
		{
			if (c != ' ')
			{
				a[d] = c;
				d++;
			}
			if (c == ' ')
			{
				if (d == Short)
				{
					for (int i = 0; i < Short;i++)
					{
						cout << a[i];
					}
					cout << " ";
				}
				d = 0;
			}
		}
		if (d == Short)
		{
			for (int i = 0; i < Short; i++)
			{
				cout << a[i];
			}
			cout << " ";
		}
	}
	f2.close();
	f2.clear();
	return 0;
}
