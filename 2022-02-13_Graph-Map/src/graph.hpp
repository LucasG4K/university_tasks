#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
using namespace std;

typedef struct TypeVertex *Vertex;

struct TypeVertex {
    int value;   // vértice principal (main vertex)
    Vertex next; // aponta para o próximo vértice que está ligado ao vértice em questão
};

class Graph {

protected:
    int vertex_counter;
    int edges_counter;

public:
    Vertex *adj; // ponteiro de ponteiro devido ao typedef acima -> **

    Graph(int vertex);
    ~Graph();
    Vertex vertexInitialize(int value);
    void insertEdge(Vertex vertex_1, Vertex vertex_2);
    void insertEdgeMatrix(int *matrix);
    void print();
    
    int getVertexCounter();
    

    //SEARCH -> bfs.cpp & dfs.cpp
    void BFS(Vertex start, Vertex end);

    void DFS();
    void DFS_visit(Vertex v, int *color, int *time_to_discover, int *time_to_finish, int *time);
    // FIM SEARCH
};

#endif