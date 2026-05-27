#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *v, int tam);
void selectionSort(int *v, int tam){
    int i, j, maior, troca;
    
    for(i = 0; i < tam; i++){
        maior = i;
        for(j = i + 1; j < tam; j++){
            if(v[j] > v[maior]){
                maior = j;
            }
        }
        if(i != maior){
            troca = v[i];
            v[i] = v[maior];
            v[maior] = troca;
        }
    }
}

int main(){
    int i, tamanho;
    int *vetor;
    
    printf("====ordenacao decrescente com selection sort====\n");
    printf("entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if(tamanho < 0){
        printf("tamanho precisa ser positivo.\n");
        return -1;
    }

    vetor = (int *)malloc(tamanho*sizeof(int));

    if(vetor == NULL){
        printf("erro de alocacao =(\n");
        return -2;
    }

    for(i = 0; i < tamanho; i++){
        printf("\ndigite o valor para a posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    int ordenado = 1;
    for(i = 0; i < tamanho-1; i++){
        if(vetor[i] < vetor[i+1]){
            ordenado = 0;
            printf("vetor nao esta ordenado...\n");
            break;
        }
    }

    if(ordenado == 1){
        for(i = 0; i < tamanho; i++){
            printf("|%d|", vetor[i]);
        }
    }else{
        selectionSort(vetor, tamanho);
        printf("===vetor ordenado====\n");
        for(i = 0; i < tamanho; i++){
            printf("| %d |\n", vetor[i]);
        }
    }
    
    free(vetor);
    return 0;
}