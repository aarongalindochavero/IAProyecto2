#pragma once
#include"Node.h"

template<class T>
class Queue
{
private:
	int _size = 0;
public:
	Node<T>* first;
	Queue():first(nullptr) {};
	Queue(T value):first(new Node<T>(first, nullptr)) { _size++; };
	void push(T data);
	void pop();
	T front();
	T back();
	void swap(T data);
	int size();
	void print();
};
/*
** Introduce un elemento hasta el fondo del queue
** @param data el elemento a introducir
*/
template<class T>
void Queue<T>::push(T data)
{
	if (first)
	{
		Node<T>* tmp = first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(data, nullptr);
		_size++;
	}
	else
	{
		first = new Node<T>(data, nullptr);
		_size++;
	}
}

/*
** Retira el elemento frontal del queue
*/
template<class T>
void Queue<T>::pop()
{
	if (first)
	{
		Node<T>* tmp = first;
		first = tmp->next;
		_size--;
		delete tmp;
	}
	else
	{
		throw new std::out_of_range("Queue is empty");
	}
}

/*
** Devuelve el elemento frontal del queue
*/
template<class T>
T Queue<T>::front()
{
	if (first)
		return first->value;
	else
		throw new std::out_of_range("Queue is empty");
}

/*
** Devuelve el último elemento del queue
*/
template<class T>
T Queue<T>::back()
{
	if (first)
	{
		Node<T>* tmp = first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return tmp->value;
	}
	else
		throw new std::out_of_range("Queue is empty");
}

/*
** Intercambia el ultimo elemento del queue por uno nuevo
** @param data que remplazará
*/
template<class T>
void Queue<T>::swap(T data)
{
	if (first)
	{
		Node<T>* tmp = first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->value = data;
	}
	else
	{
		throw new std::out_of_range("Queue is empty");
	}
}

/*
** Devuelve el tamaño del queue
*/
template<class T>
int Queue<T>::size()
{
	return _size;
}

/*
** Imprime todos los elementos del queue, haciendo pop en el progreso
*/
template<class T>
void Queue<T>::print()
{
	if (first)
	{
		std::cout << "{ ";
		while (first)
		{
			std::cout << front() << " ";
			pop();
		}
		std::cout << "}" << std::endl;
	}
	else
	{
		std::cout << "Queue is empty" << std::endl;
	}
}