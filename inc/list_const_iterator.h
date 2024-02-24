#pragma once

#include "inc/list_node.h"

namespace stl{
    template<class T>
    class ListConstIterator
    {
        typedef ListNode<T> Node;
        typedef ListConstIterator<T> iterator;
    public:
        ListConstIterator() :m_pointer(nullptr) {};
        ListConstIterator(Node* pointer) :m_pointer(pointer) {};
        ~ListConstIterator() {};

        bool operator == (const iterator& other)
        {
            return m_pointer == other.m_pointer;
        }

        bool operator != (const iterator& other)
        {
            return m_pointer != other.m_pointer;
        }

        iterator& operator = (const iterator& other)
        {
            if (this == other)
                return;
            m_pointer = other.m_pointer;
            return *this;
        }

        // 前缀++
        iterator& operator ++ ()
        {
            m_pointer = m_pointer->m_next;
            return *this;
        }

        // 后缀++（后缀++是在前缀++基础上实现的）
        iterator& operator ++ (int)
        {
            auto it = *this; // 用到了复制运算符
            ++(*this);
            return it;
        }

        // 后缀+n，本身没变
        iterator& operator + (int n)
        {
            auto it = *this;
            for (int i = 0; i < n; ++i)
            {
                ++it;
            }
            return it;
        }

        iterator& operator += (int n)
        {
            for (int i = 0; i < n; ++i)
            {
                ++(*this);
            }
            return *this;
        }


        // 前缀--
        iterator& operator -- ()
        {
            m_pointer = m_pointer->m_prev;
            return *this;
        }

        // 后缀--（后缀--是在前缀--基础上实现的）
        iterator& operator -- (int)
        {
            auto it = *this; // 用到了复制运算符
            --(*this);
            return it;
        }

        // 后缀-n，本身没变
        iterator& operator - (int n)
        {
            auto it = *this;
            for (int i = 0; i < n; ++i)
            {
                --it;
            }
            return it;
        }

        iterator& operator -= (int n)
        {
            for (int i = 0; i < n; ++i)
            {
                --(*this);
            }
            return *this;
        }

        const T& operator* () const
        {
            return m_pointer->m_value;
        }

        const T* operator -> () const
        {
            return &(m_pointer->m_value);
        }
    public:
        Node* m_pointer;
    };

}