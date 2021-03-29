#include "Exam.h"
#include <iostream>
#include <string> 
using namespace std;

Exam make_exam()
{
	string s;
	string i; 
	int d;
	cout << "Enter fio: ";
	cin >> s;
	cout << "Enter subject: ";
	cin >> i;
	cout << "Enter evaluation: ";
	cin >> d;
	Exam t(s, i, d);
	return t;
}

void print_exam(Exam t)
{
	t.show();
}
void main()
{
	Exam t1;
	t1.show();
	Exam t2("Petrov", "Information",4);
	t2.show();
	Exam t3 = t2; t3.set_fio("Petrov"); t3.set_subject("Information"); t3.set_evaluation(5);
	print_exam(t3);
	t1=make_exam();
	t1.show();
}