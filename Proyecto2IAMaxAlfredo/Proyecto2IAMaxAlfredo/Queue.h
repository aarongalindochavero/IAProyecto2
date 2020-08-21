#pragma once
#pragma once
#include <iostream>
#include "Node.h"
using std::cout; using std::endl;
template<class T>
class Queue {
private:
	int size = 0;
public:
	Node<T>* root = nullptr;
	Queue() {};
	Queue(T data) {
		if (!root) {
			root = new Node<T>(data);
			size = 1;
		}
	}
	~Queue() {};
	/**
	* Coloca un elemento al inicio de queue
	* @param data es el elemento que que se colocara al  inicio del queue
	*/
	void push(T data) {
		if (root) {
			Node<T>* tmp = root;
			while (tmp) {
				if (!tmp->next) {
					tmp->next = new Node<T>(data);
					size++;
					break;
				}
				tmp = tmp->next;
			}
		}
		else {
			root = new Node<T>(data);
			size++;
		}
	}
	/**
	* Elimina el elememto que esta el principio del queue
	*/
	void pop() {
		if (root && size > 0) {
			root = root->next;
			size--;
		}
	}
	/**
	* Regresa el emenento del queue que esta al inicio del queue
	*/
	int front() {
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
	* Regresa el emenento del queue que esta al final del queue
	*/
	int back() {
		if (root) {
			Node<T>* tmp = root;
			int pocicion = 0;
			while (tmp) {
				if (pocicion == size - 1) {
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
	* Regresa el tamaño del queue
	*/
	int Size() {
		return size;
	}
	/*
	* Imprime todo el queue
	*/
	void Print() {
		while (root) {
			cout << root->dato << ", ";
			pop();
			if (size == 0) {
				break;
			}
		}
	}
};