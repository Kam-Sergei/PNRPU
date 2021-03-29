#pragma once
#include <iostream> 
#include <string>
using namespace std;
class Exam
{
	string fio;
	string subject; 
	int evaluation;
public:
	Exam();
	Exam(string, string, int);
	Exam(const Exam&);
	~Exam();
	string get_fio();
	void set_fio(string);
	string get_subject();
	void set_subject(string);
	int get_evaluation();
	void set_evaluation(int);
	void show();
};
