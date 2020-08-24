#pragma once
#include "Vector.h"
#include "Node.h"

template <class T>
struct MultiNode
{
	T value;
	MultiNode<T>* parent;
	Vector<MultiNode<T>*> vertex;
	MultiNode(const T& v) : value(v), vertex(Vector<MultiNode<T>*>()){}
	MultiNode(const T& v, int size) : value(v), vertex(Vector<MultiNode<T>*>(size)){}
	~MultiNode() { delete vertex; };
};
