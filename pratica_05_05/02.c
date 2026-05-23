/*Faça um programa C que crie dinamicamente uma matriz de dimensão NxM 
usando alocação dinâmica.  Os valores de N e M deverão ser lidos. Em seguida 
leia valores para a matriz e calcule a soma dos elementos da matriz. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, M,i, j;
    int **mat;

    printf("========matriz dinâmica========");
    printf("dimensao N (linhas) da matriz: \n");
    scanf("%d", &N);
    printf("dimensao M (colunas) da matriz: \n");
    scanf("%d", &M);

    //verificar primeiro se as dimensoes sao validas

    if(N <= 0 || M <= 0){
        printf("valores invalidos.\n");
        return -1;
    }
    
    mat = malloc(N *sizeof(int *)); //aloca um vetor onde cada elemetno[i] tem um ponteiro para inteiro

    for(i = 0; i < N; i++){
        mat[i] = malloc(M*sizeof(int)); //aloca cada uma das linhas como vetores inteiros (representando as colunas)
    }
    
    //preencher ela com valores lidos do teclado

    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            printf("entre com um valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("============================\n");
    printf("========Matriz N X M========\n");

    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            printf("| %d ", mat[i][j]);
        }
        printf("\n");
    }

    for(i=0; i < N; i++){
        free(mat);
    }


    return 0;
}







//=================================

/*int main(){
    int i, j, M, N;
    int **mat; //pra acessar os valores da matriz (lembrar que ela é um array de arrays)

    printf("|----soma de matrizes----\n");
    printf("tamanho de M (linhas): \n");
    scanf("%d", &M);
    printf("tamanho de N(colunas): \n");
    scanf("%d", &N);

   //verifica primeiro se os valores de entrada sao validos pra alocação, ou seja, maior ou igual a 0

   if(M <= 0 || N <= 0){
    fprint(stderr, "dimensoes invalidas. entre com valores iguais ou maiores que 0. \n");
    return 1;
   }

   //aloca vetor de ponteiros (linhas)

   mat = (int **)malloc(N*sizeof(int *));
   if(!mat){
    fprintf(stderr, "Erro de alocacao. \n");
   }


    //primeiro alocar memoria para o vetor externo;
}    
*/

