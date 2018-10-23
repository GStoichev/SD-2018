#pragma once
#include <string>
#include <fstream>

class Point
{
public:
	Point() : x(0), y(0), name("") {};
	Point(int x, int y, std::string name) : x(x), y(y), name(name) {};
	Point(const Point& other) = default;
	Point& operator=(const Point& other) = default;
	~Point() = default;

	void Save(std::ofstream& stream);
	void Load(std::ifstream& stream);
	void Print() const;

private:
	int x;
	int y;
	std::string name;
};
