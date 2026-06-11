#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

typedef struct No {
    char chave;
    struct No *proximo;
} No;

No *tabela[TAMANHO];

void inicializar() {
    for (int i = 0; i < TAMANHO; i++)
        tabela[i] = NULL;
}

void inserir(char chave, int hash) {
    No *novo = (No *)malloc(sizeof(No));
    novo->chave = chave;
    novo->proximo = NULL;

    if (tabela[hash] == NULL) {
        tabela[hash] = novo;
    } else {
        No *atual = tabela[hash];
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
    }
}

void imprimir_tabela() {
    printf("estado da tabela:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" cadeia %d: ", i);
        No *atual = tabela[i];
        while (atual != NULL) {
            printf("%c", atual->chave);
            if (atual->proximo != NULL) printf(" -> ");
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void buscar(char chave, int hash) {
    printf("\nbuscando '%c' (hash=%d):\n", chave, hash);
    printf("sequencia de comparacoes: ");
    No *atual = tabela[hash];
    while (atual != NULL) {
        printf("%c", atual->chave);
        if (atual->chave == chave) {
            printf("encontrado\n");
            return;
        }
        printf(", ");
        atual = atual->proximo;
    }
    printf("nao encontrado\n");
}

int main() {

    inicializar();

    char chaves[] = {'D','Q','B','I','M','H','G','U','A','C','R','S'};
    int  hashes[] = { 2,  0,  0,  1,  2,  0,  2,  1,  2,  1,  1,  2};
    int total = 12;

    for (int i = 0; i < total; i++)
        inserir(chaves[i], hashes[i]);

    imprimir_tabela();
    buscar('J', 2);

    return 0;
}