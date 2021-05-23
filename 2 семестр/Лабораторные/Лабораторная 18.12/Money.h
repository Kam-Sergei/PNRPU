#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Money
{
    float rub;
    float kop;
    int dop;
public:
    Money();
    Money(float rub, float kop, int dop);
    ~Money();
    void SetRub();
    long GetRub();
    Money& operator++();
    Money& operator++(int a);
    void SetKop();
    int GetKop();
    void SetDop();
    int GetDop();
    void PrintClass();
    void GetRazn();

    bool operator!=(Money secondOperand);

    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);
    friend fstream& operator<<(fstream& fout, const Money& m);
    friend fstream& operator>>(fstream& fin, Money& m);
};
