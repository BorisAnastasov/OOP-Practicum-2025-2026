#include "Parking.h"

//Car* car;
//size_t count;
//size_t capacity;

void Parking::copyFrom(const Parking& other)
{
	capacity = other.capacity;
	count = other.count;
	cars = new Car[capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		cars[i] = other.cars[i];
	}
}

void Parking::free()
{
	capacity = 0;
	count = 0;
	delete[] cars;
}

void Parking::resize(size_t newCapacity)
{
	capacity = newCapacity;
}

Parking::Parking(size_t cap):capacity(cap)
{
	cars= new Car[capacity];
}

Parking::Parking(const Parking& other):capacity(other.capacity), count(other.count)
{
	copyFrom(other);
}

Parking& Parking::operator=(const Parking& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Parking::~Parking()
{
	delete[] cars;
}

void Parking::addCar(const Car& car)
{
	if (count + 1 >= capacity) {
		resize(capacity * 2);
	}
	cars[count] = car;
	count++;
}

Car& Parking::getCar(size_t idx)
{
	return cars[idx];
}

const Car& Parking::getCar(size_t idx) const
{
	return cars[idx];
}

void Parking::removeCar(size_t idx)
{
	for (size_t i = idx; i < count-1; i++)
	{
		cars[i] = cars[i + 1];
	}
	count--;
}

size_t Parking::getCount() const
{
	return count;
}

size_t Parking::getCapacity() const
{
	return capacity;
}
