#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int tam);
void insertionSort(int *v, int tam){
    int i, j, aux;

    for(i = 1; i < tam; i++){
        aux = v[i];
        for(j = i; j > 0 && aux < v[j-1]; j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}


int main(){

    int i, tamanho, extra = 0;
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

    printf("entre com um valor a acrescentar: \n");
    scanf("%d", &extra);

    vetor[tamanho] = extra;

    int ordenado = 1;
    for(i = 0; i < tamanho; i++){
        if(vetor[i] > vetor[i +1]){
            ordenado = 0;
            break;
        }
    }

    if(ordenado == 1){
        for(i = 0; i < (tamanho +1); i++){
            printf("|%d|", vetor[i]);
        }
    }else{
        printf("===ordenando vetor===\n");
        insertionSort(vetor, tamanho + 1);

        for(i = 0; i < (tamanho+1); i++){
            printf("|%d|", vetor[i]);
        }
        printf("\n");
    }

    free(vetor);
    return 0;
}

