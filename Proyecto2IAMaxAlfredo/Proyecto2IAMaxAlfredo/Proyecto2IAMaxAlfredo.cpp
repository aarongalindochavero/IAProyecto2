// Proyecto2IAMaxAlfredo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tree.h"
#include "Graph.h"
int main()
{
    Tree<int> g(0);
    g.insert(0, 1);
    g.insert(0, 2);
    g.insert(0, 4);
    g.insert(0, 6);
    g.insert(4, 5);
    g.insert(0, 4);
    g.insert(4, 5);
    g.insert(0, 8);
    g.insert(1, 10);
    g.insert(4, 1);
    g.insert(4, 9);
    g.insert(10, 4);
    g.insert(10, 20);
    g.insert(5, 20);
    g.insert(20, 50);
    g.insert(20, 51);
    g.insert(10, 52);
    g.insert(10, 52);
    g.insert(5, 20);
    g.insert(9, 13);
    g.insert(13, 15);
    //g.printBFS(g.root);
    g.printDFS();
    g.searchDFSIterative(52);
    //g.WSearchLimit(5);

    std::cout << "Hello World!\n";

    Graph<int> gr(0, 0);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 1);
    gr.addEdge(0, 3, 5);
    gr.addEdge(3, 5, 3);
    gr.addEdge(3, 4, 2);
    gr.addEdge(1, 4, 1);
    gr.addEdge(2, 4, 2);
    gr.addEdge(2, 1, 3);
    gr.addEdge(4, 6, 6);
    gr.addEdge(5, 6, 2);

    gr.search(0);

    std::cout << "" << std::endl;

    gr.Dijkstra(gr.search(0), gr.search(6));

    std::cout << "" << std::endl;

    gr.printBFS();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
