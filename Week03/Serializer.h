#pragma once
#include <fstream>
#include <queue>
#include <list>
#include <stack>
#include "Point.h"

class Serializer
{
public:
	Serializer() : fileName("") {};
	Serializer(const char* fileName) : fileName(fileName) {};
	Serializer(const Serializer& other) = default;
	Serializer& operator=(const Serializer& other) = default;
	~Serializer() = default;

	void setQueue(const std::queue<Point>& queue) { this->queue = queue; };
	std::queue<Point> getQueue() const;
	void setStack(const std::stack<Point>& stack) { this->stack = stack; };
	std::stack<Point> getStack() const;
	void setList(const std::list<Point>& list) { this->list = list; };
	std::list<Point> getList() const;

	void LoadQueue();
	void SaveQueue();
	void LoadList();
	void SaveList();
	void LoadStack();
	void SaveStack();

private:
	std::string fileName;
	std::queue<Point> queue;
	std::list<Point> list;
	std::stack<Point> stack;
};
