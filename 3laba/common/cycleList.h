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
	};
	Node* head = nullptr;
	Node* last = nullptr;
	int counter = 0;

public:

	/// <summary>
	/// Конструктор по умолчанию для списка.
	/// </summary>
	 
	CycleList() = default;

	/// <summary>
	/// Деструктор, который очищает список.
	/// </summary>
	
	~CycleList()
	{
		clear();
	}

	/// <summary>
	/// Добавляет элемент в конец списка.
	/// </summary>
	/// <param name="data">Данные, которые нужно добавить в список.</param>
	
	void add(T data)
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

	/// <summary>
	/// Вставляет элемент по указанному индексу.
	/// </summary>
	/// <param name="num">Индекс, по которому нужно вставить элемент.</param>
	/// <param name="data">Данные, которые нужно вставить в список.</param>
	/// <exception cref="out_of_range">Выбрасывается, если индекс выходит за пределы списка.</exception>
	
	void insert(int num, T data)
	{
		if (num < 0 || num > counter)
		{
			throw out_of_range("Индекс вне диапазона");
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

	/// <summary>
	/// Удаляет элемент по указанному индексу.
	/// </summary>
	/// <param name="num">Индекс элемента, который нужно удалить.</param>
	/// <exception cref="out_of_range">Выбрасывается, если индекс выходит за пределы списка.</exception>
	 
	void removeAt(int num)
	{
		if (num < 0 || num >= counter)
		{
			throw out_of_range("Индекс вне диапазона");
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
			Node* numNode = head;
			for (int i = 0; i < num - 1; i++)
			{
				numNode = numNode->next;
			}
			Dele = numNode->next;
			numNode->next = Dele->next;
			if (num == counter - 1)
			{
				last = numNode;
			}
		}
		delete Dele;
		counter--;
	}

	/// <summary>
	/// Получает элемент по указанному индексу.
	/// </summary>
	/// <param name="index">Индекс элемента, который нужно получить.</param>
	/// <returns>Ссылка на данные элемента.</returns>
	/// <exception cref="out_of_range">Выбрасывается, если индекс выходит за пределы списка.</exception>

	T& operator[](const int index)
	{
		if (index < 0 || index >= counter)
		{
			throw out_of_range("индекс вышел за пределы");
		}
		Node* numNode = head;
		for (int i = 0; i < index; i++)
		{
			numNode = numNode->next;
		}
		return numNode->data;
	}

	/// <summary>
	/// Возвращает количество элементов в списке.
	/// </summary>
    /// <returns>Количество элементов в списке.</returns>
	 
	int count() const
	{
		return counter;
	}

	/// <summary>
	/// Возвращает количество элементов, равных заданным данным.
	/// </summary>
	/// <param name="data">Данные, для которых нужно подсчитать количество вхождений.</param>
	/// <returns>Количество вхождений заданных данных в списке.</returns>
	 
	int countVV(T data) const
	{
		int cnt = 0;
		Node* current = head;
		for (int i = 0; i < counter; i++)
		{
			if (current->data == data)
			{
				cnt++;
			}
			current = current->next;
		}
		return cnt;
	}

	/// <summary>
	/// Очищает список, удаляя все элементы.
	/// </summary>
	/// 
	void clear()
	{
		while (counter > 0)
		{
			removeAt(0);
		}
	}
};