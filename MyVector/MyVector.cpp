#include "MyVector.h"

MyVector::MyVector() = default;

MyVector::MyVector(int size) : _size(size)
{
	if (size < 0)
		throw BadLength();
	else
		_heapPtr = new int[size];
}

MyVector::~MyVector()
{
	delete[] _heapPtr;
}

MyVector::MyVector(const MyVector& otherArray)
{
	_size = otherArray._size;
	_heapPtr = new int[otherArray._size];

	for (int index = 0; index < otherArray._size; index++)
		_heapPtr[index] = otherArray._heapPtr[index];
}


MyVector& MyVector::operator= (const MyVector& otherArray)
{
	if (&otherArray == this)
		return *this;

	erase();

	_size = otherArray._size;

	if (otherArray._size > 0)
	{
		_heapPtr = new int[otherArray._size];

		for (int index = 0; index < otherArray._size; index++)
			_heapPtr[index] = otherArray._heapPtr[index];
	}
	else
		_heapPtr = nullptr;

	return *this;
}

int& MyVector::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw BadRange();

	return _heapPtr[index];
}


int MyVector::getSize()
{
	return _size;
}

void MyVector::erase()
{
	delete[] _heapPtr;
	_heapPtr = nullptr;
	_size = 0;
}

void MyVector::resize(int newSize)
{
	if (newSize == _size)
		return;

	if (newSize <= 0)
	{
		erase();
		return;
	}

	int* newHeapPtr = new int[newSize];
	int maxIndex{};

	if (_size < newSize)
		maxIndex = _size;
	else
		maxIndex = newSize;

	for (int index = 0; index < maxIndex; index++)
	{
		newHeapPtr[index] = _heapPtr[index];
	}

	delete[] _heapPtr;
	_heapPtr = newHeapPtr;
	_size = newSize;

}

void MyVector::remove(int wasteIndex)
{
	if (wasteIndex < 0 || wasteIndex >= _size)
		throw BadRange();

	if (_size - 1 == 0)
	{
		erase();
		return;
	}

	--_size;
	int* newHeapPtr = new int[_size];

	for (int index = 0; index < _size; index++)
	{
		if (index < wasteIndex)
			newHeapPtr[index] = _heapPtr[index];
		else
			newHeapPtr[index] = _heapPtr[index + 1];
	}

	delete[] _heapPtr;
	_heapPtr = newHeapPtr;
}

void MyVector::insertBefore(int value, int targetIndex)
{
	if (targetIndex < 0 || targetIndex > _size)
		throw BadRange();

	++_size;

	int* newHeapPtr = new int[_size];

	for (int index = 0; index < _size; index++)
	{
		if (index < targetIndex)
			newHeapPtr[index] = _heapPtr[index];

		if (index > targetIndex)
			newHeapPtr[index] = _heapPtr[index - 1];

		if (index == targetIndex)
			newHeapPtr[index] = value;
	}

	delete[] _heapPtr;
	_heapPtr = newHeapPtr;
}

int MyVector::findValue(int value, int position)
{
	if (position >= 0 && position < _size - 1)
	{

		for (int index = position; index < _size; index++)
		{
			if (_heapPtr[index] == value)
				return index;
		}

	}
	return -1;
}

void MyVector::insertAtBeginning(int value) { insertBefore(value, 0); }
void MyVector::insertAtEnd(int value) { insertBefore(value, _size); }

