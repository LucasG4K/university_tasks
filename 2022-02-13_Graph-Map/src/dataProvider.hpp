#ifndef DATAPROVIDER_HPP
#define DATAPROVIDER_HPP

int lista_aula_11[] = {0, 2, 0, 1, 1, 0, 1, 4, 1, 5, 2, 0, 2, 3, 3, 2, 4, 1, 4, 5, 4, 6, 5, 1, 5, 4, 5, 6, 5, 7, 6, 4, 6, 5, 6, 7, 7, 6, 7, 5};

int mapa[] = {0, 3, 1, 4, 2, 3, 3, 0, 3, 2, 3, 4, 3, 6, 4, 1, 4, 3, 4, 7, 5, 8, 6, 3, 6, 12, 7, 4, 7, 8, 7, 13, 8, 5, 8, 7, 8, 9, 8, 15, 9, 8, 9, 10, 9, 16, 10, 9, 11, 12, 12, 11, 12, 6, 12, 13, 12, 18, 13, 12, 13, 7, 13, 14, 14, 13, 14, 15, 14, 19, 15, 14, 15, 8, 15, 16, 15, 23, 16, 20, 16, 15, 16, 9, 17, 18, 18, 17, 18, 12, 18, 19, 19, 18, 19, 14, 19, 22, 20, 16, 20, 21, 20, 25, 21, 20, 22, 19, 22, 23, 23, 22, 23, 26, 23, 24, 24, 23, 24, 15, 24, 25, 25, 20, 25, 24, 26, 23};

int matriz_g_denso[][12] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}};

int matriz_g_esparso[13][13] = {
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0}};

// matriz de adjacência
int matrix_aula_11[][8] = {
/*		S	W	R	V	T	X	U	Y	*/
/*S*/  {0,	1,	1,	0,	0,	0,	0,	0},
/*W*/  {1,	0,	0,	0,	1,	1,	0,	0},
/*R*/  {1,	0,	0,	1,	0,	0,	0,	0},
/*V*/  {0,	0,	1,	0,	0,	0,	0,	0},
/*T*/  {0,	1,	0,	0,	0,	1,	1,	0},
/*X*/  {0,	1,	0,	0,	1,	0,	1,	1},
/*U*/  {0,	0,	0,	0,	1,	1,	0,	1},
/*Y*/  {0,	0,	0,	0,	0,	1,	1,	0}};
  
// matriz de incidência
int matrix_2[8][10] = {
/*		A	B	C	D	E	F	G	H	I   J*/
/*S*/  {-1,	1,	1,	0,	0,	0,	0,	0,  0,  0},
/*W*/  {0,  0,	1,	1,	1,	0,	0,	0,  0,  0},
/*R*/  {1,	1,  0,	0,	0,	0,	0,	0,  0,  0},
/*V*/  {1,	0,	1, -1,	0,	0,	0,	0,  0,  0},
/*T*/  {0,	1,	0,	0, -1,	1,	1,	0,  0,  0},
/*X*/  {0,	1,	0,	0,	1, -1,	1,	1,  0,  0},
/*U*/  {0,	0,	0,	0,	1,	1, -1,	1,  0,  0},
/*Y*/  {0,	0,	0,	0,	0,	1,	1, -1,  0,  0}};


#endif

/*
A, D, B, E, C, D, D, A, D, C, D, E, D, G, E, B, E, D, E, H, F, I, G, D, G, M, H, E, H, I, H, N, I, F, I, H, I, J, I, P, J, I, J, K, J, Q, K, J, L, M, M, L, M, G, M, N, M, S, N, M, N, H, N, O, O, N, O, P, O, T, P, O, P, I, P, Q, P, X, Q, U, Q, P, Q, J, R, S, S, R, S, M, S, T, T, S, T, O, T, W, U, Q, U, V, U, Z, V, U, W, T, W, X, X, W, X, A1, X, Y, Y, X, Y, P, Y, Z, Z, U, Z, Y, A1, X*/

/*
0, 2, 0, 1, 1, 0, 1, 4, 1, 5, 2, 0, 2, 3, 3, 2, 4, 1, 4, 5, 4, 6, 5, 1, 5, 4, 5, 6, 5, 7, 6, 4, 6, 5, 6, 7, 7, 6, 7, 5*/
