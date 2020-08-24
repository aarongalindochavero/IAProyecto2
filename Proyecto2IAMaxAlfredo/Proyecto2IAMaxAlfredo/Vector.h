#pragma once
#include <iostream>

template <class T>
class Vector {

private:
	int _size;
	int _capacity;
	T* arr;
public:
	Vector();
	Vector(int);
	~Vector() { delete[] arr; };
	T& operator[](int);
	void resize(int);
	void push_back(const T&);
	void pop_back();
	int size();
	int capacity();
	void print();
};

template<class T>
Vector<T>::Vector()
{
	arr = new T[2];
	_size = 0;
	_capacity = 2;
	for (int i = 0; i < _capacity; i++)
	{
		arr[i] = T();
	}
}

template<class T>
Vector<T>::Vector(int size)
{
	arr = new T[size];
	_size = 0;
	_capacity = size;
	for (int i = 0; i < _capacity; i++)
	{
		arr[i] = T();
	}
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
void Vector<T>::resize(int size)
{
	T* tmp = new T[size];
	for (int i = 0; i < _size; i++)
	{
		tmp[i] = arr[i];
	}
	for (int i = _size; i < _capacity; i++)
	{
		tmp[i] = T();
	}
	delete[] arr;
	arr = tmp;
	_capacity = size;
}

template<class T>
void Vector<T>::push_back(const T& value)
{
	if (_size + 1 > _capacity)
	{
		resize((_size < 128) ? _size * 2 : _size + 64);
	}

	arr[_size] = value;
	_size++;
}

template<class T>
void Vector<T>::pop_back()
{
	if (_size > 0)
	{
		arr[_size] = 0;
		_size--;
	}
}

template<class T>
int Vector<T>::size()
{
	return _size;
} 

template<class T>
int Vector<T>::capacity()
{
	return _capacity;
}

template<class T>
void Vector<T>::print()
{
	std::cout << "{ ";
	for (int i = 0; i < _size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "}" << std::endl;
}