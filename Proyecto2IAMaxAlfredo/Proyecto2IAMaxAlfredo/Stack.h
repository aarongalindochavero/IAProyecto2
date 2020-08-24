#pragma once
#include"Node.h"

template<class T>
class Stack
{
private:
	int _size = 0;
public:
	Node<T>* last;
	Stack():last(nullptr) {};
	Stack(T value) :last(new Node<T>(value, nullptr)) { _size++; };
	void push(T data);
	void pop();
	T top();
	void swap(T data);
	int size();
	void print();
};

/*
** Introduce un elemento al stack
** @param data elemento a introducir
*/
template<class T>
void Stack<T>::push(T data)
{
	if (last)
	{
		Node<T>* tmp = new Node<T>(data, last);
		last = tmp;
		_size++;
	}
	else
	{
		last = new Node<T>(data, nullptr);
		_size++;
	}
}
/*
** Saca el elemento de hasta arriba del stack
*/
template<class T>
void Stack<T>::pop()
{
	if (last)
	{
		Node<T>* tmp = last;
		last = tmp->next;
		_size--;
		delete tmp;
	}
	else
	{
		throw new std::out_of_range("Stack last is nullptr");
	}
}

/*
** Devuelve el elemento de hasta arriba del stack
*/
template<class T>
T Stack<T>::top()
{
	if (last)
		return last->value;
	else
		throw new std::out_of_range("Stack last is nullptr");
}

/*
** Intercambia el valor del nodo superior del stack
** @param data elemento que reemplará al superior
*/
template<class T>
void Stack<T>::swap(T data)
{
	if (last)
	{
		last->value = data;
	}
	else
	{
		throw new std::out_of_range("Stack last is nullptr");
	}
}

/*
** Devuelve el tamaño del stack
*/
template<class T>
int Stack<T>::size() 
{
	return _size;
}

/*
** Imprime todos los elementos del stack, haciendo pop en el progreso
*/
template<class T>
void Stack<T>::print()
{
	if (last)
	{
		std::cout << "{ ";
		while (last)
		{
			std::cout << top()<<" ";
			pop();
		}
		std::cout << "}"<< std::endl;
	}
	else
	{
		std::cout << "Stack is empty" << std::endl;
	}
}
