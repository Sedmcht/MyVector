#include <iostream>
#include "BadRange.h"
#include "BadLength.h"
#include "MyVector.h"
using namespace std;

int main()
{
	MyVector vec(10);

	for (int i{ 0 }; i < 10; ++i)
		vec[i] = i + 1;

	vec.resize(8);

	vec.insertBefore(20, 5);

	vec.remove(3);

	vec.insertAtEnd(30);

	vec.insertAtBeginning(40);

	{
		MyVector b{ vec };
		b = vec;
		b = b;
		vec = vec;
	}

	try
	{
		vec.remove(999);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		MyVector vec2(-1);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}


	cout << "Found value '5' at index  " << vec.findValue(5) << endl;

	vec.insertAtEnd(5);

	cout << "Found second value '5' at index " << vec.findValue(5, vec.findValue(5) + 1) << endl;

	for (int i{ 0 }; i < vec.getSize(); ++i)
		std::cout << vec[i] << ' ';
}