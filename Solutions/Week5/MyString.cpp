#include "MyString.h"
#define _CRT_SECURE_NO_WARNINGS
//char* data;
//size_t len;
//size_t capacity;

void MyString::resize(const size_t newCapacity)
{
	capacity = newCapacity;
	char* newData = new char[newCapacity];
	strcpy(newData, data);
	delete[] data;
	data = newData;
}

void MyString::free()
{
	delete[] data;
	len = 0;
	capacity = 0;
	data = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
	char* newData = new char[other.capacity];
	strcpy(newData, other.data);
	data = newData;

	len = other.len;
	capacity = other.capacity;
}

void MyString::moveFrom(MyString&& other) noexcept
{
	len = other.len;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.capacity = other.len = 0;
}

MyString::MyString(const char* str)
{
	if (!str) {
		len = 0;
		capacity = 0;
		data = new char[capacity];
		data[0] = '\0';
		return;
	}
	len = strlen(str);
	capacity = len * 2;
	data = new char[capacity];

}

MyString::MyString(const MyString& other)//copy constructor
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

MyString& MyString::append(const MyString& other)
{
	size_t newLen = len + other.len;
	if (newLen >= capacity) {
		resize(newLen*2);
	}
	strcat(data, other.data);

	
}

const char* MyString::c_str() const
{
	return data;
}

size_t MyString::getLen() const
{
	return len;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

char& MyString::operator[](size_t idx)
{
	return data[idx];
}

const char& MyString::operator[](size_t idx) const
{
	return data[idx];
}

MyString MyString::reversed() const
{
	MyString res(*this);

	for (size_t i = 0; i < res.len/2; i++)
	{
		std::swap(data[i], data[res.len / 2-1]);
	}

	return res;
}
