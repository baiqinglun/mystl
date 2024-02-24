#include "list.h"

template<typename T>
List<T>::List() : m_size(0),m_tail(nullptr),m_head(nullptr){};

template<typename T>
List<T>::~List(){clear();}


template<typename T>
int List<T>::size() const
{
    return m_size;
}


template<typename T>
bool List<T>::empty() const
{
    return m_size == 0;
}

template<typename T>
T& List<T>::front()
{
    if (m_size == 0)
    {
        throw std::out_of_range("the list is empty");
    }
    return m_head->m_value;
}

template<typename T>
const T& List<T>::front() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("the list is empty");
    }
    return m_head->m_value;
}

template<typename T>
T& List<T>::back()
{
    if (m_size == 0)
    {
        throw std::out_of_range("the list is empty");
    }
    return m_tail->m_value;    
}

template<typename T>
const T& List<T>::back() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("the list is empty");
    }
    return m_tail->m_value;    
}

template<typename T>
void List<T>::show() const
{
    std::cout << "总元素个数：" << m_size << std::endl;
    auto node = m_head;
    while(node != nullptr)
    {
        std::cout << node->m_value << "\t";
        node = node->m_next;
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::clear()
{

}

// 向前新增
template<typename T>
void List<T>::push_front(const T& value)
{
    auto node = new Node(value);
    if(!node)
    {
        return;
    }

    if(m_size == 0)
    {
        m_head = m_tail = node;
        m_size++;
        return;
    }

    m_head->m_prev = node;
    node->m_next = m_head;
    m_head = node;
    m_size++;
}

// 删除头元素
template<typename T>
void List<T>::pop_front()
{
    if(m_size == 0)
        return;
    if(m_size == 1)
    {
        delete m_head;
        m_head = m_tail = nullptr;
        m_size--;
        return;
    }
    auto temp = m_head->m_next;
    temp->m_prev = nullptr;
    delete m_head;
    m_head = temp;
    m_size--;
}

template<typename T>
void List<T>::push_back(const T& value)
{
    auto node = new Node(value);
    if(!node)
        return;
    if(m_size == 0)
    {
        m_head = m_tail = nullptr;
        m_size++;
        return;
    }
    
    m_tail->m_next = node;
    node->m_prev = m_tail;
    m_tail = node;
    m_size++;
}

template<typename T>
void List<T>::pop_back()
{
    if(m_size == 0)
    {
        return;
    }
    if(m_size == 1)
    {
        delete m_tail;
        m_head = m_tail = nullptr;
    }

    auto temp = m_tail->m_prev;
    delete m_tail;
    temp->m_next = nullptr;
    m_tail = temp;
    m_size--;
}

template<typename T>
// typename表示iterator是一个类型而不是一个静态成员或常量成员
typename List<T>::iterator List<T>::begin()
{
    return iterator(m_head);
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
    if (m_size == 0)
        return iterator();
    else
        return iterator(m_tail->m_next);
}

template<typename T>
typename List<T>::iterator List<T>::find(const T& value)
{
    auto node = m_head;
    while (node != nullptr)
    {
        if (node->m_value == value)
            break;
        node = node->m_next;
    }
    return iterator(node);
}

template<typename T>
inline void stl::List<T>::assign(int count, const T& value)
{
    clear();
    for (int i = 0; i < count; ++i)
    {
        push_back(value);
    }
}

template<typename T>
inline void stl::List<T>::remove(const T& value)
{
    if (m_size == 0)
        return;
    while (m_head != nullptr && m_head->m_value == value)
    {
        auto node = m_head->m_next;
        node->m_prev = nullptr;
        delete m_head;
        m_head = node;
        m_size--;
    }
    auto node = m_head;
    while (node !=nullptr && node->m_next)
    {
        if (node->m_next->m_value == value)
        {
            auto temp = node->m_next;
            node->m_next = temp->m_next;
            temp->m_next->m_prev = node;
            delete temp;
            m_size--;
        }
        node = node->m_next;
    }
}

template<typename T>
inline void stl::List<T>::resize(int size)
{
    int size_ = m_size;
    if (size == size_)
        return;
    if (size > size_)
    {
        for (int i = 0; i < size - size_; ++i)
        {
            push_back(T());
        }
    }
    else
    {
        for (int i = 0; i < size_ - size; ++i)
        {
            pop_back();
        }
    }
}

template<typename T>
inline void stl::List<T>::merge(List<T>& other)
{
    m_tail->m_next = other.m_head;
    other.m_head->m_prev = m_tail;
    m_tail = other.m_tail;
    m_size += other.m_size;

    other.m_head = other.m_tail = nullptr;
    other.m_size = 0;
}

template<typename T>
inline void stl::List<T>::swap(List<T>& other)
{
    if (this == &other)
        return;

    auto head = other.m_head;
    auto tail = other.m_tail;
    int size = other.m_size;

    other.m_head = m_head;
    other.m_tail = m_tail;
    other.m_size = m_size;

    m_head = head;
    m_tail = tail;
    m_size = size;
}

template<typename T>
inline void stl::List<T>::reverse()
{
    if (m_size == 0 || m_size == 1)
        return;
    auto head = m_head;
    auto tail = m_tail;
    auto node = m_tail;

    while (node != nullptr)
    {
        auto prev = node->m_prev;
        auto next = node->m_next;

        node->m_prev = next;
        node->m_next = prev;
        node = prev;
    }

    m_head = tail;
    m_tail = head;
}

template<typename T>
typename List<T>::const_iterator List<T>::cbegin()
{
    return const_iterator(m_head);
}

template<typename T>
typename List<T>::const_iterator List<T>::cend()
{
    if (m_size == 0)
        return const_iterator();
    else
        return const_iterator(m_tail->m_next);
}

template<typename T>
typename List<T>::const_iterator List<T>::find(const T& value) const
{
    auto node = m_head;
    while (node != nullptr)
    {
        if (node->m_value == value)
            break;
        node = node->m_next;
    }
    return const_iterator(node);
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rbegin()
{
    return reverse_iterator(m_tail);
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rend()
{
    if (m_size == 0)
        return reverse_iterator();
    else
        return reverse_iterator(m_head->m_prev);
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator pos, T value)
{
    return List<T>::insert(pos, 1, value);
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator pos, int n, T value)
{
    if (pos == begin())
    {
        for (int i = 0; i < n; ++i)
        {
            push_front(value);
        }
        m_size += n;
        return begin();
    }
    else if(pos == end())
    {
        auto temp = m_tail;
        for (int i = 0; i < n; ++i)
        {
            push_back(value);
        }
        m_size += n;
        return iterator(temp->m_next);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            auto node = new Node(value);
            auto prev = pos.m_pointer->m_prev;
            node->m_prev = prev;
            prev->m_next = node;
            node->m_next = pos.m_pointer;
            pos.m_pointer->m_prev = node;
            pos.m_pointer = node;
        }
        m_size += n;
        return pos;
    }
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator pos)
{
    if (pos == begin())
    {
        auto node = m_head;
        if (m_size > 1)
        {
            m_head = m_head->m_next;
            m_head->m_prev = nullptr;
            delete node;
        }
        else
        {
            delete m_head;
            m_head = m_tail = nullptr;
        }
        m_size--;
        return begin();
    }
    else if (pos == end())
    {
        return pos;
    }
    else
    {
        auto node = pos.m_pointer;
        if (node->m_prev != nullptr)
            node->m_prev->m_next = node->m_next;
        if (node->m_next != nullptr)
            node->m_next->m_prev = node->m_prev;

        auto next = node->m_next;
        delete node;
        m_size--;
        return iterator(next);
    }
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator first, iterator last)
{
    for (auto it = first; it != last;)
    {
        it = erase(it);
    }
    return last;
}
