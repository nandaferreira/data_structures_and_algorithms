#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"
#include "TabelaHash.c"

//primeira coisa: criar uma tabela vazia
//*ao escolher o tamanho da tabela hash, o ideal é escolher um número primo e 
//evitar valores que sejam potência de dois. Escolher numero primo para tamanho 
//da tabela reduz a probabilidade de colisões


int main(){
    int TABLE_SIZE, qtd;
    struct aluno **itens;
    Hash *tabela;

    printf("====tabela hash====\n");
    printf("tamanho da tabela: ");
    scanf("%d", &TABLE_SIZE);

    printf("\n====criando tabela hash...===\n");
    tabela = criaHash(TABLE_SIZE);


}

