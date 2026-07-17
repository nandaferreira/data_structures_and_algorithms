#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H


typedef struct No No;
No* criarNo(int valor);
No* inserirNo(No* raiz, int valor);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
int contarNos(No* raiz);
int alturaArvore(No* raiz); // retorna a altura da árvore (maior distancia da raiz até a folha)
//main

#endif