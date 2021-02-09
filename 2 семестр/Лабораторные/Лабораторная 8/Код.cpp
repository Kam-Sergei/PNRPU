#include <iostream> 
#include <stdio.h>
using namespace std;
FILE* file;

struct Inform {
    string bearer;       //носитель
    int volume;          //объём
    string title;        //название        
    string author;       //автор
};

void vvod(int n)
{
    n = n + 1;
    Inform* st = new Inform[n];
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите " << i + 1 << " элемент:" << endl;
        cout << "  Носитель: ";
        cin >> st[i].bearer;
        cout << "  Объём: ";
        cin >> st[i].volume;
        cout << "  Название: ";
        cin >> st[i].title;
        cout << "  Автор: ";
        cin >> st[i].author;
    }
    if ((file = fopen("t", "w")) == NULL)
    {
        perror("Ошибка при открытии файла");
        exit(0);
    }
    fwrite(&st, sizeof(Inform), 1, file);
    fclose(file);
    cout << endl;
}

void vivod(int n)
{
    Inform* st = new Inform[n];
    cout << "Элементы  структуры:" << endl;
    if (n == 0)
    {
        cout << "В структуре нет элементов " << endl;
    }
    else {
        if ((file = fopen("t", "rb")) == NULL)
        {
            perror("Ошибка при открытии файла");
            exit(0);
        }
        fread(&st, sizeof(n), 1, file);
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " элемент:" << endl;
            cout << "Носитель: " << st[i].bearer << "  ";
            cout << "Объём: " << st[i].volume << "  ";
            cout << "Название: " << st[i].title << "  ";
            cout << "Автор: " << st[i].author << "  ";
            cout << endl;
        }
    }
    fclose(file);
    cout << endl;
}

int del(int n)
{
    Inform* st = new Inform[n];
    if ((file = fopen("t", "rb")) == NULL)
    {
        perror("Ошибка при открытии файла");
        exit(0);
    }
    fread(&st, sizeof(n), 1, file);
    fclose(file);
    int k = -1;
    int d;
    cout << "Введите объём первого элемнта, который надо удалить: ";
    cin >> d;
    for (int i = 0; i < n; i++)
    {
        if (st[i].volume == d)
        {
            k = i;
            i = n;
        }
    }
    if (k == -1)
    {
        cout << "Элемент не найден" << endl;
    }
    else {
        for (int i = k; i < n - 1; i++)
        {
            st[i].bearer = st[i + 1].bearer;
            st[i].volume = st[i + 1].volume;
            st[i].title = st[i + 1].title;
            st[i].author = st[i + 1].author;
        }
        n = n - 1;
    }
    cout << endl;
    if ((file = fopen("t", "w")) == NULL)
    {
        perror("Ошибка при открытии файла");
        exit(0);
    }
    fwrite(&st, sizeof(Inform), 1, file);
    fclose(file);
    return n;
}

int add(int n)
{
    Inform* st = new Inform[n];
    if ((file = fopen("t", "rb")) == NULL)
    {
        perror("Ошибка при открытии файла");
        exit(0);
    }
    fread(&st, sizeof(n), 1, file);
    fclose(file);
    if (n != 0)
    {
        int d;
        cout << "Введите номер элемента, перед которым надо добавить элемент: ";
        cin >> d;
        d = d - 1;
        st[n].bearer = st[n - 1].bearer;
        st[n].volume = st[n - 1].volume;
        st[n].title = st[n - 1].title;
        st[n].author = st[n - 1].author;
        int i;
        i = n - 1;
        if (n != 1)
        {
            while (i != d)
            {
                st[i].bearer = st[i - 1].bearer;
                st[i].volume = st[i - 1].volume;
                st[i].title = st[i - 1].title;
                st[i].author = st[i - 1].author;
                i = i - 1;
            }
        }
        cout << "Введите новый элемент:" << endl;
        cout << "Носитель: ";
        cin >> st[d].bearer;
        cout << "Объём: ";
        cin >> st[d].volume;
        cout << "Название: ";
        cin >> st[d].title;
        cout << "Автор: ";
        cin >> st[d].author;
        cout << endl;
        n = n + 1;
        if ((file = fopen("t", "w")) == NULL)
        {
            perror("Ошибка при открытии файла");
            exit(0);
        }
        fwrite(&st, sizeof(Inform), 1, file);
        fclose(file);
    }
    else {
        cout << "В структуре нет элементов, поэтому добавить элемент перед элементом с указанным номером не вохможно" << endl << endl;
    }
    return n;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите количество элементов в структуре: ";
    cin >> n;
    vvod(n);
    vivod(n);
    n = del(n);
    vivod(n);
    n = add(n);
    vivod(n);
    return 0;
}