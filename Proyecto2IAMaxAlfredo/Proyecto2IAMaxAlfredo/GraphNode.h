#pragma once
#pragma once
#include <iostream>
#include <vector>
using std::cout; using std::endl;
template <class T>
class GraphNode {
private:
    T data;
public:
    bool visitado = false;
    std::vector<GraphNode<T>*> adyacentes;
    T getData() {
        return data;
    }
    GraphNode() {}
    GraphNode(T d) : data(d) {

    }
    ~GraphNode() {}
};