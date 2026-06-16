#include <stdio.h>
#include <stdlib.h>

//test com: 7 | 5 | 10 | 6 | 8

void bubbleSort(int *vetor, int tamanho);
void bubbleSort(int *vetor, int tamanho){
    int i, continua, aux, fim;
    
    fim = tamanho;
    do{
        continua = 0;
        for(i = 0; i < tamanho - 1; i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = i;
            }
        }
        fim--; // fim = fim - 1
    } while(continua != 0);
    
}

//dinamico
/*int main(){

    int *vetor;
    int tamanho;

    printf("=== ordenação bubble sort ===\n");
    printf("entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho *sizeof(int));
    if( vetor == NULL){
        printf("temos um problema....\n");
        return 1;
    }

    for(int i = 0; i < tamanho; i++){
        printf("entre com o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    bubbleSort(vetor, tamanho);

    printf("====vetor ordenado====\n");
    for(int i = 0; i < tamanho; i++){
        printf("| %d |", vetor[i]);

    }
    printf("\n");


    return 0;
}
*/

int main(){
    int vetor[] = {7, 5, 10, 6, 8};

    printf("=== bubble sort ===\n");
    bubbleSort(vetor, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }

}
