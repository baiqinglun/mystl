#include<iostream>
#include "inc/vector.h"

using namespace std; using namespace stl;

int main()
{
	Vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	// ��������
	//Vector<size_t> v2;
	//for (size_t i = 10; i < 20; i++)
	//{
	//	v2.push_back(i);
	//}
	//v1.swap(v2);
	//v1.print();
	//v2.print();
	
	// ����
	//v1.reserve(20);
	//v1.resize(16,4);
	//v1.print();

	// ������
	//for (auto it = v1.begin(); it != v1.end(); ++it)
	//{
	//	std::cout << *it << " ";
	//}

	//auto it = v1.begin();
	//auto it2 = it - 3;
	//std::cout << *it2 << std::endl;

	// ����������
	//for (auto it = v1.cbegin(); it != v1.cend(); ++it)
	//{
	//	std::cout << *it << " ";
	//}

	// ���������
	//for (auto it = v1.rbegin(); it != v1.rend(); ++it)
	//{
	//	std::cout << *it << " ";
	//}
	return 0;
}