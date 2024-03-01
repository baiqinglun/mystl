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
		throw std::out_of_range("����Խ��");
	return m_data[index];
}

template<class T>
inline const T& stl::Vector<T>::at(size_t) const
{
	if (m_size < 0 || index > m_size)
		throw std::out_of_range("����Խ��");
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
	// �����ݣ�ֱ�Ӹ�ֵ
	if (m_size < m_capacity)
	{
		m_data[m_size] = value;
		m_size++;
		return;
	}

	// ���ݺ��ٸ�ֵ
	if (m_capacity == 0)
	{
		m_capacity = 1;
	}
	else
	{
		m_capacity *= 2;
	}

	// ����������
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

	// ���¸�ֵ
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
inline void stl::Vector<T>::print()
{
	std::cout << "������" << m_capacity << "����С��" << m_size << std::endl;
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << m_data[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
inline const void stl::Vector<T>::print() const
{
	std::cout << "������" << m_capacity << "����С��" << m_size << std::endl;
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
