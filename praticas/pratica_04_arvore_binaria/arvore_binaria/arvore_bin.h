#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H
#define bool _Bool


typedef struct No No;
No* criarNo(int valor);
No* inserirNo(No* raiz, int valor);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
int contarNos(No* raiz);
int alturaArvore(No* raiz); // retorna a altura da árvore (maior distancia da raiz até a folha)
//main
No* inserirABB(No* raiz, int valor);
bool buscarABB(No* raiz, int alvo);
void liberarArvore(No* raiz);

#endif