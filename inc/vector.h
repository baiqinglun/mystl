#pragma once

#include <stdexcept>

#include "inc/vector_iterator.h"
#include "inc/vector_const_iterator.h"
#include "inc/vector_reverse_iterator.h"

namespace stl
{
	template<class T>
	class Vector
	{
		typedef VectorIterator<T> iterator;
		typedef VectorConstIterator<T> const_iterator;
		typedef VectorReverseIterator<T> reverse_iterator;

	public:
		Vector();
		~Vector();

		T& at(size_t);
		const T& at(size_t) const;

		T& front();
		const T& front() const;

		T& back();
		const T& back() const;

		T* data();
		const T* data() const;

		T& operator[] (size_t index);
		const T& operator[] (size_t index) const;

		void push_back(const T& value);
		void pop_back();

		void assign(size_t n, const T& value);
		void swap(Vector<T>& other);
		bool empty();
		const bool empty() const;
		size_t size();
		const size_t size() const;
		size_t capacity();
		const size_t capacity() const;

		void resize(int n);
		void resize(int n, const T& value);
		void reserve(int n);

		void print();
		const void print() const;

		iterator begin();
		iterator end();
		const_iterator cbegin();
		const_iterator cend();
		reverse_iterator rbegin();
		reverse_iterator rend();
	private:
		T* m_data;
		size_t m_size;
		size_t m_capacity;
	};

#include "vector.inl"
}