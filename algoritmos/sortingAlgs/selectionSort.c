// complexity: O(n^2)

/*Seleciona o maior elemento para ocupar sua posição no array. Procura o menor/maior valor do array e coloca na primeira posição (a depender)
se a ordenação é crescente ou não. Divide o array em dois: a parte ordenada (esquerda do elemento analisado) e parte não ordenada (direita).
Descarta-se a primeira posição e continua*/
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *V, int tam);
void selectionSort(int *V, int tam){
    int i, j, menor, troca;

    for(i = 0; i < tam; i++){
        menor = i;
        for(j = i+1; j < tam; i++){
            if(V[j] < V[menor]){
                menor = j;
            }
        }
        
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}