#include <iostream>
#include <stack>               // ��������� �����
using namespace std;
char a,b; //a- ������ � ����� b-���� ��� ��������

void print(stack<char> st) {
	int p = st.size(); // ������ �����
	if (p == 0)
	{
		cout << "���� ����";
	}
	else {
		for (int i = 0; i < p; i++) // ������ ��������� �����
		{ 
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	stack<char> st;                // ������� ������ ����
	int n;                        // n- ���������� ��������� �����
	cout << "������� ���������� ��������� ����� : ";
	cin >> n;
	cout << "������� �������� ����� : ";
	for (int i = 0; i < n; i++)
	{
		cin >> a; //���� �������� ��������
		st.push(a); // ���������� ��������� � ����
	}
	cout << "����: ";
	print(st);                   // ������ �����

	stack<char> st2;   // ������� ������ ����
	cout << "������� ���� ��� ��������: ";
	cin >> b; //���� �������� �������� ��� ��������
	for (int i = 0; i < n; i++) // ������� ���� ���������,
	{
		if (st.top() != b)
		{	
			st2.push(st.top());
		}        
		st.pop();
	}
	n = st2.size();
		for (int i = 0; i < n; i++) 
		{ 
			st.push(st2.top());  
			st2.pop();
		}
	cout << "���� ����� ��������: ";
	print(st);                       // ������ �����

	int k = 0; //���������� ��������� ��� ����������
	cout << "������� ���������� ��������� ��� ����������: ";
	cin >> k;
	int s = 0; //�������, ����� ������� ��������� ��������
	cout << "������� ����� ��������, ����� ������� ��������� ��������: ";
	cin >> s;
	for (int i = 0; i < n-s+1; i++) 
	{
		st2.push(st.top());
		st.pop();
	}
	cout << "������� ��������: ";
	for (int i = 0; i < k; i++) 
	{
		cin >> a;
		st.push(a);
	}
	for (int i = 0; i < n - s + 1; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
	print(st);
	return 0;
}