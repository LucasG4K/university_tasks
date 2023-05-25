#include "P1&Lista.h"
#include "P2&Pilha.h"
#include "P3&Fila.h"

int main() {
    system("CLS");
    do {
        int option;

        printf(".....................\n");
        printf("    Menu Problemas:\n");
        printf(".....................\n");
        printf("1 - Problema 1 - Lista\n");
        printf("2 - Problema 2 - Pilha\n");
        printf("3 - Problema 3 - Fila\n");
        printf("4 - Problema 4 (nao feita)\n");
        printf("0 - SAIR\n");
        printf("Opcao: ");
        scanf("%d", &option);
        
        switch (option) {
        case 1:
            menuP1();
            break;
        
        case 2:
            menuP2();
            break;
        
        case 3:
            menuP3();
            break;
        
        case 4:
            //menuP4();
            break;
        
        case 0:
            printf("Saindo...");
            return 0;
            break;
        
        default:
            printf("Opcao invalida!");
            break;
        }

        system("CLS");
    } while(1);

    return 0;
}