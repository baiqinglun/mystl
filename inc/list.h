#pragma once

#include <iostream>
#include <stdexcept>
#include "inc/list_node.h"
#include "inc/list_iterator.h"
#include "inc/list_const_iterator.h"
#include "inc/list_reverse_iterator.h"

namespace stl{
    template<typename T>
    class List
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T> iterator;
        typedef ListConstIterator<T> const_iterator;
        typedef ListReverseIterator<T> reverse_iterator;

    public:
        List();
        ~List();

        int size() const;
        bool empty() const;

        T& front();
        const T& front() const;

        T& back();
        const T& back() const;

        void show() const;
        void clear();
        void assign(int count, const T& value);
        void remove(const T& value);
        void resize(int size);
        void merge(List<T>& other);
        void swap(List<T>& other);
        void reverse();

        void push_front(const T& value);
        void pop_front();
        void push_back(const T& value);
        void pop_back();

        iterator begin();
        iterator end();
        iterator find(const T& value);

        iterator insert(iterator pos, T value);
        iterator insert(iterator pos,int n,T value);
        iterator erase(iterator pos);
        iterator erase(iterator first,iterator last);

        const_iterator cbegin();
        const_iterator cend();
        const_iterator find(const T& value) const;

        reverse_iterator rbegin();
        reverse_iterator rend();

    private:
        Node *m_head;
        Node *m_tail;
        int m_size;
    };

    #include "list.inl"
}
