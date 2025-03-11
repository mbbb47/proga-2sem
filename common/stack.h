#pragma once
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
private:
    class Node
    {
    public:
        T data;
        Node* next;

        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    }

    Node* head;
    int counter;

public:
    Stack()
    {
        head = nullptr;
        counter = 0;
    }

    ~Stack()
    {
        clear();
    }

    void push(T value)
    {
        head = new Node(value, head);
        counter++;
    }

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

    T peek() const
    {
        if (head == nullptr)
        {
            throw out_of_range("Stack is empty");
        }
        return head->data;
    }

    int count() const
    {
        return counter;
    }

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