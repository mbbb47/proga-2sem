#include "queue.h"
#include <iostream>


using namespace std;

/// <summary>
/// вставляет единицу перед каждым отрицательным числом
/// </summary>
/// <param name="queue">очередь, в которую нужно вставить элементы</param>

void implement(Queue<int>& queue)
{
    int Count0 = queue.count();
    for (int i = 0; i < Count0; i++)
    {
        int temp_num = queue.unqueue();
        if (temp_num < 0)
        {
            queue.queue(1);
        }
        queue.queue(temp_num);
    }
}

/// <summary>
/// удаляет все отрицательные числа из очереди
/// </summary>
/// <param name="queue">очередь, из которой нужно удалить элементы</param>
void deleteNeg(Queue<int>& queue)
{
    int Count0 = queue.count();
    for (int i = 0; i < Count0; i++)
    {
        int temp_num = queue.unqueue();
        if (temp_num >= 0)
        {
            queue.queue(temp_num);
        }
    }
}

/// <summary>
/// подсчитывает количество вхождений в очередь определенного числа
/// </summary>
/// <param name="queue">очередь, в которой нужно посчитать вхождения</param>
/// <param name="value">число, количество вхождений которого нужно посчитать </param>
/// <returns>количество вхождений в очередь</returns>
int countEntries(Queue<int>& queue, int value)
{
    int counter = 0;
    int Count0 = queue.count();
    for (int i = 0; i < Count0; i++)
    {
        int temp_num = queue.unqueue();
        if (temp_num == value)
        {
            counter++;
        }
        queue.queue(temp_num);
    }
    return counter;
}

/// <summary>
/// вылезает меню действий
/// </summary>
/// 
void Menu()
{
    cout << "(1) добавить новый элемент в очередь\n";
    cout << "(2) достать элемент из очереди\n";
    cout << "(3) Узнать количество элементов\n";
    cout << "(4) очистить очередь\n";
    cout << "(5) вставить 1 перед каждым отрицательным числом\n";
    cout << "(6) удалить все отрицательные числа\n";
    cout << "(7) посчитать количество вхождений чисел\n";
    cout << "(8) закончить выполнение\n";
    cout << "команда №:  ";
}

int main()
{
    Queue<int> queue;
    int command;

    while (true)
    {
        Menu();
        cin >> command;

        switch (command)
        {
        case 1:
        {
            int num;
            cout << "Число: ";
            cin >> num;
            queue.queue(num);
            cout << "элемент добавлен.\n";
            break;
        }
        case 2:
        {
            if (queue.count() == 0)
            {
                cout << "ошибка.очередь пустая.\n";
            }
            else
            {
                int item = queue.unqueue();
                cout << "извлеченный элемент: " << item << "\n";
            }
            break;
        }

        case 3:
        {
            cout << "количество элементов в очереди: " << queue.count() << "\n";
            break;
        }
        case 4:
        {
            queue.clear();
            cout << "очередь очищена.\n";
            break;
        }
        case 5:
        {
            implement(queue);
            cout << "вставка выполнена.\n";
            break;
        }
        case 6:
        {
            deleteNeg(queue);
            cout << "отрицательные числа удалены.\n";
            break;
        }
        case 7:
        {
            int value;
            cout << "введите число для подсчета: ";
            cin >> value;
            int repeat = countRepeat(queue, value);
            cout << "число" << value << " повторяется " << repeat << " раз(а)\n";
            break;
        }
        case 8:
        {
            cout << "выход из программы.\n";
            return 0;
        }
        default:
        {
            cout << "неверный выбор. ошибка\n";
            break;
        }
        }
    }

    return 0;
}