#include <algorithm>
#include <iostream>
#include <iterator>
#include "Vector.h"
#include <map>
#include "Money.h"
#include <time.h>
using namespace std;

int getCorrectNumber()
{
    int num;
    cout << "Enter size:  ";
    while (!(cin >> num) || (cin.peek() != '\n') || num < 0)
    {

        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное число: ";
    }
    return num;
}

float srednee(multimap<float, Money> m)
{
    multimap<float, Money>::iterator it;
    float s = 0;
    for (it = m.begin(); it != m.end(); it++)
    {
        s += it->second.GetRub() * 1.0 + it->second.GetKop() / 100.0;
    }
    return s / m.size();
}

void Task1()
{
    // creation    
    cout << "TASK 1" << endl << endl;
    int size;
    size = getCorrectNumber();

    multimap<float, float> Mymap;
    multimap<float, float>::iterator it;
    it = Mymap.begin();
    for (int i = 0; i < size; i++)
    {
        Mymap.insert(make_pair(i, rand() % 1000 / 10.0));
    }


    cout << "Task1" << endl << "Исходный словарь" << endl;
    multimap<float, float>::iterator p2;
    for (p2 = Mymap.begin(); p2 != Mymap.end(); ++p2)
        cout << p2->first + 1 << ")\t" << p2->second << '\n';

    float min = 10000;
    for (it = Mymap.begin(); it != Mymap.end(); it++)
    {
        if (min > it->second)
        {
            min = it->second;
        }
    }
    cout << "min = " << min << endl;


    int pos;
    cout << "Enter position:  ";
    cin >> pos;
    multimap<float, float>Mymap2;
    multimap<float, float>::iterator it2;
    it2 = Mymap.begin();
    for (int i = 0; i < pos - 1; i++)
    {
        Mymap2.insert(*it2);
        it2++;
    }

    Mymap2.insert(make_pair(pos - 1, min));
    for (int j = pos; j < size + 1; j++)
    {
        Mymap2.insert(*it2);
        it2++;
    }
    multimap<float, float>::iterator p3;
    int i = 1;
    for (p3 = Mymap2.begin(); p3 != Mymap2.end(); ++p3)
    {
        cout << i << ")\t";
        cout << p3->second << "\n";
        i++;
    }

}

void Task2()
{
    cout << "TASK 2" << endl << endl;
    int size;
    size = getCorrectNumber();

    multimap<float, Money> Mymap;
    multimap<float, float>::iterator it;
    Money element;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        Mymap.insert(make_pair(i, element));
    }


    cout << "Task 2" << endl << "Исходный словарь" << endl;
    multimap<float, Money>::iterator p2;
    for (p2 = Mymap.begin(); p2 != Mymap.end(); ++p2)
        cout << p2->first + 1 << ")\t" << p2->second << '\n';

    float sr = srednee(Mymap);
    cout << "Среднее арифметическое = ";
    cout << sr << endl;

    multimap<float, Money> Mymap2;
    multimap<float, Money>::iterator p3;
    for (p3 = Mymap.begin(); p3 != Mymap.end(); ++p3)
    {
        int i = 0;
        if ((p3->second.GetRub() * 1.0 + p3->second.GetKop() / 100.0) < sr)
        {
            Mymap2.insert(make_pair(i, p3->second));
        }
        i++;
    }

    multimap<float, Money>::iterator p4;
    cout << "После удаления элементов больше среднего арифметического" << endl;
    int i = 1;
    for (p4 = Mymap2.begin(); p4 != Mymap2.end(); ++p4)
    {

        cout << i << ")\t" << p4->second << '\n';
        i++;
    }

}

void Task3()
{
    cout << "TASK 3" << endl << endl;
    int size;
    size = getCorrectNumber();
    Vector<float> storage(size);
    for (int i = 0; i < storage.size(); i++)
    {
        cout << "Enter " << i + 1 << " element:\t";
        cin >> storage[i];
    }
    cout << "Your Vector:" << endl;
    cout << storage << endl;
    float max = storage.GetMax();
    cout << "Max = " << max << endl;
    cout << "Каждый элемент вектора домножен на максимальный" << endl;
    for (int i = 0; i < storage.size(); i++)
    {
        storage[i] *= max;
    }
    cout << storage << endl;

}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    Task1();
    Task2();
    Task3();
}