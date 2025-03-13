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
    cout << "Первые 10 элементов созданного массива:" << endl;
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
        case 8: count = regenerate_array(); cop(count); cout << "Первые 10 элементов созданного массива:" << endl; out(); break;
        case 9: sort(sch); break;
        case 10: saveToFile(sch); saveToFileMas(count); return 0;
        }
    }
}

//МЕНЮ
int menu()
{
    register int er;
    cout << "Введите:\n";
    cout << "1- для сортировки методом пузырька\n";
    cout << "2- для сортировки методом выбора\n";
    cout << "3- для сортировки методом вставки\n";
    cout << "4- для сортировки методом Шелла\n";
    cout << "5- для сортировки методом Хоара\n";
    cout << "6- для сортировки болотным методом\n";
    cout << "7- для поиска элемента \n";
    cout << "8- для регенерации массива \n";
    cout << "9- для сортировки структуры\n";
    cout << "10- для выхода\n";
    cin >> er;
    while (er <= 0 || er > 10 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 10. Повторный ввод: ";
        cin >> er;
    }
    if (er < 7) flag = 1;
    return er;
}