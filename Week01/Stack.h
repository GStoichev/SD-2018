#pragma once

template <typename T> struct Node
{
	Node<T>* next;
	T value;
};

template <typename T> class Stack
{
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack<T>& other);
	~Stack();

	void push(const T& value);
	void pop();
	const T& peek() const;
	T getTop() const;
	const size_t getSize() const;

private:
	size_t size;
	Node<T>* top;

	void copyFunc(const Stack<T>& other);
	void deleteStack();
};

template <typename T> Stack<T>::Stack()
{
	this->size = 0;
	this->top = nullptr;
}

template <typename T> Stack<T>::Stack(const Stack<T>& other)
{
	this->copyFunc(other);
}

template <typename T> Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		this->deleteStack();
		this->copyFunc(other);
	}
	return *this;
}

template <typename T> Stack<T>::~Stack()
{
	this->deleteStack();
}

template <typename T> const T& Stack<T>::peek() const
{
	return this->top->value;
}

template <typename T> T Stack<T>::getTop() const
{
	return this->top->value;
}

template <typename T> void Stack<T>::push(const T& value)
{
	Node<T>* newNode = new Node<T>;
	newNode->next = this->top;
	newNode->value = value;
	this->top = newNode;
	this->size++;
}

template <typename T> void Stack<T>::pop()
{
	if (this->top)
	{
		Node<T>* removeMe = this->top;
		this->top = this->top->next;
		delete removeMe;
		this->size--;
	}
}

template <typename T> const size_t Stack<T>::getSize() const
{
	return this->size;
}

//Private methods
template <typename T> void Stack<T>::copyFunc(const Stack<T>& other)
{
	this->size = other.size;
	if (this->size)
	{
		this->top = new Node<T>;
		this->top->value = other.top->value;
		this->top->next = nullptr;

		Node<T>* thisNode = this->top;
		const Node<T>* otherNode = other.top;

		otherNode = otherNode->next;

		while (otherNode)
		{
			Node<T>* newNode = new Node<T>;
			newNode->value = otherNode->value;
			newNode->next = nullptr;

			thisNode->next = newNode;
			thisNode = thisNode->next;
			otherNode = otherNode->next;
		}
	}
	else {
		this->top = nullptr;
	}
}

template <typename T> void Stack<T>::deleteStack()
{
	while (this->top)
	{
		Node<T>* deleteMe = this->top;
		this->top = this->top->next;
		delete deleteMe;
		this->size--;
	}
}