#include <iostream>
#include "Tree.h"
#include "Graph.h"
int main()
{
    Tree<int> g(0);

    g.insert(0, 1);
    g.insert(0, 2);
    g.insert(0, 3);
    g.insert(0, 4);
    g.insert(1, 7);
    g.insert(2, 5);
    g.insert(2, 6);
    g.insert(3, 10);
    g.insert(7, 9);
    g.insert(9, 11);


    int valToSearch = 6;
    std::cout << "----Arbol----" << std::endl;
    if (g.searchBFS(valToSearch, g.root))
    {
        std::cout << "Encontre el " << valToSearch << " con BFS" << '\n';
    }
    std::cout << "" << std::endl;
    if (g.searchDFS(valToSearch))
    {
        std::cout << "Encontre el " << valToSearch << " con DFS" << '\n';
    }
    std::cout << "" << std::endl;
    if (g.searchDFSIterative(valToSearch))
    {
        std::cout << "Encontre el " << valToSearch << " con DFSiterative" << '\n';
    }
    std::cout << "" << std::endl;
    if (g.searchDFSLimit(valToSearch, 0, 2))
    {
        std::cout << "Encontre el " << valToSearch << " con DFSLIMIT"<< '\n';
    }
    std::cout << "" << std::endl;
    MultiNode<int>* nd = g.BiderectionalSearch(g.root, g.searchDFS(valToSearch));
    if (nd)
    {
        std::cout << "Con bidireccional el nodo para "<< valToSearch <<" que sigue es " << nd->value << '\n';
    }
    std::cout << "" << std::endl;
    std::cout << "----Grafo----" << std::endl;
    Graph<int> gr(0, 0);
    gr.addEdge(0, 3, 5);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 1);
    gr.addEdge(2, 1, 3);
    gr.addEdge(2, 4, 2);
    gr.addEdge(1, 4, 1);
    gr.addEdge(3, 5, 3);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 6, 6);
    gr.addEdge(5, 6, 2);

    std::cout << "" << std::endl;

    auto djstra = gr.Dijkstra(gr.padre, gr.search(6));

    if (djstra.size() > 0)
    {
        std::cout << "Camino para Dijkstra -> ";
        for (auto nodo : djstra)
        {
            std::cout << nodo->getData() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Ese camino no existe" << std::endl;
    }

    std::cout << "" << std::endl;

    auto aStar = gr.A_star(gr.padre, gr.search(6));

    if (aStar.size() > 0)
    {
        std::cout << "Camino para A* -> ";
        for (auto nodo : aStar)
        {
            std::cout << nodo->getData() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Ese camino no existe" << std::endl;
    }

    std::cout << "" << std::endl;

    auto hillClimb = gr.hillClimb(gr.padre, gr.search(6));

    if (aStar.size() > 0)
    {
        std::cout << "Camino para Hillclimb -> ";
        for (auto nodo : aStar)
        {
            std::cout << nodo->getData() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Ese camino no existe" << std::endl;
    }

}