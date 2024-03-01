#pragma once

namespace stl{
    template<class T>
    class VectorReverseIterator
    {
        typedef VectorReverseIterator<T> iterator;
    public:
        VectorReverseIterator() :m_pointer(nullptr) {};
        VectorReverseIterator(T* pointer) :m_pointer(pointer) {};
        ~VectorReverseIterator() {};

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
            if (&other != nullptr)
            {
                m_pointer = other.m_pointer;
            }
            return *this;
        }

        // 前缀++
        iterator& operator ++ ()
        {
            m_pointer -= 1;
            return *this;
        }

        // 后缀++（后缀++是在前缀++基础上实现的）
        iterator& operator ++ (int)
        {
            auto it = *this; // 用到了复制运算符
            --(*this);
            return it;
        }

        // 后缀+n，本身没变
        iterator& operator + (int n)
        {
            auto it = *this;
            it.m_pointer -= n;
            return it;
        }

        iterator& operator += (int n)
        {
            m_pointer -= n;
            return *this;
        }


        // 前缀--
        iterator& operator -- ()
        {
            m_pointer += 1;
            return *this;
        }

        // 后缀--（后缀--是在前缀--基础上实现的）
        iterator& operator -- (int)
        {
            auto it = *this; // 用到了复制运算符
            ++(*this);
            return it;
        }

        // 后缀-n，本身没变
        iterator& operator - (int n)
        {
            auto it = *this;
            it.m_pointer += n;
            return it;
        }

        iterator& operator -= (int n)
        {
            m_pointer += n;
            return *this;
        }

        T& operator* ()
        {
            return *m_pointer;
        }

        T* operator -> ()
        {
            return m_pointer;
        }
    public:
        T* m_pointer;
    };

}