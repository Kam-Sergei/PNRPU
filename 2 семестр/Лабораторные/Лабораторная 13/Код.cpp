#include <iostream>
using namespace std;

int mas[8][8];
int str, col;   //str-строка, col-столбец

void vvod();    //Функция добавления
void del();     //Функция удаления
void vivod();   //Функция вывода

void vvod()
{
	for (int i =str; i < 8; i++)
	{
		for (int j = col; j < 8; j++)
		{
			if (mas[i][j] == 0)
			{
				int x = i;
				int y = j;
				str = x;
				mas[i][j] = -(str + 1);
				for (int a = 0; a < 8; a++)
				{
					if (mas[x][a] == 0)
					{
						mas[x][a] = str + 1;
					}
				}
				for (int b = 0; b < 8; b++)
				{
					if (mas[b][y] == 0)
					{
						mas[b][y] = str + 1;
					}
				}
				while (x != 7 && y != 7)
				{
					if (mas[x + 1][y + 1] == 0)
					{
						mas[x + 1][y + 1] = str + 1;
					}
					x++;
					y++;
				}
				x = i;
				y = j;
				while (x != 0 && y != 0)
				{
					if (mas[x - 1][y - 1] == 0)
					{
						mas[x - 1][y - 1] = str + 1;
					}
					x--;
					y--;
				}
				x = i;
				y = j; 
				while (x != 0 && y != 7)
				{
					if (mas[x - 1][y + 1] == 0)
					{
						mas[x - 1][y + 1] = str + 1;
					}
					x--;
					y++;
				}
				x = i;
				y = j; 
				while (x != 7 && y != 0)
				{
					if (mas[x + 1][y - 1] == 0)
					{
						mas[x + 1][y - 1] = str + 1;
					}
					x++;
					y--;
				}
				j = 7;
				col = 0;
				cout << "Доска после добавление:" << endl;
				vivod();
				if (str == 7)
				{
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							if (mas[i][j] > 0)
							{
								mas[i][j] = 0;
							}
							if (mas[i][j] < 0)
							{
								mas[i][j] = 1;
							}
						}
					}
					cout << "Результат:" << endl;
					cout << "1 - клетка с ферзём" << endl;
					cout << "0 - пустая клетка" << endl << endl;
					vivod();
					exit(0);
				}
			}
			else
			{
				if (j == 7 && mas[i][j] != 0)
				{
					del();
				}
			}
		}
		
	}
}

void del()
{
	for (int j = 0; j < 8;j++)
	{
		if (mas[str][j] == -(str + 1))
		{
			col = j;
			j = 7;
		}
	}
	mas[str][col] = 0;
	int x = str;
	int y = col;
	for (int a = 0; a < 8; a++)
	{
		if (mas[x][a] == str + 1)
		{
			mas[x][a] = 0;
		}
	}
	for (int b = 0; b < 8; b++)
	{
		if (mas[b][y] == str + 1)
		{
			mas[b][y] = 0;
		}
	}
	while (x != 7 && y != 7)
	{
		if (mas[x + 1][y + 1] == str + 1)
		{
			mas[x + 1][y + 1] = 0;
		}
		x++;
		y++;
	}
	x = str;
	y = col;
	while (x != 0 && y != 0)
	{
		if (mas[x - 1][y - 1] == str + 1)
		{
			mas[x - 1][y - 1] = 0;
		}
		x--;
		y--;
	}
	x = str;
	y = col;
	while (x != 0 && y != 7)
	{
		if (mas[x - 1][y + 1] == str + 1)
		{
			mas[x - 1][y + 1] = 0;
		}
		x--;
		y++;
	}
	x = str;
	y = col;
	while (x != 7 && y != 0)
	{
		if (mas[x + 1][y - 1] == str + 1)
		{
			mas[x + 1][y - 1] = 0;
		}
		x++;
		y--;
	}
	cout << "Доска после удаления:" << endl;
	vivod();
	for (int j = col + 1; j < 8; j++)
	{
		if (mas[str][j] == 0)
		{
			col = j;
			vvod();
		}
	}
	str--;
	del();
}

void vivod()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout<<mas[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			mas[i][j] = 0;
		}
	}
	str = 0;
	col = 0;
	cout << "Пустая доска:" << endl;
	vivod();
	vvod();
	return 0;
}
