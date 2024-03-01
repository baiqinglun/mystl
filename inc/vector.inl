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
inline void stl::Vector<T>::resize(int n)
{
	resize(n, T());
}

template<class T>
inline void stl::Vector<T>::resize(int n, const T& value)
{
	if (n < m_size)
	{
		m_size = n;
		return;
	}
	if (n < m_capacity)
	{
		for (size_t i = m_size; i < n; ++i)
		{
			m_data[i] = value;
		}
		m_size = n;
		return;
	}
	while (n >= m_capacity)
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
	for (size_t i = 0; i < m_size; ++i)
	{
		data[i] = m_data[i];
	}
	for (size_t i = m_size; i < n; i++)
	{
		data[i] = value;
	}
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
	m_data = data;
	m_size = n;
}

template<class T>
inline void stl::Vector<T>::reserve(int n)
{
	if (n < m_capacity)
	{
		return;
	}
	while (n >= m_capacity)
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
	for (size_t i = 0; i < m_size; i++)
	{
		data[i] = m_data[i];
	}
	if (m_data != nullptr)
	{
		delete m_data;
		m_data = nullptr;
	}
	m_data = data;
}

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::insert(iterator pos, const T& value)
{
	return insert(pos, 1, value);
}

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::insert(iterator pos, size_t n, const T& value)
{
	size_t size = pos - begin();
	if (m_size + n <= m_capacity)
	{
		for (size_t i = m_size; i > size ; i--)
		{
			m_data[i + n - 1] = m_data[i - 1];
		}

		for (size_t i = 0; i < n; i++)
		{
			m_data[i + size] = value;
		}
		m_size += n;
		return iterator(m_data + size);
	}

	while (n + m_size > m_capacity)
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
	for (size_t i = 0; i < size; i++)
	{
		data[i] = m_data[i];
	}

	for (size_t i = size; i < size+n; i++)
	{
		data[i] = value;
	}

	for (size_t i = size+n; i < n+m_size; i++)
	{
		data[i] = m_data[i - n];
	}
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
	m_data = data;
	m_size += n;
	return iterator(m_data + size);
}

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::erase(iterator pos)
{
	if (pos == end())
	{
		throw std::out_of_range("out_of_range");
	}
	else if(end() - pos == 1)
	{
		m_size -= 1;
		return end();
	}
	else
	{
		size_t index = pos - begin();
		for (size_t i = 0; i < m_size - index - 1; i++)
		{
			m_data[index + i] = m_data[index + i + 1];
		}
		m_size -= 1;
		return iterator(m_data + index);
	}
}

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::erase(iterator first, iterator last)
{
	if (last == end())
	{
		size_t size = last - first;
		m_size -= size;
		return iterator(end()-1);
	}
	else
	{
		size_t size = last - first;
		size_t index = first - begin();
		size_t l = last - begin();
		if (is_basic_type())
		{
			std::memmove(m_data + index, m_data + l, (m_size - l) * sizeof(T));
		}
		else
		{
			for (size_t i = 0; i < m_size - index - size; i++)
			{
				m_data[index + i] = m_data[index + i + size];
			}
		}
		m_size -= size;
		return iterator(m_data + index);
	}
}

template<class T>
inline bool stl::Vector<T>::is_basic_type()
{
	if (std::is_pointer<T>::value)
	{// 如果是个指针
		return true;
	}
	return (typeid(T) == typeid(bool)) ||
		(typeid(T) == typeid(char)) ||
		(typeid(T) == typeid(unsigned char)) ||
		(typeid(T) == typeid(short)) ||
		(typeid(T) == typeid(unsigned short)) ||
		(typeid(T) == typeid(int)) ||
		(typeid(T) == typeid(unsigned int)) ||
		(typeid(T) == typeid(long)) ||
		(typeid(T) == typeid(unsigned long)) ||
		(typeid(T) == typeid(float)) ||
		(typeid(T) == typeid(double));
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

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::begin()
{
	return iterator(m_data);
	//return iterator(&m_data[0]);
}

template<class T>
inline typename stl::Vector<T>::iterator stl::Vector<T>::end()
{
	return iterator(m_data+m_size);
	//return iterator(&(m_data[m_size - 1]));
}

template<class T>
inline typename stl::Vector<T>::const_iterator stl::Vector<T>::cbegin()
{
	return const_iterator(m_data);
}

template<class T>
inline typename stl::Vector<T>::const_iterator stl::Vector<T>::cend()
{
	return const_iterator(m_data + m_size);
}

template<class T>
inline typename stl::Vector<T>::reverse_iterator stl::Vector<T>::rbegin()
{
	return reverse_iterator(m_data + m_size -1);
}

template<class T>
inline typename stl::Vector<T>::reverse_iterator stl::Vector<T>::rend()
{
	return reverse_iterator(m_data -1);
}
