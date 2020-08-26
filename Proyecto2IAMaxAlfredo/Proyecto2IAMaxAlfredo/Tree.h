#pragma once
#include "MultiNode.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Vector.h"
#include <iostream>

template<class T>
class Tree
{
private:
	typedef MultiNode<T> NODE;
public:
	NODE* root;
	NODE* last;
	MultiNode<T>* searchDFSIterative(T data);
	Tree() : root(nullptr), last(nullptr) {}
	Tree(const T& data) : root(new NODE(data)), last(nullptr) {}
	Tree(NODE* node) : root(node) {}
	NODE* searchDFS(T);
	bool insert(T parent, T data);
	void erase(T data);
	NODE* searchBFS(const T&, NODE*);
	void printBFS(NODE* start);
	void printDFS();
	NODE* BiderectionalSearch(NODE* start, NODE* end); // Alfredo
	MultiNode<T>* lookforDPSIterative(T data, NODE* node);
private:
	NODE* lookForDPS(T,NODE*);
	void printFromNode(NODE*);
};

template<class T>
MultiNode<T>* Tree<T>::searchDFSIterative(T data)
{
	return lookforDPSIterative(data, root);
}

template<class T>
MultiNode<T>* Tree<T>::searchDFS(T data)
{
	return lookForDPS(data, root);
}

template<class T>
bool Tree<T>::insert(T parent, T data)
{
	NODE* tmp = searchDFS(parent);
	if (tmp)
	{
		if (searchDFS(data))
			return false;
		NODE* newNode = new NODE(data);
		tmp->vertex.push_back(newNode);
		newNode->parent = tmp;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void Tree<T>::erase(T data)
{
	NODE* to_erase = searchDFS(data);

	if (to_erase)
	{
		delete to_erase;
	}
}

template<class T>
void Tree<T>::printDFS()
{
	printFromNode(root);
}

template<class T>
void Tree<T>::printFromNode(NODE* node)
{
	if (node)
	{
		std::cout << node->value << "<-[ ";
		for (int i = 0; i < node->vertex.size(); i++)
		{
			std::cout << node->vertex[i]->value << " ";
		}
		std::cout << "]" << std::endl;

		for (int i = 0; i < node->vertex.size(); i++)
		{
			printFromNode(node->vertex[i]);
		}
	}
}

template<class T>
MultiNode<T>* Tree<T>::BiderectionalSearch(NODE* start, NODE* end) {
	if (start && end && lookForDPS(end->value, start)) {
		Vector<NODE*> pathToEnd; // Alfredo

		NODE* tmp;
		tmp = end;

		if (pathToEnd.size() <= 0) {
			while (tmp->value != start->value) {
				pathToEnd.push_back(tmp);
				tmp = tmp->parent;
			}
		}
		if (lookForDPS(pathToEnd[pathToEnd.size() - 1]->value, start)) {
			tmp = pathToEnd[pathToEnd.size() - 1];
			std::cout << "Path to follow" << std::endl;
			for (int i = 0; i < pathToEnd.size(); i++) {

				std::cout << pathToEnd[pathToEnd.size()-i-1]->value << std::endl;
			}
			return tmp;
		}

		return nullptr;
	}
	return nullptr;
}

template<class T>
MultiNode<T>* Tree<T>::lookforDPSIterative(T data, NODE* node)
{
	if (!node) return nullptr;


	//Aqui se puede añadir a un stack
	LinkedList<NODE*> visited;
	Stack<NODE*> stack;
	NODE* current = node;
	stack.push(node);
	while (stack.size() > 0)
	{
		current = stack.top();
		stack.pop();

		if (!visited.contains(current))
		{
			std::cout << current->value << " ";
			visited.push_back(current);

		}

		if (current->value == data)
		{
			return current;
		}

		for (int i = current->vertex.size() - 1; i >= 0; i--)
		{
			if (!visited.contains(current->vertex[i]))
			{
				stack.push(current->vertex[i]);
			}
		}
	}

	return nullptr;
}

template<class T>
MultiNode<T>* Tree<T>::searchBFS(const T& data, NODE* start)
{
	LinkedList<NODE*> visited;
	Queue<NODE*> queue;

	visited.push_back(start);
	queue.push(start);

	while (queue.size() > 0)
	{
		start = queue.front();
		if (start->value == data) return start;
		queue.pop();

		for (int i = 0; i < start->vertex.size(); i++)
		{
			NODE* tmp = start->vertex[i];
			if (!visited.contains(tmp))
			{
				visited.push_back(tmp);
				queue.push(tmp);
			}
		}
	}

	return nullptr;
}

template<class T>
MultiNode<T>* Tree<T>::lookForDPS(T data, NODE* node)
{
	if (!node) return nullptr;

	if (node->value == data)
	{
		last = node;
		return node;
	}

	//Aqui se puede añadir a un stack

	for (int i = 0; i < node->vertex.size(); i++)
	{
		if (node->vertex[i])
			lookForDPS(data, node->vertex[i]);
		if (last->value == data)
			return last;
	}

	//Aqui se borraría del stack

	return nullptr;
}

template<class T>
void Tree<T>::printBFS(NODE* start)
{
	LinkedList<NODE*> visited;
	Queue<NODE*> queue;

	visited.push_back(start);
	queue.push(start);

	while (queue.size() > 0)
	{
		start = queue.front();
		std::cout << start->value << " ";
		queue.pop();

		for (int i = 0; i < start->vertex.size(); i++)
		{
			NODE* tmp = start->vertex[i];
			if (!visited.contains(tmp))
			{
				visited.push_back(tmp);
				queue.push(tmp);
			}
		}
	}
}

