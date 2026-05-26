/*Escreva um algoritmo que receba um vetor ordenado e um número extra e 
insira esse número na sua posição correta no vetor ordenado, deslocando 
os outros números se necessário.*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int tam);
void insertionSort(int *v, int tam){
    int i, j, aux;

    for(i = 0; i < tam; i++){
        aux = v[i];
        
        for(j = i; j > 0 && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}


int main(){

    int i, tamanho;
    int *vetor;

    printf("tamanho do vetor: \n");
    scanf("%d", &tamanho);

    if(tamanho < 0){
        printf("tamanho invalido.\n");
        return -1;
    }
    vetor = (int *)malloc((tamanho + 1)*sizeof(int));

    if(vetor == NULL){
        printf("erro de alocacao; \n");}

    for(i = 0; i < tamanho; i++){
        printf("digite o valor da posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int ordenado = 1;
    for(i = 0; i < tamanho - 1; i++){
        if(vetor[i] > vetor[i +1]){
            ordenado = 0;
            break;
        }
    }

    if(ordenado == 1){
        for(i = 0; i < tamanho; i++){
            printf("|%d|", vetor[i]);
        }
    }else{
        printf("===ordenando vetor===\n");
        insertionSort(vetor, tamanho);

        for(i = 0; i < tamanho; i++){
            printf("|%d|", vetor[i]);
        }
    }

    return 0;
}

