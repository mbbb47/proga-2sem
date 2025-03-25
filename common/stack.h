#pragma once
#include <stdexcept>

using namespace std;

/// @brief Класс Stack реализует стек с использованием связного списка.
///@tparam <т> Тип данных, который будет храниться в стеке.

template <typename T>
class Stack
{
private:
/// @brief Внутренний класс Node представляет узел связного списка.
    class Node
    {
    public:
        T data; 
        Node* next; 
 /// @brief Конструктор узла.
 /// @param Data Данные, который будут храниться в узле.
 /// @param Next Указатель на следующий узел (по умолчанию nullprt).
        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    Node* head; 
    int counter; 

public:
/// @brief Конструктора стека.

    Stack() : head(nullptr), counter(0) {}

/// @brief Деструктор стека.
/// Освобождает память, занятую элементами стека.
/// 
    ~Stack()
    {
        clear();
    }

///@brief Добавляет элемент на вершину стека.
///@param Value значение, которое будет добавлено в стек.
    void push(T value)
    {
        head = new Node(value, head);
        counter++;
    }

///@brief Удаляет и возвращает элемент с вершины стека.
///@return Т значение, которое было на вершине стека.
///@throws Out_of_range если стек пуст.

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
///@return Т значение, которое находится на вершине стека.
///@throws Out_of_range если стек пуст.

    T peek() const
    {
        if (head == nullptr)
        {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }

///@brief Возвращает количество элементов в стеке.
///@return Int количество элементов в стеке.

    int count() const
    {
        return counter;
    }

/// @brief Очищает стек.

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
