#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vet, int tam);
void selectionSort(int *vet, int tam){
    int i, j, menor, troca;

    for(i = 0; i < tam -1; i++){
        menor = i; 
        
        for(j = i+1; j < tam; j++){ 
            if(vet[j] < vet[menor]){
                menor = j; 
            }
        }
        if( i!= menor){ 
                troca = vet[i]; 
                vet[i] = vet[menor]; 
                vet[menor] = troca; 
            }
    }
}

int main(){
    int tamanho;
    int *vetor;
    printf("entre com o tamanho:\n");
    scanf("%d", &tamanho);

    if(tamanho < 1 || tamanho > 100){
        printf("tamanho invalido.\n");
        return -1;
    }

    vetor =(int *) malloc(tamanho*sizeof(int));

    if(vetor == NULL){
        printf("erro de alocacao =(\n");
        return 2;
    }

    for (int i = 0; i < tamanho; i++){
        printf("entre com o valor pra posicao [%d]", i);
        scanf("%d", &vetor[i]);
    }

    int ordenado = 1;

    for(int i = 0; i < tamanho-1; i++){
        if(vetor[i] > vetor[i+1]){
            ordenado = 0; // vetor nao ordenado
            printf("nao ta ordenado ein...\n");
            break;
        }
    }

    if(ordenado == 1){
        printf("\n====valores encontrados====\n");
        for(int i = 0; i < tamanho; i++){
            printf("|%d ", vetor[i]);
        }
    }else{
        printf("\n====ordenando vetor====\n");
        
        selectionSort(vetor,  tamanho);
        
        for(int i = 0; i < tamanho; i++){
            printf("|%d", vetor[i]);
        }
        printf("\n");
        printf("\nORDENADO\n");
    }

    free(vetor);
    return 0;
}