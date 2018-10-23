#include "Serializer.h"

void Serializer::SaveQueue()
{
	std::ofstream stream(this->fileName, std::ios::binary | std::ios::out);
	if (stream)
	{
		int size = this->queue.size();
		stream.write((char*)&size, sizeof(size));

		while (!this->queue.empty())
		{
			printf("Queue saved point : ");
			this->queue.front().Print();
			this->queue.front().Save(stream);
			this->queue.pop();
		}
	}
	stream.close();
}

void Serializer::LoadQueue()
{
	std::ifstream stream(this->fileName, std::ios::binary | std::ios::in);
	if (stream)
	{
		size_t size = 0;
		stream.read((char*)&size, sizeof(this->queue.size()));

		for (size_t i = 0; i < size; i++)
		{
			Point p;
			p.Load(stream);
			this->queue.push(p);
			printf("Queue loaded point : ");
			this->queue.back().Print();
		}

	}
	stream.close();
}

void Serializer::SaveStack()
{
	std::ofstream stream(this->fileName, std::ios::binary | std::ios::out);
	if (stream)
	{
		int size = this->stack.size();
		stream.write((char*)&size, sizeof(size));

		while (!this->stack.empty())
		{
			printf("Stack saved point : ");
			this->stack.top().Print();
			this->stack.top().Save(stream);
			this->stack.pop();
		}
	}
	stream.close();
}

void Serializer::LoadStack()
{
	std::ifstream stream(this->fileName, std::ios::binary | std::ios::in);
	if (stream)
	{
		size_t size = 0;
		stream.read((char*)&size, sizeof(size));

		for (size_t i = 0; i < size; i++)
		{
			Point p;
			p.Load(stream);
			this->stack.push(p);
			printf("Stack loaded point : ");
			this->stack.top().Print();
		}
	}
	stream.close();
}

void Serializer::SaveList()
{
	std::ofstream stream(this->fileName, std::ios::binary | std::ios::out | std::ios::trunc);
	if (stream)
	{
		int size = this->list.size();
		stream.write((char*)&size, sizeof(size));

		while (!this->list.empty())
		{
			printf("List saved point : ");
			this->list.front().Print();
			this->list.front().Save(stream);
			this->list.pop_front();
		}
	}
	stream.close();
}

void Serializer::LoadList()
{
	std::ifstream stream(this->fileName, std::ios::binary | std::ios::in);
	if (stream)
	{
		size_t size = 0;
		stream.read((char*)&size, sizeof(size));

		for (size_t i = 0; i < size; i++)
		{
			Point p;
			p.Load(stream);
			this->list.push_back(p);
			printf("List loaded point : ");
			this->list.back().Print();
		}
	}
	stream.close();
}

std::queue<Point> Serializer::getQueue() const
{
	return this->queue;
}

std::stack<Point> Serializer::getStack() const
{
	return this->stack;
}

std::list<Point> Serializer::getList() const
{
	return this->list;
}