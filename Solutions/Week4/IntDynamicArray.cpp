#include "IntDynamicArray.h"

IntDynamicArray::IntDynamicArray() :arr(nullptr), capacity(0), currCount(0) {}

IntDynamicArray::IntDynamicArray(size_t capacity) : arr(new int[capacity]), capacity(capacity), currCount(0) {}

IntDynamicArray::IntDynamicArray(const IntDynamicArray& other) : arr(new int[capacity]),capacity(other.capacity),currCount(other.currCount) {
	for (int i = 0; i < other.currCount;i++) {
		arr[i] = other.arr[i];
	}
}

IntDynamicArray::~IntDynamicArray() {
	delete[] arr;
	arr = nullptr;
}

void IntDynamicArray::pushBack(int value) {
	if (capacity <= currCount) {
		return;
	}
	arr[currCount] = value;
	currCount++;
}

void IntDynamicArray::popBack() {
	if (currCount == 0) {
		return;
	}
	currCount--;
}

int IntDynamicArray::getAt(size_t index) const {
	if (0 > index || index >= currCount) return 0;

	return arr[index];
}

void IntDynamicArray::setAt(size_t index, int value) {
	if (0 > index || index >= currCount) return;

	arr[index] = value;
}

size_t IntDynamicArray::getSize() const {
	return currCount;
}

size_t IntDynamicArray::getCapacity() const{
	return capacity;
}

bool IntDynamicArray::isEmpty() const {
	return currCount == 0;
}

void IntDynamicArray::resize(size_t newCapacity) {
	int* newArr = new int[newCapacity];

	for (size_t i = 0; i < currCount; ++i) {
		newArr[i] = arr[i];
	}

	delete[] arr;

	arr = newArr;
	capacity = newCapacity;
}
