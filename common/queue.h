#pragma once
#include <stdexcept>

using namespace std;

/// <summary>
/// класс queue реализует структуру данных "очередь" при помощи связного списка
/// очередь работает по принципу, "Первый пришел - Первый вышел" (LIFO)
/// </summary>
/// <typeparam name=T>  тип данных, хранящихся в очереди</typeparam>
template <typename T>
class Queue
{
private:
    /// <summary>
    /// внутренний класс Node представляет узел связного списка
    /// </summary>
    struct Node
    {
        T data;
        Node* next;
        /// <summary>
        /// конструктор узла
        /// <summary>
        /// <param name="data">данные, которое буду храниться в узле.</param>
        /// <param name="next">указатель на следующий узел( nullptr по умолчанию) .</param>
        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    }

    Node* head = nullptr;
    Node* last = nullptr;
    int counter = 0;

public:

    /// <summary>
    /// конструктор, инициализация пустой очереди
    /// </summary>
 
    Queue() = default;

    ///<summary>
    /// деструктор. освобождает очередь
    ///</summary>
 
    ~Queue()
    {
        clear();
    }

    ///<summary>
    /// добавляет элемент в конец очереди
    /// <summary>
    /// <param name= "data"> элемент, который нужно добавить в очередь.</param>

    void queue(T data)
    {
        Node* newNode = new Node(data);
        if (last)
        {
            last->next = newNode;
        }
        else
        {
            head = newNode;
        }
        last = newNode;
        counter++;
    }

    /// <summary>
    ///удаляет и возвращает элемент из конца очереди
    /// <summary>
    /// <returns> элемент удаленный из конца очереди <returns>
 
    T unqueue()
    {
        if (!head)
        {
            throw out_of_range("пустая очередь");
        }
        T data = head->data;
        Node* temp = head;
        head = head->next;
        if (!head)
        {
            last = nullptr;
        }
        delete temp;
        counter--;
        return data;
    }

    /// <summary>
    /// возвращает кол-во элементов
    /// </summary>
    /// <returns>кол-во элементов в очереди
 
    int count() const
    {
        return counter;
    }

    ///<summary>
    /// очищает очередь
    /// </summary>

    void clear()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        last = nullptr;
        counter = 0;
    }
}; 
