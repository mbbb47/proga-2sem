#pragma once
#include <stdexcept>

using namespace std;

/// @brief класс Stack реализует стек с использованием связного списка
///@tparam <т> тип данных, который будет храниться в стеке

template <typename T>
class Stack
{
private:
/// @brief внутренний класс Node представляет узел связного списка
    class Node
    {
    public:
        T data; 
        Node* next; 
 /// @brief конструктор узла
 /// @param data Данные, которые будут храниться в узле
 /// @param next Указатель на следующий узел (по умолчанию nullptr)
        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    Node* head; 
    int counter; 

public:
/// @brief Конструктор стека

    Stack() : head(nullptr), counter(0) {}

/// @brief Деструктор стека
/// Освобождает память, занятую элементами стека
/// 
    ~Stack()
    {
        clear();
    }

///@brief Добавляет элемент на вершину стека
///@param value Значение, которое будет добавлено в стек
/// 
    void push(T value)
    {
        head = new Node(value, head);
        counter++;
    }


///@brief удаляет и возвращает элемент с вершины стека
///@return T значение, которое было на вершине стека
///@throws out_of_range Если стек пуст

    T pop()
    {
        if (head == nullptr)
        {
            throw out_of_range("Stack is empty");
        }
        T value = head->data;
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        counter--;
        return value;
    }

     ///@brief Возвращает значение элемента на вершине стека без его удаления.
     ///@return T Значение, которое находится на вершине стека.
     ///@throws out_of_range Если стек пуст.

    T peek() const
    {
        if (head == nullptr)
        {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }

     ///@brief Возвращает количество элементов в стеке.
     ///@return int Количество элементов в стеке.
     /// 
    int count() const
    {
        return counter;
    }

     /// @brief Очищает стек, удаляя все элементы.

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        counter = 0;
    }
};
