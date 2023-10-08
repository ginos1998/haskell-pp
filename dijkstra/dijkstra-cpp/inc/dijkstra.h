#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <limits>

struct Vertex {
    int name;
};

struct Edge {
    Vertex origin;
    Vertex dest;
    int weigth;
};

struct Grafo {
    std::vector<Vertex> Vertexs;
    std::vector<Edge> edges;
};

struct Dijkstra {
    std::vector<Edge> a;
    std::vector<Vertex> knownVertexs;
    std::vector<Vertex> unknownVertexs;
    std::vector<int> acWeigth;
    std::vector<Vertex> prevVertex;
};

const int oo = std::numeric_limits<int>::max();

Vertex nullVertex();

int costo(const std::vector<Edge>& edgeVector, const Vertex& originVertex, const Vertex& destVertex);

std::vector<Vertex> prevInitVertex(const Vertex& vertex, const std::vector<Vertex>& vertexVector);

std::vector<int> initAcum(const std::vector<Edge>& acumEdges, const Vertex& vertex, const std::vector<Vertex>& vertexVector);

template <typename T>
std::vector<T> changeN(const T& a, int n, const std::vector<T>& vec);

Dijkstra generateInit(const Vertex& vertex, const Grafo& grafo);

int getWeigth(const std::vector<int>& weigths, const Vertex& vertex);

std::pair<std::vector<int>, std::vector<Vertex>> actualWeigth(const std::pair<std::vector<int>, std::vector<Vertex>>& status,
                                                         const std::vector<Edge>& edgeVector);

Dijkstra interaction(const Dijkstra& dijkstra);

Dijkstra shortPath(const Dijkstra& dijkstra);

#endif // DIJKSTRA_H
