#pragma once
#include "MultiNode.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

template<class T>
class Tree
{
private:
	typedef MultiNode<T> NODE;
public:
	NODE* root;
	NODE* last;

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
private:
	NODE* lookForDPS(T,NODE*);
	void printFromNode(NODE*);
};

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
	LinkedList<NODE*> pathToEnd; // Alfredo
	
	NODE* tmp;
	tmp = end;

	if (pathToEnd.size() <= 0) {
		while (tmp->value != start->value || tmp->parent != nullptr){
			pathToEnd.push_back(tmp->parent);
			tmp = tmp->parent;
		}
	}

	for (int i = 0; i < pathToEnd->size(); i++) {
		if (lookForDPS(pathToEnd[i]->value, start)) {
			std::count << start->value << std::endl;
			tmp = pathToEnd->last;
			pathToEnd->erase_back();
			start = tmp;
		}
	}

	for (int i = 0; i < pathToEnd.size(); i++) {
		std::count << pathToEnd[i] << std::endl;
	}

	/*for (int i = 0; i < pathToEnd->size(); i++) {
		pathToEnd.erase_at(i);
	}*/

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

