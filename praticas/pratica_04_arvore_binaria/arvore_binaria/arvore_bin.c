#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore_bin.h"

struct No{
    No* esquerdo;
    int info;
    No* direito;
};

No* criarNo(int valor){
    No* novo;

    novo = (No*)malloc(sizeof(No));
    novo ->info = valor;
    novo ->direito = NULL;
    novo ->esquerdo = NULL;
    return novo;
}

No* inserirNo(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->info){
        raiz-> esquerdo = inserirNo(raiz->esquerdo, valor);
    }else if(valor > raiz->info){
        raiz->direito = inserirNo(raiz->direito, valor);
    }
    return raiz;
}


void preOrdem(No* raiz){
    if(raiz == NULL){return;}
    printf("\n%d", raiz->info);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
}

void emOrdem(No* raiz){
    if(raiz == NULL){return;}
    emOrdem(raiz->esquerdo);
    printf("\n%d", raiz->info);
    emOrdem(raiz->direito);
}

void posOrdem(No* raiz){
    if(raiz == NULL){return;}
    posOrdem(raiz->esquerdo);
    posOrdem(raiz->direito);
    printf("\n%d", raiz->info);
}

int contarNos(No* raiz){
    if(raiz == NULL){
        return 0;}

    int total_esq = contarNos(raiz->esquerdo);
    int total_dir = contarNos(raiz->direito);
    return ((total_esq + total_dir)+ 1);
}

int alturaArvore(No* raiz){
    if(raiz == NULL){
        return -1;
    }

    int alt_esq = alturaArvore(raiz->esquerdo);
    int alt_dir = alturaArvore(raiz->direito);

    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir +1);
    }
}

No* inserirABB(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->info){
        raiz->esquerdo = inserirABB(raiz->esquerdo, valor);
    }else if(valor > raiz->info){
        raiz->direito = inserirABB(raiz->direito, valor);
    }

    return raiz;
}

bool buscarABB(No* raiz, int alvo){
    if(raiz == NULL){
        return false;
    }else if(alvo == raiz->info){
        return true;
    }else if(alvo < raiz->info){
        return buscarABB(raiz->esquerdo, alvo);
    }else{
        return buscarABB(raiz->direito, alvo);
    }
}

void liberarArvore(No* raiz){
    if(raiz == NULL){
        return;
    }

    liberarArvore(raiz->esquerdo);
    liberarArvore(raiz->direito);
    free(raiz);
}