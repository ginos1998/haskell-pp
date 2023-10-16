#include "../inc/dijkstra.h"

int main() {
    Vertice v0(0), 
            v1(1), 
            v2(2), 
            v3(3), 
            v4(4);

    Arista a0(v0, v1, 2), 
            a1(v0, v2, 4), 
            a2(v1, v2, 1), 
            a3(v1, v3, 7), 
            a4(v2, v3, 3), 
            a5(v2, v4, 5), 
            a6(v3, v4, 1);

    Grafo grafo({v0, v1, v2, v3, v4}, 
                {a0, a1, a2, a3, a4, a5, a6});

    Vertice inicio = v0;
    Vertice destino = v4;
}