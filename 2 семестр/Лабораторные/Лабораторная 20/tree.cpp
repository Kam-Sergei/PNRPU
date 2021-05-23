#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    btree t;
    int n;
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t.insert(a);
    }
    t.print();
    t.kol();
}