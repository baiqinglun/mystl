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

	// 删除
	//v1.erase(v1.begin()+5);
	//auto begin = v1.begin() + 1;
	//auto last = v1.begin() + 4;
	//v1.erase(begin, last);
	v1.erase(v1.begin() + 1, v1.begin() + 4);
	//v1.erase(v1.begin()+4, v1.end());
	v1.print();

	// 插入
	//auto it = v1.insert(v1.begin()+3,10,2);
	//v1.print();

	// 交换函数
	//Vector<size_t> v2;
	//for (size_t i = 10; i < 20; i++)
	//{
	//	v2.push_back(i);
	//}
	//v1.swap(v2);
	//v1.print();
	//v2.print();
	
	// 扩容
	//v1.reserve(20);
	//v1.resize(16,4);
	//v1.print();

	// 迭代器
	//for (auto it = v1.begin(); it != v1.end(); ++it)
	//{
	//	std::cout << *it << " ";
	//}

	//auto it = v1.begin();
	//auto it2 = it - 3;
	//std::cout << *it2 << std::endl;

	// 常量迭代器
	//for (auto it = v1.cbegin(); it != v1.cend(); ++it)
	//{
	//	std::cout << *it << " ";
	//}

	// 反向迭代器
	//for (auto it = v1.rbegin(); it != v1.rend(); ++it)
	//{
	//	std::cout << *it << " ";
	//}
	return 0;
}