#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
int n;
int arr[], F1[], F2[], F3[];

void Merge1(int* v, int r, int t)
{
	int p = 1;
	int k = 1;
	int i = 0;
	bool flag = false;
	while (v[i] <= v[i + 1] && i < r - 1)
	{
		p++;
		i++;
	}
	if (v[i] > v[i + 1] && i < r - 1)
	{
		i++;
		flag = true;
		while (v[i] <= v[i + 1] && i < r - 1)
		{
			k++;
			i++;
		}
	}
	int num = i + 1;
	int* a = new int[p];
	int* b = new int[k];
	for (i = 0; i < p; i++)
	{
		a[i] = v[i];
	}
	int g = 0;
	if (flag == true)
	{
		for (i = p; i < p + k; i++)
		{
			b[g] = v[i];
			g++;
		}
	}
	int j = 0;
	int l = 0;
	if (flag == true)
	{
		for (i = 0; i < num; i++)
		{
			if ((a[l] < b[j] || j >= k) && l < p)
			{
				v[i] = a[l];
				l++;
			}
			else if ((a[l] > b[j] || l >= p) && j < k)
			{
				v[i] = b[j];
				j++;
			}
			else if (a[l] == b[j] && j < k && l < p)
			{
				v[i] = a[l];
				v[i + 1] = b[j];
				i++;
				j++;
				l++;
			}
		}
	}
}

void MergeSort1(int* v, int r, int i)
{
	if (i < r)
	{
		Merge1(v, r, i);
		MergeSort1(v, r, i + 1);
	}
}

void Merge2(int* A, int first, int last)
{
	int* mas = new int[n];
	int middle = (first + last) / 2;
	int start = first;
	int final = middle + 1;
	for (int i = first; i <= last; i++)
	{
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[i] = A[start];
			start++;
		}
		else
		{
			mas[i] = A[final];
			final++;
		}
	}
	for (int i = first; i <= last; i++)
	{
		A[i] = mas[i];
	}
	delete[]mas;
}

void MergeSort2(int* A, int first, int last)
{
	if (first < last)
	{
		MergeSort2(A, first, (first + last) / 2);
		MergeSort2(A, (first + last) / 2 + 1, last);
		Merge2(A, first, last);
	}
}

void sort(int* a, int k)
{
	int b = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
}

void MergeSort3(int* A)
{
	int a = 1, b = 1, k1 = 0, k2 = 0, k3 = 0;
	while (a + b <= n / 2)
	{
		if (a > b)
		{
			b = a + b;
		}
		else
		{
			a = a + b;
		}
		if (n % (a + b) == 0)
		{
			k1 = a;
			k2 = b;
		}
	}
	int* F1 = new int[n];
	int* F2 = new int[n];
	int* F3 = new int[n];
	if ((k1 == 0) && (k2 == 0))
	{
		k1 = 1;
	}
	int s = n / (k1 + k2);
	for (int i = 0; i < k1 * s; i++)
	{
		F1[i] = A[i];
	}
	sort(F1, k1 * s);
	for (int i = k1 * s; i < (k1 + k2) * s; i++)
	{
		F2[(i - (k1 * s))] = A[i];
	}
	sort(F2, k2 * s);
	int s1 = s, s2 = s, s3 = s;
	for (int j = 0; j < n; j++)
	{
		if ((k1 * s1 != n) && (k2 * s2 != n) && (k3 * s3 != n))
		{
			if (k1 == 0)
			{
				if (k2 > k3)
				{
					k1 = k3;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k3 * s3)
						{
							F1[i] = F3[i];
						}
						else
						{
							F1[i] = F2[i - k3 * s3];
						}
					}
					sort(F1, k1 * s1);
					for (int i = 0; i < (k2 * s2 - k3 * s3); i++)
					{
						F2[i] = F2[(i + (k3 * s3))];
					}
					k2 = k2 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k1 = k2;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k2 * s2)
						{
							F1[i] = F2[i];
						}
						else
						{
							F1[i] = F3[i - k2 * s2];
						}
					}
					sort(F1, k1 * s1);
					for (int i = 0; i < (k3 * s3 - k2 * s2); i++)
					{
						F3[i] = F3[(i + (k2 * s2))];
					}
					k3 = k3 - k2;
					k2 = 0;
					s2 = 0;
				}
			}
			else if (k2 == 0)
			{
				if (k1 > k3)
				{
					k2 = k3;
					s2 = s1 + s3;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k3 * s3)
						{
							F2[i] = F3[i];
						}
						else
						{
							F2[i] = F1[i - k3 * s3];
						}
					}
					sort(F2, k2 * s2);
					for (int i = 0; i < (k1 * s1 - k3 * s3); i++)
					{
						F1[i] = F1[(i + (k3 * s3))];
					}
					k1 = k1 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k2 = k1;
					s2 = s3 + s1;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k1 * s1)
						{
							F2[i] = F1[i];
						}
						else
						{
							F2[i] = F3[i - k1 * s1];
						}
					}
					sort(F2, k2 * s2);
					for (int i = 0; i < (k3 * s3 - k1 * s1); i++)
					{
						F3[i] = F3[(i + (k1 * s1))];
					}
					k3 = k3 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
			else if (k3 == 0)
			{
				if (k1 > k2)
				{
					k3 = k2;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k2 * s2)
						{
							F3[i] = F2[i];
						}
						else
						{
							F3[i] = F1[i - k2 * s2];
						}
					}
					sort(F3, k3 * s3);
					for (int i = 0; i < (k1 * s1 - k2 * s2); i++)
					{
						F1[i] = F1[(i + (k2 * s2))];
					}
					k1 = k1 - k2;
					k2 = 0;
					s2 = 0;
				}
				else
				{
					k3 = k1;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k1 * s1)
						{
							F3[i] = F1[i];
						}
						else
						{
							F3[i] = F2[i - k1 * s1];
						}
					}
					sort(F3, k3 * s3);
					for (int i = 0; i < (k2 * s2 - k1 * s1); i++)
					{
						F2[i] = F2[(i + (k1 * s1))];
					}
					k2 = k2 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
		}
		else {
			if (k1 * s1 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F1[i];
				}
			}
			if (k2 * s2 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F2[i];
				}
			}
			if (k3 * s3 == n)
			{
				for (int i = 0; i < n; i++)
				{
					A[i] = F3[i];
				}
			}
			j = n;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов: ";
	cin >> n;
	srand(time(NULL));
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() / 100;
		cout << arr[i] << " ";
	}
	int ar;
	cout << endl << "Операции:" << endl;
	cout << "1 - сортировка методом естественного слияния" << endl;
	cout << "2 - сортировка сбалансированным слиянием" << endl;
	cout << "3 - сортировка многофазным слиянием" << endl;
	cout << "Введите операцию: ";
	cin >> ar;
	switch (ar)
	{
	case 1: MergeSort1(arr, n, 0); break;
	case 2: MergeSort2(arr, 0, n - 1); break;
	case 3: MergeSort3(arr); break;
	default: cout << "ОШИБКА!!! Неизвестная операция. Сортировка не выполнена." << endl;
	}
	cout << endl << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
