#include "inc/vector.h"

template<class T>
Vector<T>::Vector():m_data(nullptr),m_size(0),m_capacity(0)
{
}

template<class T>
Vector<T>::~Vector()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
	}
	m_capacity = 0;
	m_size = 0;
}

template<class T>
inline T& stl::Vector<T>::at(size_t index)
{
	if (m_size < 0 || index > m_size)
		throw std::out_of_range("数组越界");
	return m_data[index];
}

template<class T>
inline const T& stl::Vector<T>::at(size_t) const
{
	if (m_size < 0 || index > m_size)
		throw std::out_of_range("数组越界");
	return m_data[index];
}

template<class T>
inline T& stl::Vector<T>::front()
{
	return m_data[0];
}

template<class T>
inline const T& stl::Vector<T>::front() const
{
	return m_data[0];
}

template<class T>
inline T& stl::Vector<T>::back()
{
	return m_data[m_size-1];
}

template<class T>
inline const T& stl::Vector<T>::back() const
{
	return m_data[m_size - 1];
}

template<class T>
inline T* stl::Vector<T>::data()
{
	return m_data;
}

template<class T>
inline const T* stl::Vector<T>::data() const
{
	return m_data;
}

template<class T>
inline T& stl::Vector<T>::operator[](size_t index)
{
	return m_data[index];
}

template<class T>
inline const T& stl::Vector<T>::operator[](size_t index) const
{
	return m_data[index];
}

template<class T>
inline void stl::Vector<T>::push_back(const T& value)
{
	// 不扩容，直接赋值
	if (m_size < m_capacity)
	{
		m_data[m_size] = value;
		m_size++;
		return;
	}

	// 扩容后，再赋值
	if (m_capacity == 0)
	{
		m_capacity = 1;
	}
	else
	{
		m_capacity *= 2;
	}

	// 创建新数组
	T* data = new T[m_capacity];
	for (size_t i = 0; i < m_size; ++i)
	{
		data[i] = m_data[i];
	}

	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}

	// 重新赋值
	m_data = data;
	m_data[m_size] = value;
	m_size++;
}

template<class T>
inline void stl::Vector<T>::pop_back()
{
	if (m_size > 0)
	{
		m_size--;
	}
}

template<class T>
inline void stl::Vector<T>::assign(size_t n,const T& value)
{
	if (n < m_capacity)
	{
		for (size_t i = 0; i < n; i++)
		{
			m_data[i] = value;
			m_size = n;
		}
		return;
	}

	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	}

	while (m_capacity < n)
	{
		if (m_capacity == 0)
		{
			m_capacity = 1;
		}
		else
		{
			m_capacity *= 2;
		}
	}

	T* data = new T[m_capacity];
	for (size_t i = 0; i < n; i++)
	{
		data[i] = value;
	}
	m_data = data;
	m_size = n;
}

template<class T>
inline void stl::Vector<T>::swap(Vector<T>& other)
{
	if (&other != nullptr && this != &other)
	{
		T* data = m_data;
		m_data = other.m_data;
		other.m_data = data;

		size_t size = m_size;
		m_size = other.m_size;
		other.m_size = size;

		size_t capacity = m_capacity;
		m_capacity = other.m_capacity;
		other.m_capacity = capacity;
	}
}

template<class T>
inline bool stl::Vector<T>::empty()
{
	return m_size == 0;
}

template<class T>
inline const bool stl::Vector<T>::empty() const
{
	return m_size == 0;
}

template<class T>
inline size_t stl::Vector<T>::size()
{
	return m_size;
}

template<class T>
inline const size_t stl::Vector<T>::size() const
{
	return m_size;
}

template<class T>
inline size_t stl::Vector<T>::capacity()
{
	return m_capacity;
}

template<class T>
inline const size_t stl::Vector<T>::capacity() const
{
	return m_capacity;
}

template<class T>
inline void stl::Vector<T>::print()
{
	std::cout << "容量：" << m_capacity << "，大小：" << m_size << std::endl;
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
inline const void stl::Vector<T>::print() const
{
	std::cout << "容量：" << m_capacity << "，大小：" << m_size << std::endl;
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << std::endl;
}
