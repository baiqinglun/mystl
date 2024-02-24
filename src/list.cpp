#include <iostream>
#include "inc/list.h"

using namespace stl;

int main()
{
    List<int> list;
    List<int> list2;
    for(int i = 10; i > 0; --i)
    {
        list.push_front(i);
        list2.push_front(i * 2);
    }
    list2.push_back(5);
    list.show();
    list.reverse();
    list.show();
    //auto it1 = list.begin() + 2;
    //auto it2 = list.begin() + 5;
    //list.erase(it1,it2);
    //list.show();
    
    //auto it = list.find(10);
    //std::cout << *(it) << std::endl;
    //list.resize(10);
    //list.show();
    //std::cout << std::endl;
    //list2.show();
    //list.merge(list2);
    //std::cout << std::endl;
    //list.show();
    //std::cout << std::endl;
    //list2.show();
    //list.swap(list2);
    //list.show();
    
    //for (auto it = list.begin(); it != list.end(); ++it)
    //{
    //    std::cout << *it << std::endl;
    //}

    //for (auto it = list.cbegin(); it != list.cend(); ++it)
    //{
    //    std::cout << *it << std::endl;
    //}

    //for (auto it = list.rbegin(); it != list.rend(); ++it)
    //{
    //    std::cout << *it << std::endl;
    //}
    //std::cout << std::endl;
    return 0;
}