// Proyecto2IAMaxAlfredo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tree.h"
#include "Graph.h"
int main()
{
    Tree<int> g(0);
    /*g.insert(0, 1);
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
    g.insert(13, 15);*/

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

    g.searchDFSLimit(10, 0, 2);

    //g.printBFS(g.root);
    g.printDFS();
    //g.searchDFSIterative(52);
    //g.WSearchLimit(5);

    //std::cout << "Hello World!\n";

    Graph<int> gr(0, 0);
<<<<<<< Updated upstream
=======
    /*gr.addEdge(0, 1, 1);
    gr.addEdge(0, 2, 2);
    gr.addEdge(0, 8, 3);

>>>>>>> Stashed changes
    gr.addEdge(0, 3, 5);
    gr.addEdge(0, 1, 4);
    gr.addEdge(0, 2, 1);
    gr.addEdge(2, 1, 3);
    gr.addEdge(2, 4, 2);
    gr.addEdge(1, 4, 1);
    gr.addEdge(3, 5, 3);
    gr.addEdge(3, 4, 2);
    gr.addEdge(4, 6, 6);
    gr.addEdge(5, 6, 2);*/
    gr.addEdge(0, 3, 1);
    gr.addEdge(3, 4, 2);
    gr.addEdge(3, 6, 3);
    gr.addEdge(4, 11, 1);
    gr.addEdge(4, 12, 2);
    gr.addEdge(6, 12, 3);
    gr.addEdge(6, 8, 1);
    gr.addEdge(11, 9, 2);
    gr.addEdge(12, 9, 3);
    gr.addEdge(9, 15, 2);

<<<<<<< Updated upstream
    //gr.search(0);
    std::cout << "" << std::endl;

    gr.Dijkstra(gr.search(0), gr.search(11));

    std::cout << "" << std::endl;


    gr.printBFS();
=======
    gr.HeuristicFunction(15);
    gr.search(0);

    // std::cout << "" << std::endl;

    // gr.Dijkstra(gr.search(0), gr.search(6));
    //// gr.hillClimb(gr.search(0), gr.search(5));
    // std::cout << "" << std::endl;
    // gr.printHillClimb(gr.search(0), gr.search(6));
    // std::cout << "" << std::endl;

    gr.WSearchLimit(15);
    //gr.printBFS();
>>>>>>> Stashed changes
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
