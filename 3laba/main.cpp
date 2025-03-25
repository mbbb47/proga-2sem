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
    cout << "==============================" << endl;
    cout << "| 1. Добавить элемент        |" << endl;
    cout << "| 2. Вставить элемент        |" << endl;
    cout << "| 3. Удалить элемент по номеру |" << endl;
    cout << "| 4. Получить элемент по номеру |" << endl;
    cout << "| 5. Посчитать количество элементов |" << endl;
    cout << "| 6. Посчитать количество вхождений значения |" << endl;
    cout << "| 7. Очистить список        |" << endl;
    cout << "| 8. Вставить 1 перед каждым отрицательным элементом |" << endl;
    cout << "| 9. Удалить все отрицательные элементы |" << endl;
    cout << "| 10. Вывод списка        |" << endl;
    cout << "| 0. Выход                |" << endl;
    cout << "==============================" << endl;
    cout << "Выберите команду: ";
}

/// <summary>
/// Обрабатывает пользовательскую команду
/// </summary>
/// <param name="list">Циклический список для работы</param>
/// <param name="command">Номер команды</param>
/// <returns>false если нужно завершить программу, true если продолжить</returns>
bool Commands(CycleList<int>& list, int command) {
    int value, num;

    switch (command) {
    case 1:
        cout << "Введите значение: ";
        cin >> value;
        list.add(value);
        break;
    case 2:
        cout << "Введите номер и значение: ";
        cin >> num >> value;
        list.insert(num, value);
        break;
    case 3:
        cout << "Введите номер: ";
        cin >> num;
        list.removeAt(num);
        break;
    case 4:
        cout << "введите число: ";
        cin >> num;
        if (num >= 0 && num < list.count()) {
            cout << "Элемент с номером " << num << ": " << list[num] << endl;
        }
        else {
            cout << "число вне диапозона комманд " << endl;
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
        cout << "список очищен" << endl;
        break;
    case 8:
        befNegat(list);
        cout << "вставлены 1 перед каждым отрицательным элементом" << endl;
        break;
    case 9:
        DelNegatives(list);
        cout << "отрицательные элементы удалены" << endl;
        break;
    case 10:
        print(list);
        break;
    case 0:
        return false;
    default:
        cout << "неправильно введенная команда" << endl;
    }
    return true;
}

/// <summary>
/// Главная функция программы, которая управляет циклическим списком.
/// </summary>
/// <returns>Код завершения программы.</returns>
int main() {
    CycleList<int> list;
    int Commands;

    while (true) {
        Menu();
        cin >> command;

        if (!Commands(list, command)) {
            break;
        }
    }

    return 0;
}