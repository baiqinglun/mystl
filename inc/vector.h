#pragma once

#include <stdexcept>

namespace stl
{
	template<class T>
	class Vector
	{
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

		void print();
		const void print() const;
	private:
		T* m_data;
		size_t m_size;
		size_t m_capacity;
	};

#include "vector.inl"
}