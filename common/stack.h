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
 /// @param data Данные, который будут храниться в узле
 /// @param next указатель на следующий узел (по умолчанию nullprt)
        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    Node* head; 
    int counter; 

public:
/// @brief конструктора стека

    Stack() : head(nullptr), counter(0) {}

/// @brief деструктор стека
/// освобождает память, занятую элементами стека.
/// 
    ~Stack()
    {
        clear();
    }

///@brief добавляет элемент на вершину стека
///@param value значение, которое будет добавлено в стек
    void push(T value)
    {
        head = new Node(value, head);
        counter++;
    }


///@brief удаляет и возвращает элемент с вершины стека
///@return Т значение, которое было на вершине стека
///@throws out_of_range если стек пуст

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

///@brief возвращает значение элемента на вершине стека без его удаления 
///@return Т значение, которое находится на вершине стека
///@throws out_of_range если стек пуст

    T peek() const
    {
        if (head == nullptr)
        {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }

///@brief возвращает количество элементов в стеке
///@return int количество элементов в стеке

    int count() const
    {
        return counter;
    }

/// @brief очищает стек

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
