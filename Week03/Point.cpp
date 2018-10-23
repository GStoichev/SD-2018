#include "Point.h"

void Point::Print() const
{
	printf("%s - %d : %d \n", this->name.data(), this->x, this->y);
}

void Point::Save(std::ofstream& stream)
{
	stream.write((char*)&this->x, sizeof(this->x));
	stream.write((char*)&this->y, sizeof(this->y));
	int size = this->name.size();
	stream.write((char*)&size, sizeof(size));
	stream.write(this->name.data(), sizeof(char) * size);
}

void Point::Load(std::ifstream& stream)
{
	stream.read((char*)&this->x, sizeof(this->x));
	stream.read((char*)&this->y, sizeof(this->y));
	int size = 0;
	stream.read((char*)&size, sizeof(size));
	char* buffer = new char[size + 1];
	stream.read(buffer, sizeof(char) * size);
	buffer[size] = '\0';
	this->name.clear();
	this->name.append(buffer);

}