#include "../inc/dijkstra.h"

std::vector<int> inicializarPesos(const Grafo& grafo, const Vertice& inicio) {
    std::vector<int> pesos(grafo.vertices.size(), std::numeric_limits<int>::max());
    pesos[inicio.nombre] = 0;
    return pesos;
}

std::vector<Vertice> obtenerNoConocidos(const Grafo& grafo) {
    return grafo.vertices;
}

int obtenerPesoArista(const Grafo& grafo, const Vertice& origen, const Vertice& destino) {
    auto it = std::find_if(grafo.aristas.begin(), grafo.aristas.end(),
                           [&](const Arista& arista) {
                               return arista.origen == origen && arista.destino == destino;
                           });

    return (it != grafo.aristas.end()) ? it->peso : std::numeric_limits<int>::max();
}