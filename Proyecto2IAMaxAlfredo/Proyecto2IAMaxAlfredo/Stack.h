#pragma once
#pragma once
#include <iostream>
#include "Node.h"
using std::cout; using std::endl;
template<class T>
class Stack {
private:
	int size = 0;
public:
	Node<T>* root = nullptr;
	Stack() {};
	Stack(T data) {
		if (!root) {
			root = new Node<T>(data);
			size = 1;
		}
	}
	~Stack() {};
	/*
	**Coloca un elemento al inicio del stack;
	*/
	void Push(T data) {
		if (root) {
			Node<T>* tmp = root;
			root = new Node<T>(data);
			root->next = tmp;
			size++;
		}
		else {
			root = new Node<T>(data);
			size++;
		}
	}
	/*
	**Elimina el elememto que esta el principio del stack
	*/
	void pop() {
		if (root && size > 0) {
			root = root->next;
			size--;
		}
	}
	/*
	**Regresa el elemento que esta al inicio del stack
	*/
	T Top() {
		if (root) {
			Node<T>* tmp = root;
			int pocicion = 0;
			while (tmp) {
				if (pocicion == 0) {
					return tmp->dato;
					break;
				}
				pocicion++;
				tmp = tmp->next;
			}
		}
		return 0;
	}
	/*
	**Imprime el stack
	*/
	void Print() {
		while (root) {
			cout << root->dato << ", ";
			pop();
			if (size == 0) {
				break;
			}
		}
		cout << endl;
	}
	/*
	**Regresa el tamaño del stack
	*/
	int Size() {
		return size;
	}
};