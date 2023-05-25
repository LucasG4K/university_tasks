#include "graph.hpp"

int Graph::getVertexCounter() { return vertex_counter ;}

Graph::Graph(int value) {
    vertex_counter = value;
    edges_counter  = 0;
    adj = (Vertex *)malloc(value * sizeof(Vertex));

    for (int i = 0; i < value; i++)
        adj[i] = vertexInitialize(i);

}

Graph::~Graph() {
    for (int i = 0; i < vertex_counter; i++)
        delete[] adj[i];
    delete[] adj;
}

Vertex Graph::vertexInitialize(int value) {
    Vertex v = (Vertex)malloc(sizeof(Vertex));
    v->value = value;
    v->next  = NULL;
    return v;
}

void Graph::insertEdgeMatrix(int *matrix) { // matriz de adjacência para lista
    for (int i = 0; i < vertex_counter; i++) {
        for (int j = 0; j < vertex_counter; j++) {
            if (*(matrix + i * vertex_counter + j) == 1)
                insertEdge(adj[i], adj[j]);
        }
    }
}

void Graph::insertEdge(Vertex vertex_1, Vertex vertex_2) {
    Vertex v = adj[vertex_1->value];

    while (v->next != NULL) {
        if (v->value == vertex_2->value)
            return;
        v = v->next;
    }

    v->next = vertexInitialize(vertex_2->value);
    edges_counter++;
}

void Graph::print() {
    Vertex temp;
    bool controller;

    for (int i = 0; i < vertex_counter; i++) {
        temp = adj[i];
        controller = true;

        while (temp != NULL) {
            !controller ? temp->next != NULL ? cout << temp->value << " : " : cout << temp->value : cout << temp->value << " -> ";
            temp = temp->next;
            controller = false;
        }
        cout << endl;
    }
}