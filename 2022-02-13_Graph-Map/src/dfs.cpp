#include "graph.hpp"

void Graph::DFS_visit(Vertex v, int *color, int *time_to_discover, int *time_to_finish, int *time) {
    color[v->value] = 1;
    *time += 1;
    time_to_discover[v->value] = *time;

    for(Vertex index = adj[v->value]; index != NULL; index = index->next)
        if(color[index->value] == 0)
        DFS_visit(index, color, time_to_discover, time_to_finish, time);

    color[v->value] = 2;
    *time += 1;
    time_to_finish[v->value] = *time;
    printf("Vertex:%d D:%d, F:%d \n", v->value, time_to_discover[v->value], time_to_finish[v->value]);
}

void Graph::DFS() {
    int color[vertex_counter];            // Branco 0, Cinza 1, Preto 2
    int time_to_discover[vertex_counter]; // Tempo de descoberta
    int time_to_finish[vertex_counter];   // Tempo de finalização
    int time = 0;

    for(int v = 0; v < vertex_counter; v++)
        color[v] = 0;

    for(int v = 0; v < vertex_counter; v++)
        if(color[v] == 0)
            DFS_visit(adj[v], color, time_to_discover, time_to_finish, &time);
}
