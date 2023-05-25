#include "graph.hpp"
#include "queue.hpp"

void Graph::BFS(Vertex start, Vertex end) {
    Queue q;

    int color[vertex_counter]; // 0 Branco - Desconhecido, 1 Cinza - Conhecido mas não visitado, 2 Preto - Conhecido e visitado
    int level[vertex_counter]; // distância do vértice de origem
    int predecessor[vertex_counter]; // -1 == NULL

    // inicializa informações dos vértices
    for (int index = 0; index < vertex_counter; index++) {
        if (index != start->value) {
            color[index]       =  0; // não visitado
            level[index]       = -1; // infinito
            predecessor[index] = -1; // não tem pai ainda
        }
    }

    color[start->value]       =  1;
    level[start->value]       =  0;
    predecessor[start->value] = -1;

    q.inqueue(start->value);

    while (q.getSize() > 0) {
        Block *data = q.dequeue(); // passa o primeiro valor da fila que deve ter a posição em ADJ explorada

        for (Vertex vtx = adj[data->value]; vtx != NULL; vtx = vtx->next) {
            if (color[vtx->value] == 0) {
                color[vtx->value] = 1;
                level[vtx->value] = level[data->value] + 1; // vindo de data->value para vtx->value
                predecessor[vtx->value] = data->value;
                q.inqueue(vtx->value);
            }
        }
        color[data->value] = 2;
        printf("Vertex:%3d  %3d::%d::%d\n", data->value, predecessor[data->value], data->value, level[data->value]);
    }
    
    if (end->value == start->value) return; // NÃO BUSCA O MENOR CAMINHO
/*
    SHORTEST PATH inicia aqui!!!
    O caminho é percorrido de trás para frente para achar a melhor solução
*/
    // verifica se existe alguma solução possível
    if (color[end->value] == 0) { cout << "NÃO EXISTEM CAMINHOS POSSÍVEIS PARA CHEGAR AO DESTINO!!" << endl; return; }
    
    int temp = end->value;
    while (temp != -1) {          // se bater em -1 chegou a origem -> sem pai
        q.inqueue(temp);          // registra o caminho na fila
        temp = predecessor[temp]; // próximo pai
    }

    q.reverse();
    q.print();
}
