#include <stdlib.h>
#include <string.h>
#include "ArvBin.h"

typedef struct NO{
    NO* esq;
    int info;
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
    if(raiz == NULL){
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

int contarNos(NO* raiz){
    if(raiz == NULL){
        return 1;
    }
    
    int total_esq = contarNos(&((raiz)->esq));
    int total_dir = contarNos(&((raiz)->dir));
    return ((total_esq + total_dir)+1);

}


/*====Percorrendo uma árvore
Em árvores binárias é muito comum percorrer todos os seus nós, executando alguma ação em cada nó. Essa ação pode ser imprimir o valor do nó, modificar
o valor, remover o valor, etc. Não existe uma ordem "natural" de se percorrer todos os nós de uma árvore binária. Existem os percursos:
- pre-ordem
- em-ordem
- pos-ordem*/

//pre-ordem (void)

//1 - recebe arvore como parametro (raiz)
//2 - verifica se eh valida 
// 3- verifica se eh vazia
// 4- executa o percurso (nesse caso, pre-ordem)
// 4.1 - imprime o valor associado ao no
// 4.2 - chama a funcao recursivamente pra percorrer a subarvore da esq
// 4.3 - chama a funcao recursivamente pra percorrer a subarvore da dir

void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 1;
    }else if(*raiz == NULL){
        return 1;
    }
    printf("\n%d", (*raiz)->info);
    preOrdem_ArvBin(&((*raiz)->esq));
    preOrdem_ArvBin(&((*raiz)-> dir));
}


void preOrdem_NO(NO* raiz){
    if(raiz == NULL){
        return 1;
    }
    printf("\n%d", raiz->info);
    preOrdem_NO(&((raiz)->esq));
    preOrdem_NO(&((raiz)->dir));

}
//em-ordem
//1 - recebe arvore como parametro (ok)
//2 - verifica se eh valida (ok)
//3 - verifica se eh vazia (ok)
//4- se nao invalida/vazia , executa percurso
//4.1 - imprime valor do NO associado
//4.2 - visita a subarvore direita


void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 1;
    }else if(*raiz == NULL){
        return 1;
    }
    emOrdem_ArvBin(&((*raiz)-> esq));
    printf("\n%d", (*raiz)->info);
    emOrdem_ArvBin(&((*raiz)->dir));


}

//pos-ordem
//1- recebe arvore como parametro(raiz)
//2-verifica se eh valida (raiz)
// 3- verifica se eh vazia (*raiz)
// 4- nao eh valida/vazia, executa o percurso
// 4.1 - chama a funcao recursivamente pra percorrer a subarvore da esquerda
// 4.2 - chama a funcao recursivamente pra percorrer a subarvore da direita
// 4.3 - imprime valor do NO

void posOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 1;
    } else if(*raiz == NULL){
        return 1;}

    posOrdem_ArvBin(&((*raiz)->esq));
    posOrdem_ArvBin(&((*raiz)->dir));
    printf("\n%d", (*raiz)-> info);
}