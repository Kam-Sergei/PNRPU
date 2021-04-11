#include "Stack.h"
#include <iostream>
using namespace std;

int main() 
{
    Stack<int> s;
    bool flag = true;
    while (flag)
    {
        cout << "1. Push   2. Pop    3. Print    4. Quit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case(1):
            cout << "Enter a number to push in Stack?";
            int n;
            cin >> n;
            s.push(n);
            break;
        case(2):
            s.pop();
            break;
        case(3):
            s.print();
            break;
        case(4):
            return 1;
        default:
            cout << "Invalid choice!!" << endl;
            break;
        }
    }
    return 0;
}