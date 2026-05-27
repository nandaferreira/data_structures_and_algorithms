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