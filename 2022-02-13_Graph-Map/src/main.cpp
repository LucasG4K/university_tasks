#include "graph.hpp"
#include "dataProvider.hpp"
#include <chrono>

#define AULA_11 8
#define MAPA 27

void p1();
void p2();
void p3();
void p4();
void p5_6(int *matrix);

int main() {

	int op;

	system("clear");

	do {
		cout << "\t\tMENU" << endl;
		cout << "1 - PROBLEMA AULA (LISTA  DE ADJACÊNCIA)" << endl;
		cout << "2 - PROBLEMA AULA (MATRIZ DE ADJACÊNCIA)" << endl;
		cout << "3 - PROBLEMA AULA (MATRIZ DE INCIDÊNCIA)" << endl;
		cout << "4 - PROBLEMA PRINCIPAL (MAPEAMENTO COM GRAFO)" << endl;
		cout << "5 - GRAFO DENSO   (144 VÉRTICES) - TEMPO x MEMÓRIA" << endl;
		cout << "6 - GRAFO ESPARSO (144 VÉRTICES) - TEMPO x MEMÓRIA" << endl;
		cout << "0 - SAIR" << endl;
		cout << "Opção: ";
		cin >> op;
		cout << endl;

		switch (op) {
		
		case 1:
			cout << "POR LISTA DE ADJACÊNCIA:" << endl << "=============================" << endl;
			p1();
			break;

		case 2:
			cout << "POR MATRIZ DE ADJACÊNCIA:" << endl << "=============================" << endl;
			p2();
			break;

		case 3:
			cout << "NÃO CONCLUÍDO!" << endl;
			break;

		case 4:
			cout << "PROBLEMA MAPA:" << endl << "=============================" << endl;
			p4();
			break;

		case 5:
			cout << "GRAFO DENSO   (144 VÉRTICES): " << endl;
			p5_6(*matriz_g_denso);
			break;
		
		case 6:
			cout << "GRAFO ESPARSO (144 VÉRTICES): " << endl;
			p5_6(*matriz_g_esparso);
			break;

		case 0:
			return 0;
		
		default:
			cout << "OPÇÃO INVÁLIDA!!" << endl;
			break;
		}

		cout << endl << endl << "Pressione enter para continuar..."; getchar(); while(getchar() != '\n');
		system("clear");

	} while (op != 0);

	return 0;
}

void p1() {
	double time1, time2;

	// Seguindo o grafo da aula 11 - Slide 09
	Graph g(AULA_11); // inicializa o grafo

	for (int i = 0; i < 40; i += 2) {
		g.insertEdge(g.adj[lista_aula_11[i]], g.adj[lista_aula_11[i+1]]);
	}

	g.print();

	cout << "RODANDO BFS" << endl;
	g.BFS(g.adj[0], g.adj[0]);
	
	cout << "RODANDO DFS" << endl;
	g.DFS();
	
}

void p2() {

	// Seguindo o grafo da aula 11 - Slide 09
	Graph g(AULA_11); // inicializa o grafo

	g.insertEdgeMatrix(*matrix_aula_11);

	g.print();

	cout << "RODANDO BFS" << endl;
	g.BFS(g.adj[0], g.adj[0]);

	cout << "RODANDO DFS" << endl;
	g.DFS();

}

void p4() {

	double time1, time2;

	Graph GP(MAPA);

			
	for (int i = 0; i < 128; i += 2) {
		GP.insertEdge(GP.adj[mapa[i]], GP.adj[mapa[i+1]]);
	}

	GP.print();

	cout << "RODANDO BFS:" << endl;
	GP.BFS(GP.adj[6], GP.adj[20]);
}

void p5_6(int *matriz) {

	Graph g(12);

	g.insertEdgeMatrix(matriz);

	g.print();

	cout << "RODANDO BFS:" << endl;
	auto start = chrono::steady_clock::now();
	g.BFS(g.adj[0], g.adj[0]);
	auto end = chrono::steady_clock::now();
	auto time1 = end - start;
	cout << "TEMPO: " << chrono::duration_cast<chrono::microseconds>(time1).count() << "µs" << endl << endl;

	cout << "RODANDO DFS:" << endl;
	start = chrono::steady_clock::now();
	g.DFS();
	end = chrono::steady_clock::now();
	auto time2 = end - start;
	cout << "TEMPO: " << chrono::duration_cast<chrono::microseconds>(time2).count() << "µs" << endl << endl;
	
	if (time1 > time2) cout << "DFS "<< time1 / time2 << "x MAIS RÁPIDO" << endl;
	else 			   cout << "BFS "<< time2 / time1 << "x MAIS RÁPIDO" << endl;

}