#include <iostream>
#include "Money.h"
using namespace std;

Money::Money()
{
    rub = 0;
    kop = 0;
}
Money::Money(long rub, int kop)
{
    this->rub = rub;
    this->kop = kop;
}
Money:: ~Money() {}
void Money::SetRub()
{
    long val;
    cout << "??????? ?????: ";
    cin >> val;
    while (val < 0)
    {
        cout << "??????? ?????????? ?????: ";
        cin >> val;
    }
    this->rub = val;
}
long Money::GetRub() { return rub; }
void Money::SetKop()
{
    int tmp;
    cout << "??????? ???????: ";
    cin >> tmp;
    while (tmp > 99 || tmp < 0)
    {
        cout << "??????? ?????????? ?????: ";
        cin >> tmp;
    }
    this->kop = tmp;
}
int Money::GetKop() { return kop; }

void Money::PrintClass()
{
    cout << "????????: " << this->rub << "," << this->kop << endl;
}

Money& Money::operator++()
{
    rub++;
    return *this;
}
Money& Money::operator++(int a)
{
    Money tmp(*this);
    this->rub++;
    return tmp;
}

istream& operator>>(istream& stream, Money& element)
{
    stream >> element.rub;
    stream >> element.kop;
    return stream;
}

ostream& operator<<(ostream& stream, Money element)
{
    stream << element.rub << "," << element.kop;
    return stream;
}