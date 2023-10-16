#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct Vertice {
    int nombre;
    Vertice(int n) : nombre(n) {}
};

bool operator==(const Vertice& v1, const Vertice& v2) {
    return v1.nombre == v2.nombre;
}

struct Arista {
    Vertice origen;
    Vertice destino;
    int peso;
    Arista(Vertice o, Vertice d, int p) : origen(o), destino(d), peso(p) {}
};

struct Grafo {
    std::vector<Vertice> vertices;
    std::vector<Arista> aristas;
    Grafo(const std::vector<Vertice>& v, const std::vector<Arista>& a) : vertices(v), aristas(a) {}
};

struct DijkstraResult {
    std::vector<int> pesos;
    std::vector<Vertice> previos;
    std::vector<Arista> recorridas;
    std::vector<Vertice> verticesConocidos;
    std::vector<Vertice> verticesNoConocidos;
};

std::vector<int> inicializarPesos(const Grafo& grafo, const Vertice& inicio);

std::vector<Vertice> obtenerNoConocidos(const Grafo& grafo);

int obtenerPesoArista(const Grafo& grafo, const Vertice& origen, const Vertice& destino);



#endif // DIJKSTRA_H
