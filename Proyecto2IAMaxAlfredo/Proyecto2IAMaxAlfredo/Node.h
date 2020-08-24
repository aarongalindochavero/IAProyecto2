#pragma once

template<class T>
 struct Node {
   Node(const T &v) : value(v), next(nullptr) {}
   Node(const T &v, Node<T>* node) : value(v), next(node) {}
   ~Node() {};
   T value;
   Node<T> *next;
 };
