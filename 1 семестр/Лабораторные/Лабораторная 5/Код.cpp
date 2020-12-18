#include <iostream>

using namespace std;

int a[100][100];
int s, n;
bool f;

void function(int i, int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] < 0)
		{
			f = true;
			j = n;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите количество строк в массиве: s=";
	cin >> s;
	cout << "¬ведите количество элементов в строке: n=";
	cin >> n;
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = rand() % 100 - 20;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= s; i++)
	{
		f = false;
		function(i,n);
		if (f == true)
		{
			for (int k = i; k <= s; k++)
			{
				for (int j = 1; j <= n; j++)
				{
					a[k][j] = a[k + 1][j];
				}
			}
			i = i - 1;
		}
	}
	cout << "ѕеределанный массив:"<<endl;
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}