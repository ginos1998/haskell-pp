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

DijkstraResult dijkstra(const Grafo& grafo, const Vertice& inicio, const Vertice& destino) {
    auto pesos = inicializarPesos(grafo, inicio);
    auto noConocidos = obtenerNoConocidos(grafo);
    auto resultados = DijkstraResult{pesos, std::vector<Vertice>(grafo.vertices.size(), inicio), {}, {inicio}, noConocidos};

    while (!noConocidos.empty()) {
        auto verticeActual = *std::min_element(noConocidos.begin(), noConocidos.end(),
                                               [&](const Vertice& a, const Vertice& b) {
                                                   return resultados.pesos[a.nombre] < resultados.pesos[b.nombre];
                                               });

        if (verticeActual.nombre == destino.nombre) {
            break;
        }

        noConocidos.erase(std::remove(noConocidos.begin(), noConocidos.end(), verticeActual), noConocidos.end());
        for (const auto& arista : grafo.aristas) {
            if (arista.origen.nombre == verticeActual.nombre) {
                resultados = actualizarResultados(resultados, arista, grafo);
            }
        }
    }

    return resultados;
}

DijkstraResult actualizarResultados(const DijkstraResult& resultados, const Arista& arista, const Grafo& grafo) {
    auto nuevosPesos = resultados.pesos;
    auto nuevosPrevios = resultados.previos;
    auto nuevosVerticesConocidos = resultados.verticesConocidos;
    auto nuevosVerticesNoConocidos = resultados.verticesNoConocidos;

    int pesoArista = obtenerPesoArista(grafo, arista.origen, arista.destino);

    if (resultados.pesos[arista.destino.nombre] > resultados.pesos[arista.origen.nombre] + pesoArista) {
        nuevosPesos[arista.destino.nombre] = resultados.pesos[arista.origen.nombre] + pesoArista;
        nuevosPrevios[arista.destino.nombre] = arista.origen;

        auto itNoConocidos = std::find(nuevosVerticesNoConocidos.begin(), nuevosVerticesNoConocidos.end(), arista.destino);
        if (itNoConocidos != nuevosVerticesNoConocidos.end()) {
            nuevosVerticesNoConocidos.erase(itNoConocidos);
        }

        auto itConocidos = std::find(nuevosVerticesConocidos.begin(), nuevosVerticesConocidos.end(), arista.destino);
        if (itConocidos == nuevosVerticesConocidos.end()) {
            nuevosVerticesConocidos.push_back(arista.destino);
        }
    }

    return {nuevosPesos, nuevosPrevios, {arista}, nuevosVerticesConocidos, nuevosVerticesNoConocidos};
}

void imprimirResultados(const DijkstraResult& resultados, const Vertice& inicio, const Vertice& destino) {
    std::cout << "Camino más corto desde el vértice " << inicio.nombre << " hasta el vértice " << destino.nombre << ":\n";
    std::cout << "Peso total: " << resultados.pesos[destino.nombre] << "\n";
    std::cout << "Vector de Pesos: ";
    for (int peso : resultados.pesos) {
        std::cout << peso << " ";
    }
    std::cout << "\n";
    std::cout << "Camino: ";

    std::vector<int> camino;
    int actual = destino.nombre;
    while (actual != inicio.nombre) {
        camino.push_back(actual);
        actual = resultados.previos[actual].nombre;
    }
    camino.push_back(inicio.nombre);

    for (auto it = camino.rbegin(); it != camino.rend(); ++it) {
        std::cout << *it;
        if (it + 1 != camino.rend()) {
            std::cout << " -> ";
        }
    }

    std::cout << "\n";
    std::cout << "Vertices Conocidos: ";
    for (const auto& vertice : resultados.verticesConocidos) {
        std::cout << vertice.nombre << " ";
    }
    std::cout << "\n";
    std::cout << "Vertices No Conocidos: ";
    for (const auto& vertice : resultados.verticesNoConocidos) {
        std::cout << vertice.nombre << " ";
    }
    std::cout << "\n";
    
}