#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include <stdbool.h>

int main(){
    No* raizABB = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    int n = sizeof(valores)/ sizeof(valores[0]);

    for(int i = 0; i <n; i++){
        raizABB = inserirABB(raizABB, valores[i]);
    }

    printf("Em-ordem da ABB: ");
    emOrdemABB(raizABB); //deve imprimir ordem crescente
    printf("\n");

    printf("Buscar 45: %s\n", buscarABB(raizABB, 45) ? "Sim" : "Nao");
    printf("Buscar 100: %s\n", buscarABB(raizABB, 100) ? "Sim" : "Nao");

    liberaABB(raizABB);
    return 0;

}