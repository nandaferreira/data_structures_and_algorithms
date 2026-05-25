/*Escreva um algoritmo que receba valores em um vetor e imprima ORDENADO se o vetor estiver em ordem crescente*/

#include <stdio.h>
#include <stdlib.h>

/*
1-> recebe valor do tamanho do vetor (verifica se eh um tamanho ok)
2 -> aloca espaço para o vetor
3 -> verifica se alocação deu certo
4 -> le valores
5 -> verifica se tá ordenado (ordem crescente)
    int ordenado = 1; (começa assumindo que sim!)
    laço que vai até (tamanho-1) pra não acessar posição inválida

6 -> Ordena vetor

*/

void selectionSort(int *vet, int tam);
void selectionSort(int *vet, int tam){
    int i, j, menor, troca;

    for(i = 0; i < tam -1; i++){
        menor = i; // considera a posicao atual como o menor e já "separa" o vetor, considerando que essa parte está ordenada. 
        
        for(j = i+1; j < tam; j++){ // itera sobre a parte direita do vetor separado pra comparar com o dito menor; tam-1 pra nao extrapolar memoria quando chegar no ultimo elemento
            if(vet[j] < vet[menor]){
                menor = j; //atribui a posicao, nao o valor
            }
        }
        if( i!= menor){ //considerando que "menor" recebeu a posicao de j 
                troca = vet[i]; // "troca" guarda o valor de vet[i] (antigo menor)
                vet[i] = vet[menor]; // vet[i] recebe o atual menor valor vet[menor] -> sendo: menor = j
                vet[menor] = troca; //
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
    
    //pra verificar a ordenação, tenho que assumir que o vetor tá ordenado, utilizando uma variavel de controle (flag)

    int ordenado = 1;

    for(int i = 0; i < tamanho-1; i++){
        if(vetor[i] > vetor[i+1]){
            ordenado = 0; // vetor nao ordenado
            printf("nao ta ordenado ein...\n");
            break;
        }
    }

    if(ordenado == 1){
        printf("====valores encontrados====\n");
        for(int i = 0; i < tamanho; i++){
            printf("|%d ", vetor[i]);
        }
    }else{
        printf("====ordenando vetor====\n");
        
        selectionSort(vetor,  tamanho);
        
        for(int i = 0; i < tamanho; i++){
            printf("|%d", vetor[i]);
        }
    }
}

