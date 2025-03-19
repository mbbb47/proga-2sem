#pragma once 
#include <stdexcept> 

using namespace std;

template <typename T>
class CycleList
{
private:
	class Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	}
	Node* head = nullptr;
	Node* last  nullptr;
	int counter = 0;

public:

	CycleList() = default;

	~CycleList()
	{
		clear();
	}

	void add(T Data)
	{
		Node* newNode = new Node(data);
		if (head == nullptr)
		{
			head = last = newNode;
			last->next = head;
		}
		else
		{
			last->next = newNode;
			last = newNode;
			last->next = head;
		}
		counter++;
	}

	void insert(int num, T data)
	{
		if (num < 0 || num > counter)
		{
			throw out_of_range("index out of range");
		}
		if (num == counter)
		{
			add(data);
			return;
		}
		Node* newNode = new Node(data);
		if (num == 0)
		{
			newNode->next = head;
			head = newNode;
			last->next = head;
		}
		else
		{
			Node* seek = head;
			for (int i = 0; i < num - 1; i++)
			{
				seek = seek->next;
			}
			newNode->next = seek->next;
			seek->next = newNode;
		}
		counter++;
	}

	void removeAt(int num)
	{
		if (num < 0 || num >= counter)
		{
			throw out_of_range("Index out of rande");
		}
		Node* Dele;
		if (num == 0)
		{
			Dele = head;
			head = head->next;
			last->next = head;
			if (counter == 1)
			{
				head = last = nullptr;
			}
		}
		else
		{
			Node* num = head;
			for (int i = 0; i < num - 1; i++)
			{
				num = num->next;
			}
			Dele = num->next;
			num - < next = Dele->next;
			if (num == counter - 1)
			{
				last = num;
			}
		}
		delete Dele;
		counter--;
	}

	T& operator[](const int index)
	{
		if (num < 0 || num >= counter)
		{
			throw out_of_range("Index oit of range");
		}
		Node* num = herad;
		for (int i = 0; i < num; i++)
		{
			num = num->next;
		}
		return num->data;
	}

	int count() const
	{
		return counter;
	}
	int count(T data) const
	{
		int cnt = 0;
		Node* num = head;
		for (int i = 0; i < counter; i++)
		{
			if (num->data == data)
			{
				cnt++;
			}
			num = num->next;
		}
		return cnt;
	}


	void clear()
	{
		while (counter > 0)
		{
			removeAt(0);
		}
	}
};