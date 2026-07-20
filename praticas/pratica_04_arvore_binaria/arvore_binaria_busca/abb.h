#ifndef ABB_H
#define ABB_H

#include <stdbool.h>

typedef struct No No;

No* criarNo(int valor);
No* inserirABB(No* raiz, int valor);
bool buscarABB(No* raiz, int alvo);
void liberaABB(No* raiz);
void emOrdemABB(No* raiz);
No* menorValor(No* raiz);
No* removerABB(No* raiz, int valor);
#endif