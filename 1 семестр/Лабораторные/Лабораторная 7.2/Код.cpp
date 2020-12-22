# include <iostream>

using namespace std;

int kvadr(int n, int first, ...)
{
	int k = 0;
	int a = 0;
	int b = 0;
	int* p = &first;
	while (n>0)
	{
		a = *p;
		p++;
		b = (int)sqrt(a)*(int)sqrt(a);
		if (a ==b)
		{
			k = k + 1;
		}
		n--;
	}
	cout<<"k=" << k<<endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	kvadr(3,4,5,7);
	kvadr(7,4, 5, 7,25,9,22,5);
	kvadr(11,4, 5, 7, 12,56,16,3,1,5,2,9);
	return 0;
}