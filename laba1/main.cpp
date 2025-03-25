#include <iostream>
#include "stack.h" 

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    Stack<int> stack;
    int value;

    cout << "введите числа для работы (если необходимо завершить программу введите 0):" << endl;
    while (cin >> value && value != 0)
    {
        stack.push(value);
    }

    cout << "числа в обратном порядке:" << endl;
    while (stack.count() > 0)
    {
        int num = stack.pop();
        if (num > 0)
        {
            cout << num << " ";
        }
    }

    return 0;
}