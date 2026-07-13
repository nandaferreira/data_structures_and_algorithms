#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int destino;
    int peso;
    struct No *proximo;
}No;

typedef struct{
    int V;
    No **lista;
}Grafo;

//exercicio - complete a função

void adicionarAresta(Grafo *g, int origem, int destino, int peso){

    No *novo = malloc(sizeof(No));
    novo ->destino = destino;
    novo ->peso = peso;
    novo ->proximo;
}

//complexidade: O(n)