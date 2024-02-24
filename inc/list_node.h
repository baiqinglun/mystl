#pragma once

namespace stl
{
    template <class T>
    class ListNode
    {
        typedef ListNode<T> Node;

    public:
        ListNode() = delete;
        ~ListNode() = default;
        ListNode(const T& val):m_value(val),m_prev(nullptr),m_next(nullptr) {};

    public:
        T m_value;
        Node *m_prev;
        Node *m_next;
    };
};
