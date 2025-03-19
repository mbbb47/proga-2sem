#include <iostream>
#include "cycleList.h"

using namespace std;

/// <summary>
/// Вставляет единицу перед каждым отрицательным элементом в циклическом списке.
/// </summary>
/// <param name="list">Циклический список, в который будут добавлены единицы.</param>
void befNegat(CycleList<int>& list) {
    int count = list.count();
    for (int i = 0; i < count; i++) {
        if (list[i] < 0) {
            list.insert(i, 1);
            i++;
            count++;
        }
    }
}

/// <summary>
/// Удаляет все отрицательные элементы из циклического списка.
/// </summary>
/// <param name="list">Циклический список, из которого будут удалены отрицательные элементы.</param>
void DelNegatives(CycleList<int>& list) {
    int i = 0;
    while (i < list.count()) {
        if (list[i] < 0) {
            list.removeAt(i);
        }
        else {
            i++;
        }
    }
}

/// <summary>
/// Выводит элементы циклического списка на экран.
/// </summary>
/// <param name="list">Циклический список, элементы которого будут выведены.</param>
void print(const CycleList<int>& list) {
    for (int i = 0; i < list.count(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

/// <summary>
/// Отображает меню доступных команд для работы с циклическим списком.
/// </summary>
void Menu() {
    cout << "==============================\n";
    cout << "| 1. добавить элемент        |\n";
    cout << "| 2. вставить элемент        |\n";
    cout << "| 3. удалить элемент по индексу |\n";
    cout << "| 4. получить элемент по индексу |\n";
    cout << "| 5. посчитать количество элементов |\n";
    cout << "| 6. посчитать количество вхождений значения |\n";
    cout << "| 7. очистить список        |\n";
    cout << "| 8. вставить 1 перед каждым отрицательным элементом |\n";
    cout << "| 9. удалить все отрицательные элементы |\n";
    cout << "| 10. вывод списка        |\n";
    cout << "| 0. выход                |\n";
    cout << "==============================\n";
    cout << "выберите команду: ";
}

/// <summary>
/// Главная функция программы, которая управляет циклическим списком.
/// </summary>
/// <returns>Код завершения программы.</returns>
int main() {
    CycleList<int> list;
    int command, value, num;

    while (true) {
        Menu();
        cin >> command;

        switch (command) {
        case 1:
            cout << "введите значение: ";
            cin >> value;
            list.add(value);
            break;
        case 2:
            cout << "введите индекс и значение: ";
            cin >> num >> value;
            list.insert(num, value);
            break;
        case 3:
            cout << "введите индекс: ";
            cin >> num;
            list.removeAt(num);
            break;
        case 4:
            cout << "введите индекс: ";
            cin >> num;
            if (num >= 0 && num < list.count()) {
                cout << "элемент с индексом " << num << ": " << list[num] << endl;
            }
            else {
                cout << "индекс вышел за границы" << endl;
            }
            break;
        case 5:
            cout << "количество элементов: " << list.count() << endl;
            break;
        case 6:
            cout << "введите значение: ";
            cin >> value;
            cout << "количество вхождений " << value << ": " << list.count(value) << endl;
            break;
        case 7:
            list.clear();
            cout << "список очищен \n";
            break;
        case 8:
            befNegat(list);
            cout << "вставлены единицы перед каждым отрицательным элементом\n";
            break;
        case 9:
            DelNegatives(list);
            cout << "все отрицательные элементы удалились \n";
            break;
        case 10:
            print(list);
            break;
        case 0:
            return 0;
        default:
            cout << "ошибка. \n";
        }
    }

    return 0;
}
