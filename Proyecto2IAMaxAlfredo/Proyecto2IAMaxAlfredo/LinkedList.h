#pragma once
#include "Node.h"
#include <iostream>
template <class T>
class LinkedList
{
private:
	int _size = 0;
public:
    Node<T>* root;
    Node<T>* last;
	LinkedList() : root(nullptr),last(nullptr) {};
    LinkedList(Node<T> ruth) { push_back(ruth); };
    LinkedList(const T& data) : root(new Node<T>(data)),last(root) { _size++; };
	void push_back(const T& data);
	void push_back(Node<T>* node);
    void push_front(const T& data);
    void add(const T& data, int pos);
    void erase_at(int index);
    void erase(const T& data);
    void erase_back();
    void erase_front();
    Node<T>* get(const T& data);
    Node<T>* get_at(int index);
    void bubbleSort();
    void insertionSort();
    int size();
    bool contains(const T&);
    bool containsNode(Node<T>*);
    bool replace_at(int, const T&);
    void reverse_iterative();
    void reverse_recursive();
    void print();
private:
    void recursiveInversion(Node<T>* current, Node<T>* previous);
};

/*
** Introduce el @param data hasta el final de la lista
*/
template<class T>
void LinkedList<T>::push_back(const T& data)
{
	if (root)
	{
        Node<T>* tmp = root;
        last->next = new Node<T>(data);
        last = last->next;
        _size++;
	}
	else
	{
		root = new Node<T>(data);
        last = root;

        _size++;
	}
}

template<class T>
void LinkedList<T>::push_back(Node<T>* node)
{
    if (root)
    {
        last->next = node;
        Node<T>* tmp = last->next;
        _size++;
        while (tmp->next)
        {
            _size++;
            tmp = tmp->next;
        }
        last = tmp;
    }
    else
    {
        root = node;
        Node<T>* tmp = root;
        _size++;
        while (tmp->next)
        {
            _size++;
            tmp = tmp->next;
        }
        last = tmp;
    }
}

/*
** Introduce el @param data en la primera posición de la lista
*/
template <class T>
void LinkedList<T>::push_front(const T& data)
{
    if (root)
    {
        root = new Node<T>(data, root);
        _size++;
    }
    else
    {
        root = new Node<T>(data);
        last = root;
        _size++;
    }
}

/*
** Devuelve el tamaño de la lista
*/
template<class T>
int LinkedList<T>::size()
{
    return _size;
}

/*
** Devuelve si la lista contiene el elemento @param i
*/
template<class T>
bool LinkedList<T>::contains(const T& i)
{
    if (root)
    {
        Node<T>* tmp = root;
        while (tmp)
        {
            if (tmp->value == i) return true;
            tmp = tmp->next;
        }
        return false;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
        return false;
    }
}

/*
** Devuelve si la lista contiene el nodo @param node
*/
template<class T>
bool LinkedList<T>::containsNode(Node<T>* node)
{
    Node<T>* tmp = root;

    if (root)
    {
        while (tmp)
        {
            if (tmp == node)
                return true;
            tmp = tmp->next;
        }
        return false;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
    return false;
}

/*
** Remplaza el value del nodo en la posición @param index
** con el valor del @ param replace
*/
template<class T>
bool LinkedList<T>::replace_at(int index, const T& replace)
{
    if (root)
    {
        int count = 0;
        if (index <= size())
        {
            Node<T>* to_replace = get_at(index);
            to_replace->value = replace;
            return true;
        }
        return false;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
        return false;
    }

}

/*
** Añade el valor del @param data en la posición
** @param pos de la lista
*/
template<class T>
void LinkedList<T>::add(const T& data, int pos)
{
    int count = 0;
    if (root)
    {
        if (pos <= size())
        {
            Node<T>* tmp = root;
            if (pos == 0)
            {
                push_front(data);
            }
            else if (pos == _size)
            {
                push_back(data);
            }
            else if (pos > 0)
            {
                while (tmp)
                {
                    if (count == pos - 1)
                    {
                        tmp->next = new Node<T>(data, tmp->next);
                        _size++;
                    }
                    tmp = tmp->next;
                    count++;
                }
            }
        }
        else
        {
            throw new std::out_of_range("Out of LinkedList");
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }

}

/*
** Elimina de la lista el primer valor que se igual 
** a @param data.
*/
template<class T>
void LinkedList<T>::erase(const T& data)
{
    if (root)
    {
        Node<T>* tmp = root;
        int count = 0;
        while (tmp)
        {
            if (tmp->value == data)
            {
                erase_at(count);
                break;
            }
            tmp = tmp->next;
            count++;
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
}

/*
** Elimina el primer valor de la lista
*/
template<class T>
void LinkedList<T>::erase_front()
{
    erase_at(0);
}

/*
** Elimina el ultimo valor de la lista
*/
template<class T>
void LinkedList<T>::erase_back()
{
    erase_at(_size - 1);
}

/*
** Elimina el valor en la posción @param index
** de la lista.
*/
template<class T>
void LinkedList<T>::erase_at(int index)
{
    if (root)
    {
        if (index <= _size)
        {
            if (index == 0)
            {
                Node<T>* tmp = root;
                root = root->next;
                if (root == last)
                    last = root->next;
                _size--;
                delete tmp;
            }
            else
            {
                Node <T>* previous, * forward, * to_delete;

                to_delete = (index == _size)? last :get_at(index);
                if (index > 0)
                    previous = get_at(index - 1);
                else
                    previous = nullptr;

                if (index + 1 < _size)
                    forward = get_at(index + 1);
                else
                    forward = nullptr;

                if (previous)
                    previous->next = forward;
                if (to_delete == last)
                    last = previous;
                delete to_delete;
                _size--;
            }
        }
        else
        {
            throw new std::out_of_range("Out of LinkedList");
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }

}

/*
** Devuelve el NODO en la posición @param index
** de la lista.
*/
template<class T>
Node<T>* LinkedList<T>::get_at(int index)
{
    if (root)
    {
        Node<T>* tmp = root;
        if(index >= _size) throw new std::out_of_range("Out of LinkedList");
        if (index == 0)
            return root;
        for (unsigned int i = 0; i < index; i++)
                tmp = tmp->next;
        return tmp;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
    return nullptr;
}

template<class T>
void LinkedList<T>::bubbleSort()
{
    if (root)
    {
        for (unsigned int i = 0; i < _size; i++)
        {
            for (unsigned int j = 0; j < _size - 1; j++)
            {
                Node<T>* first = get_at(j);
                if (first->value > first->next->value)
                {
                    T tmp = first->value;
                    first->value = first->next->value;
                    first->next->value = tmp;
                }
            }
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }

}

template<class T>
void LinkedList<T>::insertionSort()
{
    if (root)
    {
        T key;
        for (unsigned int i = 1; i < _size; i++)
        {
            key = get_at(i)->value;
            for (int j = i - 1; j >= 0; j--)
            {
                Node<T>* tmp = get_at(j);
                if (tmp->value > key)
                {
                    tmp->next->value = tmp->value;
                    tmp->value = key;
                }
            }
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }

}

/*
** Devuelve el primer NODO cuyo valor se igual a @param data
** de la lista.
*/
template<class T>
Node<T>* LinkedList<T>::get(const T& data)
{
    Node<T>* tmp = root;

    if (root)
    {
        while (tmp)
        {
            if (tmp->value == data)
                return tmp;
            tmp = tmp->next;
        }
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
    return nullptr;
}

/*
** Cambia el sentido de la lista
*/
template<class T>
void LinkedList<T>::reverse_iterative()
{
    if (root)
    {
        Node<T>* current = root, * prev = nullptr, * next;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        root = prev;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
}

template<class T>
void LinkedList<T>::reverse_recursive()
{
    recursiveInversion(root, nullptr);
    Node<T>* tmp = root;
    root = last;
    last = tmp;
}

template<class T>
void LinkedList<T>::recursiveInversion(Node<T>* current, Node<T>* previous)
{
    if (!current) return;
    recursiveInversion(current->next, current);
    current->next = previous;
}

/*
** Imprime todos lo valores de la lista
*/
template<class T>
void LinkedList<T>::print() {
    if (root)
    {
        Node<T>* tmp = root;
        std::cout << "{ ";
        while (tmp) {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << "}" << std::endl;
    }
    else
    {
        throw new std::out_of_range("LinkedList is null");//Null list exeption
    }
}
