#include <stdlib.h>
#include <string.h>
#include "ArvBin.h"

typedef struct NO{
    NO* esq;
    int dado;
    NO* dir;
}NO;

//cria arvore
ArvBin* cria_ArvBin(){
    ArvBin* raiz;
    raiz = (ArvBin*)malloc(sizeof(ArvBin));

    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//libera arvore
/* para liberar uma árvore binária é necessária uma função para percorrer recursivamente
todos os nós da árvore e liberá-los, libera_NO, e outra para inicializar a destruição da árvore e liberar
a memória alocada para a raiz, libera_ArvBin*/


void libera_NO(struct NO* no){
    if (no == NULL){
        return;
    }else{
        libera_NO(no->esq);
        libera_NO(no->dir);
        free(no);
        no = NULL;
    }
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }else{
        libera_NO(*raiz); //libera cada nó
        free(raiz); //libera a raiz
    }
}



//estaVazia
//inserir elemento
//remover elemento
//busca elemento
//calcula altura
//preOrdem
//emOrdem
//posOrdem
