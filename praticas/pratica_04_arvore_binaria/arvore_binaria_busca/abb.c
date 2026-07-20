#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct No {
    No* esq;
    int info;
    No* dir;
};

No* criarNo(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL) return NULL;
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserirABB(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->info){
        raiz->esq = inserirABB(raiz->esq, valor);
    } else if(valor > raiz->info){
        raiz->dir = inserirABB(raiz->dir, valor);
    }
    return raiz;
}

bool buscarABB(No* raiz, int alvo){
    No* atual = raiz;
    while(atual != NULL){
        if(alvo == atual->info) return true;
        if(alvo < atual->info) atual = atual->esq;
        else atual = atual->dir;
    }
    return false;
}

void liberaABB(No* raiz){
    if(raiz == NULL) return;
    liberaABB(raiz->esq);
    liberaABB(raiz->dir);
    free(raiz);
}

void emOrdemABB(No* raiz){
    if(raiz == NULL) return;
    emOrdemABB(raiz->esq);
    printf("%d ", raiz->info);
    emOrdemABB(raiz->dir);
}

No* menorValor(No* raiz){
    No* atual = raiz;
    while(atual && atual->esq != NULL){
        atual = atual->esq;
    }
    return atual;
}

static No* removerNo(No* no){
    if(no->esq == NULL){
        No* temp = no->dir;
        free(no);
        return temp;
    }

    if(no->dir == NULL){
        No* temp = no->esq;
        free(no);
        return temp;
    }

    No* sucessor = menorValor(no->dir);
    no->info = sucessor->info;
    no->dir = removerABB(no->dir, sucessor->info);
    return no;
}

No* removerABB(No* raiz, int valor){
    if(raiz == NULL){
        return NULL;
    }

    if(valor < raiz->info){
        raiz->esq = removerABB(raiz->esq, valor);
    } else if(valor > raiz->info){
        raiz->dir = removerABB(raiz->dir, valor);
    } else {
        raiz = removerNo(raiz);
    }

    return raiz;
}