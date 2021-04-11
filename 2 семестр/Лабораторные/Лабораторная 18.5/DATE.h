#pragma once
#include "TRIAD.h"
class DATE :
    public TRIAD
{
public:
    DATE(void);
    ~DATE(void);
    void Show();
    DATE(int, int, int);
    DATE(const DATE&);

    void year(int);
    void month(int);
    void day(int);

    /// ������������� �������
    DATE operator++(int); // ����������� ��������
    DATE operator+(int);

    friend istream& operator>>(istream& in, DATE& l);
    friend ostream& operator<<(ostream& out, const DATE& l);
};

