// Proyecto2IAMaxAlfredo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Graph.h"
int main()
{
    Graph<int> g(0);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(0, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 8);
    g.addEdge(1, 10);
    g.addEdge(4, 1);
    g.addEdge(4, 9);
    g.addEdge(10, 4);
    g.addEdge(10, 20);
    g.addEdge(5, 20);
    g.addEdge(20, 50);
    g.addEdge(20, 51);
    g.addEdge(10, 52);
    g.addEdge(10, 52);
    g.addEdge(5, 20);
    g.addEdge(9, 13);
    g.addEdge(13, 15);
    g.printBFS();
    g.WSearchLimit(5);
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
