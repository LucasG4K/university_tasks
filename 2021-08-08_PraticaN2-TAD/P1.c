#include "P1&Lista.h"
#include <time.h>
#include <string.h>

//submenu 1
int menuP1() {
    do {
        system("CLS");
        char option;
        printf("Problema 1 - Listas:\n");
        printf("A - Concatenar L1 e L2\n");
        printf("B - Jogo\n");
        printf("C - Mercado (incompleta)\n");
        printf("X - Voltar\n");
        printf("Opcao: ");
        scanf(" %c", &option);

        system("CLS");

        switch (option) {
        case ('A'): case ('a'):
            p1A();
            break;

        case ('B'): case ('b'):
            p1B();
            break;

        case ('C'): case ('c'):
            p1C();
            break;

        case ('X'): case ('x'):
            printf("Voltando para o menu principal...");
            return 0;
            break;

        default:
            printf("Opcao invalida!");
            break;
        }
        system("PAUSE");
    } while (1);
}

//retorna numeros randomizados no intervalo desejado
int numGen(int interval) {
    //srand(time(NULL));
    return rand() % interval;
}

//problema 1A (permutacao de 2 listas)
void p1A() {
    Lista L1, L2, L3;
    ItemP1 d;
    BlockP1* aux1, * aux2;
    int i = 0, k = 0, temp;

    initL(&L1);
    initL(&L2);
    initL(&L3);

    //preenchimento L1 e L2 -> par e impar respectivamente
    while (i < P1A || k < P1A) {
        temp = numGen(200);
        if (temp % 2 == 0 && i < P1A) {
            d.val = temp;
            insertL(&L1, d);
            i++;
        }
        else if (temp % 2 != 0 && k < P1A) {
            d.val = temp;
            insertL(&L2, d);
            k++;
        }
    }

    //preenchimento L3
    aux1 = L1.first->next;
    aux2 = L2.first->next;
    while (aux2 != NULL) {
        d = aux1->data;
        insertL(&L3, d);
        d = aux2->data;
        insertL(&L3, d);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    printf("---------------\nLista 1\n");
    printL(&L1);
    printf("---------------\nLista 2\n");
    printL(&L2);
    printf("---------------\nLista 3\n");
    printL(&L3);

    emptyL(&L1);
    emptyL(&L2);
    emptyL(&L3);
}

//problema 1B (jogo)
void p1B() {
    Lista L1, L2, L3;
    BlockP1* temp1, * temp2, * temp3;
    ItemP1 d;
    int i = 0, k = 0;

    initL(&L1);
    initL(&L2);
    initL(&L3);

    //preenche L1 e L2
    while (i < P1B || k < P1B) {
        d.val = numGen(13);
        if (d.val != 0 && i < P1B) {
            insertL(&L1, d);
            i++;
        }
        d.val = numGen(13);
        if (d.val != 0 && k < P1B) {
            insertL(&L2, d);
            k++;
        }
    }

    //numero inicial para o jogo
    int temp = numGen(13);
    temp == 0 ? temp = 1 : temp;
    printf("...................\n"
        "Numero inicial: %d\n"
        "...................\n"
        "Regra: (L1[i] - inicial + L2[i] - inicial = ?) => O maior ganha!\n\n", temp);

    //preenche lista auxilixar (L3) e imprime L1 e L2 em intervalos
    temp1 = L1.first->next;
    temp2 = L2.first->next;
    printf("Pares: {");

    while (i > 0) {
        printf("{%d , %d", temp1->data.val, temp2->data.val);
        i != P1B - 2 ? printf("}, ") : printf("}");

        d.val = temp1->data.val - temp + temp2->data.val - temp;
        insertL(&L3, d);

        temp1 = temp1->next;
        temp2 = temp2->next;
        i--;
    }

    printf("}\n\n");

    temp1 = L3.first->next;
    while (temp1 != NULL) {

        printf("Soma %d: %d\n", i + 1, temp1->data.val);

        i++;
        temp2 = temp1;
        temp1 = temp2->next;
    }

    //comparacoes
    temp1 = L3.first->next;
    printf("---------------------------------");
    if (temp1->data.val > temp1->next->data.val && temp1->data.val > temp1->next->next->data.val)
        printf("\n|Soma 1 (valor: %d) vencedor!!!|\n", temp1->data.val);

    else if (temp1->next->data.val > temp1->data.val && temp1->next->data.val > temp1->next->next->data.val)
        printf("\n|Soma 2 (valor: %d) vencedor!!!|\n", temp1->next->data.val);

    else if (temp1->next->data.val == temp1->data.val && temp1->next->data.val == temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->data.val == temp1->data.val && temp1->next->data.val > temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->data.val > temp1->data.val && temp1->next->data.val == temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->data.val < temp1->data.val && temp1->data.val == temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->data.val == temp1->data.val && temp1->data.val > temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->next->data.val == temp1->data.val && temp1->next->data.val < temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else if (temp1->next->next->data.val > temp1->data.val && temp1->next->data.val == temp1->next->next->data.val)
        printf("\n|           EMPATE!!!          |\n");

    else printf("\n|Soma 3 (valor: %d) vencedor!!!|\n", temp1->next->next->data.val);
    printf("---------------------------------\n");

    emptyL(&L1);
    emptyL(&L2);
    emptyL(&L3);
}

//problema 1C (mercado) -> incompleta
void p1C() {
    ListaC L1, L2, L3;
    ItemP1C d1, d2, d3;

    initLc(&L1);
    initLc(&L2);
    initLc(&L3);

    d1.produto = "Arroz 5kg";
    d1.val = 30.80;
    d1.id = 1;
    insertLc(&L1, d1);

    d1.produto = "Feijao 1kg";
    d1.val = 10.20;
    d1.id = 2;
    insertLc(&L1, d1);

    d1.produto = "Milho Verde 200g";
    d1.val = 4.00;
    d1.id = 3;
    insertLc(&L1, d1);

    d2.mercado = "Mercado 1";
    d2.id = 1;
    insertLc(&L2, d2);

    d2.mercado = "Mercado 2";
    d2.id = 2;
    insertLc(&L2, d2);

    d2.mercado = "Mercado 3";
    d2.id = 3;
    insertLc(&L2, d2);

    printProdutoAllc(&L1);
    printMercadoAllLc(&L2);

    emptyLc(&L1);
    emptyLc(&L2);
    emptyLc(&L3);
}