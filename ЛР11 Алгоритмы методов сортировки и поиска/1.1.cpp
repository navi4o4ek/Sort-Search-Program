#include <iostream>      
#include <fstream>
#include <windows.h>
#include "1.1.h"
using namespace std;

int menu();
static int flag = 0;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int count, sch;
    sch = loadFromFile();
    count = generate_array();
    cop(count);
    cout << "������ 10 ��������� ���������� �������:" << endl;
    out();

    while (1)
    {
        switch (menu())
        {
         
        case 1: bubble_sort(count); break;
        case 2: min_sort(count); break;
        case 3: insert_sort(count); break;
        case 4: shell_sort(count); break;
        case 5: hoare_sort_t(count, 0, count - 1); break;
        case 6: bogosort(count); break;
        case 7: if (flag)
            find_b(count);
              else
            find(count);
            break;
        case 8: count = regenerate_array(); cop(count); cout << "������ 10 ��������� ���������� �������:" << endl; out(); break;
        case 9: sort(sch); break;
        case 10: saveToFile(sch); saveToFileMas(count); return 0;
        }
    }
}

//����
int menu()
{
    register int er;
    cout << "�������:\n";
    cout << "1- ��� ���������� ������� ��������\n";
    cout << "2- ��� ���������� ������� ������\n";
    cout << "3- ��� ���������� ������� �������\n";
    cout << "4- ��� ���������� ������� �����\n";
    cout << "5- ��� ���������� ������� �����\n";
    cout << "6- ��� ���������� �������� �������\n";
    cout << "7- ��� ������ �������� \n";
    cout << "8- ��� ����������� ������� \n";
    cout << "9- ��� ���������� ���������\n";
    cout << "10- ��� ������\n";
    cin >> er;
    while (er <= 0 || er > 10 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
        cin >> er;
    }
    if (er < 7) flag = 1;
    return er;
}