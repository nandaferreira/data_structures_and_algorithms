/* Defina uma função para inserir elementos no início de uma lista encadeada 
considerando passagem por valor e referência; */

#include <stdio.h>
#include <stdlib.h>

typedef struct Alunos {
    char nome[25];
    struct Alunos *prox;
} alunos;

alunos *inicializa() {
    return NULL;
}

alunos *insereLista(alunos *lista, char nome[]) {
    alunos *novo = (alunos *)malloc(sizeof(alunos));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        return lista;
    }
    strcpy(novo->nome, nome);
    novo->prox = lista;
    return novo;
}