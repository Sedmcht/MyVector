#pragma once
#include"BadRange.h"
#include"BadLength.h"

class MyVector
{
	int _size{};
	int* _heapPtr{};

public:

	MyVector();

	MyVector(int size);

	MyVector(const MyVector& otherArray);

	~MyVector();

	MyVector& operator= (const MyVector& otherArray);

	int& operator[](int index);

	int getSize();

	int findValue(int value, int position = 0);

	void erase();

	void resize(int newSize);

	void remove(int wasteIndex);

	void insertBefore(int value, int targetIndex);

	void insertAtBeginning(int value);

	void insertAtEnd(int value);

};

