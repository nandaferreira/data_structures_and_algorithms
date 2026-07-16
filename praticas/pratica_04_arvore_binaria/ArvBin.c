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

//libera no
/* para liberar uma árvore binária é necessária uma função para percorrer recursivamente todos os nós da árvore e liberá-los, libera_NO, 
e outra para inicializar a destruição da árvore e liberar a memória alocada para a raiz, libera_ArvBin*/

void libera_NO(struct NO* no){
    if (no == NULL){
        return;
    }else{
        libera_NO(no->esq); //acessa o NO esquerdo
        libera_NO(no->dir); //acessa o NO direito
        free(no); //libera o No
        no = NULL;
    }
}

//libera arvore
void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }else{
        libera_NO(*raiz); //libera cada nó
        free(raiz); //libera a raiz
    }
}

//estaVazia
// Uma ávore binária será considerada vazia sempre que o conteúdo da sua 'raiz' apontar para a constante NULL

int estaVazia_ArvBin(ArvBin* raiz){
    if(raiz == NULL){ //verifica primeiro se o ponteiro ArvBin* raiz é igual a NUll. Se for verdade, teve algum problema na criação da árvore e, nesse caso, não teria uma árvore válida para trabalhar
        return 1; //erro de criacao - arvore invalida
    }else if(*raiz == NULL){ //se foi criada com sucesso, entao é possivel acessar o conteudo da sua 'raiz' (*raiz) e comparar com NULL. Se for NULL, valor atribuido a raiz quando vazia, entao a arvore esta vazia
        return 1;}
    return 0; // nao esta vazia
}

int totalNO_ArvBin(ArvBin* raiz){
    //sempre verificar primeiro se a arvore foi corretamente criada, ou seja, se a raiz nao eh NULL. Se nao for, eh possivel entrar no conteudo (*raiz) e comecar a contagem

    if(raiz == NULL){
        return 0;
    }else if(*raiz == NULL){
        return 0;
    }
    int total_esq = totalNO_ArvBin(&((*raiz)-> esq));
    int total_dir = totalNO_ArvBin(&((*raiz)-> dir));
    return(total_esq + total_dir + 1);

}

int altura_ArvBin(ArvBin* raiz){
    if(raiz ==NULL){
        return 0;
    }else if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvBin(&((*raiz)-> esq));
    int alt_dir = altura_ArvBin(&((*raiz)-> dir));

    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }
    else
        return (alt_dir + 1);
}