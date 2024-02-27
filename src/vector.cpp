#include<iostream>
#include "inc/vector.h"

using namespace std; using namespace stl;

int main()
{
	Vector<size_t> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	Vector<size_t> v2;
	for (size_t i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}
	v1.swap(v2);
	v1.print();
	v2.print();
	return 0;
}