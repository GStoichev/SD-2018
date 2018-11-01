#pragma once

#include <iostream>

template <typename T> struct Node
{
	T value;
	Node<T>* next;
};

template <typename T> class Iterator 
{
public:

	Iterator(Node<T>* node) : node(node) {};

	Iterator(const Iterator&) = default;
	Iterator& operator=(const Iterator&) = default;
	
	Iterator& operator++();
	Iterator operator++(int);

	bool operator==(const Iterator<T>& other);
	bool operator!=(const Iterator<T>& other);

	T& operator*();
	const T& operator*() const;

private:
	Node<T>* node;
};

template <typename T> Iterator<T>& Iterator<T>::operator++()
{
	// preincrement
	this->node = this->node->next;
	return (*this);
}

template <typename T> Iterator<T> Iterator<T>::operator++(int) 
{  // postincrement
	Iterator temp = *this;
	++*this;
	return (temp);
}

template <typename T> bool Iterator<T>::operator==(const Iterator<T>& other)
{
	return (this->node == other.node);
}

template <typename T> bool Iterator<T>::operator!=(const Iterator<T>& other)
{
	return !(*this == other);
}

template <typename T> T& Iterator<T>::operator*()
{
	return this->node->value;
}

template <typename T> const T& Iterator<T>::operator*() const
{
	return this->node->value;
}


template <typename T> class List
{
public:
	List();
	List(const List<T>& other);
	List& operator=(const List<T>& other);
	~List();

	void Pop_front();
	void Push_front(const T& value);
	const T& GetFirst() const;
	const T& GetLast() const;
	void Print() const;
	size_t GetSize() const { return this->size; };

	Iterator<T> Begin() { return Iterator<T>(this->first); }
	const Iterator<T> Begin() const { return Iterator<T>(this->first); }
	Iterator<T> End() { return Iterator<T>(nullptr); }
	const Iterator<T> End() const { return tierator<T>(nullptr); }

private:
	void copyFunc(const List<T>& other);

	size_t size;
	Node<T>* first;
	Node<T>* last;
};

template <typename T> List<T>::List()
{
	this->first = nullptr;
	this->last = nullptr;
}

template <typename T> List<T>::List(const List<T>& other)
{
	this->copyFunc(other);
}

template <typename T> const T& List<T>::GetFirst() const
{
	return this->first->value;
}

template <typename T> const T& List<T>::GetLast() const
{
	return this->last->value;
}

template <typename T> void List<T>::Push_front(const T& value)
{
	Node<T>* newNode = new Node<T>;
	newNode->value = value;
	newNode->next = this->first;
	
	if (!this->first)
	{
		this->last = newNode;
	}
	this->first = newNode;
}

template <typename T> void List<T>::Pop_front()
{
	if (this->first)
	{
		Node<T>* deleteMe = this->first;
		this->first = this->first->next;
		delete deleteMe;
		this->size--;
		if (this->first == this->last)
		{
			this->first = this->last = nullptr;
		}
	}
}

template <typename T> List<T>::~List()
{
	while (this->first)
	{
		Node<T>* deleteMe = this->first;
		this->first = this->first->next;
		delete deleteMe;
	}
}

template <typename T> void List<T>::Print() const 
{
	Node<T>* iterator = this->first;
	while (iterator != nullptr)
	{
		std::cout << iterator->value << ' ';
		iterator = iterator->next;
	}
	std::cout << std::endl;

}

template <typename T> void List<T>::copyFunc(const List<T>& other)
{

}

