/*Faça um programa C que crie dinamicamente um vetor de inteiros de tamanho
N. Para tal use alocação dinâmica. O valor de N deverá ser lido. Em seguida
leia valores para o vetor e determine o maior valor elemento do valor lido.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N; // tamanho do vetor
    int *p;

    printf("N do vetor (em inteiro): \n");
    scanf("%d", &N);
    p = (int *)malloc(N*sizeof(int));

    for(int i = 0; i < N; i++){
        printf("digite valor para a posicao [%d]: \n", i);
        scanf("%d", &p[i]);
    }

    /*printf("|----valores encontrados----|\n");
    for(int i = 0; i < N; i++){
        printf("| %d ", p[i]);
    }*/

    int maior;
    maior = p[0];
    
    for (int i = 0; i < N; i++){
        if(p[i] > maior){
            maior = p[i];
        }
    }
    
    printf("maior elemento : %d\n", maior);

    free(p); // libera os dados (eles são armazenados na memória heap)
}   

/*Lopes version

#include <stdio.h>
#include <stdlib.h>

int main(){
int n, i, maior;
int *v;

printf("digite N");
scanf("%d", &N);

if(!v){
fprintf(stderr, "Erro de alocacao.\n")




}




}

*/