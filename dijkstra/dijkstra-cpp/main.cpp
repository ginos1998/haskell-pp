#include "../inc/dijkstra.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

int validInput(int argc, char** argv);
FILE * openFile(const std::string& path);
void readFromFile(FILE *file);
void createVertice(int n);
void createArista(int n, int m, int w);
std::vector<Vertice> vertices;
std::vector<Arista> aristas;
int validInicioDestino(const Grafo& grafo, int inicio, int destino);

int main(int argc, char** argv) {
    try {
//        argc = 4;
//        argv[1] = "../graph.txt";
//        argv[2] = "0";
//        argv[3] = "4";
        if (validInput(argc, argv) == 1) {
            return 1;
        }
        FILE *file;
        std::string path = argv[1];
        file = openFile(path);
        readFromFile(file);

        std::cout<< "Vertices: ";
        for (auto &vertice : vertices) {
            printf("v%d ", vertice.nombre);
        }

        std::cout<< "\nAristas: " << std::endl;
        int i = 0;
        for (auto &arista : aristas) {
            printf("{a%d}: (v%d) --[%d]-- (v%d)\n", i++, arista.origen.nombre, arista.peso, arista.destino.nombre);
        }

        Grafo grafo(vertices, aristas);

        if (validInicioDestino(grafo, std::stoi(argv[2]), std::stoi(argv[3])) == 1) {
            return 1;
        }
        Vertice inicio = vertices[std::stoi(argv[2])];
        Vertice destino = vertices[std::stoi(argv[3])];
        auto resultados = dijkstra(grafo, inicio, destino);
        imprimirResultados(resultados, inicio, destino);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int validInput(int argc, char** argv) {
    if (argc == 2 && std::string(argv[1]) == "-h") {
        std::cout << "Usage: ./dijkstra <path_to_file> <start_vertice> <end_vertice>" << std::endl;
        return 1;
    }

    if (argc != 4) {
        printf("Error: Invalid input. Arguments needed 4. You've passed %d.\nTry ./dijkstra -h for help", argc);
        return 1;
    }
    return 0;
}

int validInicioDestino(const Grafo& grafo, int inicio, int destino) {
    if (inicio < 0 || inicio >= grafo.vertices.size()) {
        printf("Error: Invalid input. Start vertice must be between 0 and %lu.\n", grafo.vertices.size() - 1);
        return 1;
    }
    if (destino < 0 || destino >= grafo.vertices.size()) {
        printf("Error: Invalid input. End vertice must be between 0 and %lu.\n", grafo.vertices.size() - 1);
        return 1;
    }
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

void readFromFile(FILE *file) {
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        std::istringstream iss(line);
        char type;
        int n, m, w, x;

        if (iss >> type >> n && type == 'v') {
            createVertice(n);
        } else if (sscanf(line, "a%d(v%d,v%d,%d)", &x, &n, &m, &w) == 4) {
            createArista(n, m, w);
        }
    }
}

void createVertice(int n) {
    Vertice vertice(n);
    vertices.push_back(vertice);
}

void createArista(int n, int m, int w) {
    Vertice origen(n);
    Vertice destino(m);
    Arista arista(origen, destino, w);
    aristas.push_back(arista);
}





