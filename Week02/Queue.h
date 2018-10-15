#pragma once


template <typename T> struct Node
{
	T value;
	Node<T>* next;
};

template <typename T> class Queue
{
public:
	Queue();
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	~Queue();

	void push(const T& value);
	void pop();
	const T& front();
	const T& back();

private:
	Node<T>* first;
	Node<T>* last;
	size_t size;

	void copyFunc(const Queue<T>& other);
	void deleteFunc();
};

template <typename T> Queue<T>::Queue()
{
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template <typename T> Queue<T>::Queue(const Queue<T>& other)
{
	this->copyFunc(other);
}

template <typename T> Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		this->deleteFunc();
		this->copyFunc(other);
	}
	return *this;
}

template <typename T> Queue<T>::~Queue()
{
	this->deleteFunc();
}

template <typename T> void Queue<T>::push(const T& value)
{
	Node<T>* newElement = new Node<T>();
	newElement->value = value;
	newElement->next = nullptr;

	if (this->first == nullptr)
	{
		this->first = this->last = newElement;
	}
	else {
		this->last->next = newElement;
		this->last = this->last->next;
	}
	this->size++;

}

template <typename T> void Queue<T>::pop()
{
	if (this->first != nullptr)
	{
		Node<T>* deleteMe = this->first;
		this->first = this->first->next;
		if (deleteMe == this->last)
		{
			delete deleteMe;
			this->first = this->last = nullptr;
		}
		else
		{
			delete deleteMe;
		}
		this->size--;
		
	}
}

template <typename T> const T& Queue<T>::front()
{
	if (this->first)
	{
		return this->first->value;
	}
	return T();
}

template <typename T> const T& Queue<T>::back()
{
	if (this->last)
	{
		return this->last->value;
	}
	return T();
}

template <typename T> void Queue<T>::copyFunc(const Queue<T>& other)
{
	this->size = other.size;
	if (this->size)
	{
		this->first = new Node<T>;
		Node<T>* otherNode = other.first;
		Node<T>* thisNode = this->first;

		while (otherNode->next != nullptr)
		{
			thisNode->value = otherNode->value;
			thisNode->next = new Node<T>;

			thisNode = thisNode->next;
			otherNode = otherNode->next;
		}

		thisNode->value = otherNode->value;
		thisNode->next = otherNode->next;

		this->last = thisNode;
		this->last->next = nullptr;
	}
	else
	{
		this->first = this->last = nullptr;
	}
}

template <typename T> void Queue<T>::deleteFunc()
{
	while (this->first != nullptr)
	{
		this->pop();
	}
}
