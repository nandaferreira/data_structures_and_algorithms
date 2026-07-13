#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int tam);
void selectionSort(int *v, int tam){
    int i, j, menor, troca;
    for(i = 0; i < tam; i++){
        menor = i;
        for(j = i + 1; j < tam; j++){
            if(v[j] < menor){
                menor = j;
            }
        }

        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

int buscaOrdenada(int *v, int tam, int elemento);
int buscaOrdenada(int *v, int tam, int elemento){
    int i;

    for(i = 0; i < tam; i++){
        if(elemento == v[i]){
            return i;
        }else{
            if(elemento < v[i]){
                return -1;
            }
        }
    }
    return -2;
}

int main(){
    int i, tamanho, elemento;
    int *vetor;
    int posicao;

    printf("tamanho do vetor: \n");
    scanf("%d", &tamanho);

    if(tamanho < 0){
        printf("tamanho invalido!\n");
        return -1;
    }

    vetor = (int *)malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        printf("alocacao invalida \n");
        return -1;
    }

    for(i = 0; i < tamanho; i++){
        printf("digite valor da posicao [%d]: \n", i);
        scanf("%d", &vetor[i]);
    }

    printf("qual valor deseja encontrar? \n");
    scanf("%d", &elemento);

    int ordenado = 1;

    for(i =0; i < tamanho; i++){
        if(vetor[i] > vetor[i+1]){
            ordenado = 0;
            break;
        }
    }

    posicao = buscaOrdenada(vetor, tamanho, elemento);
    if(ordenado == 1){
        
        buscaOrdenada(vetor, tamanho, elemento);
        printf("\nvalor encontrado na posicao: %d", posicao + 1);
    }else{
        selectionSort(vetor, tamanho);
        buscaOrdenada(vetor, tamanho, elemento);
        printf("\nvalor encontrado na posicao: %d ", posicao + 1);

    }
    return 0;
}