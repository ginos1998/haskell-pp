#include "../inc/dijkstra.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

FILE * openFile(const std::string& path);
std::vector<Vertice> readVerticesFromFile(FILE *file);
std::vector<Arista> readAristasFromFile(FILE *file);

int main(int argc, char** argv) {
    /*if (argc != 2) {
        std::cout << "Add a graph file: " << std::endl;
        return 1;
    }*/
    FILE *file;
//    std::string path = argv[1];
    std::string path = "../graph.txt";
    file = openFile(path);
    std::vector<Vertice> vertices = readVerticesFromFile(file);
    std::vector<Arista> aristas = readAristasFromFile(file);

//
//    Arista a0(v0, v1, 2),
//            a1(v0, v2, 4),
//            a2(v1, v2, 1),
//            a3(v1, v3, 7),
//            a4(v2, v3, 3),
//            a5(v2, v4, 5),
//            a6(v3, v4, 1);
//
//    Grafo grafo({v0, v1, v2, v3, v4},
//                {a0, a1, a2, a3, a4, a5, a6});
//
//    Vertice inicio = v0;
//    Vertice destino = v4;
//
//    auto resultados = dijkstra(grafo, inicio, destino);
//
//    imprimirResultados(resultados, inicio, destino);

    return 0;
}

FILE *openFile(const std::string& path) {
    FILE *file;
    file = fopen(path.c_str(), "r");
    if (file == nullptr) {
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }
    return file;
}

std::vector<Vertice> readVerticesFromFile(FILE *file) {
    char line[100];
    std::vector<Vertice> vertices;

    while (fgets(line, sizeof(line), file)) {
        std::istringstream iss(line);
        char type;
        int n;

        if (iss >> type >> n && type == 'v') {
            Vertice vertice(n);
            vertices.push_back(vertice);
        }
    }

    std::cout<< "Vertices: " << std::endl;
    for (auto &vertice : vertices) {
        std::cout << vertice.nombre << std::endl;
    }
    return vertices;
}

std::vector<Arista> readAristasFromFile(FILE *file) {
    char line[100];
    std::vector<Arista> aristas;

    while (fgets(line, sizeof(line), file)) {
        std::istringstream iss(line);
        char type;
        int n, m, w;

        if (iss >> type >> n >> type >> m >> type >> w && type == 'a') {
            // Creating Arista
            Vertice origen(n);
            Vertice destino(m);
            Arista arista(origen, destino, w);
            aristas.push_back(arista);
        }
    }

    std::cout<< "Aristas: " << std::endl;
    int i = 0;
    for (auto &arista : aristas) {
        printf("a%d: %d -> %d\n", i++, arista.origen.nombre, arista.destino.nombre);
    }
    return aristas;
}





