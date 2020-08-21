#pragma once
#pragma once
template <class T>
class Node {
public:
	T dato;
	Node* next = nullptr;
	Node(T d) : dato(d) {};
};