/*por questão de desempenho, a tabela Hash irá armazenar só o endereço para a estrutura que contém os dados, e não os dados em si.
Isso evita o gasto excessivo de memória, pois na tabela os elementos ficam dispersos, então várias posições do array podem não possuir
nenhum dado. Assim, se armazenasse uma struct teríamos uma grande quantidade de memória desperdiçada. Para evitar qisso, usamos um array
de ponteiros (que ocupa menos memória que a struct) e à medida que os elementos são inseridos na tabela, realiza-se a alocação daquele 
único elemento.*/

#include <stdlib.h>
#include <string.h>
#include "TabelaHash.h"

typedef struct hash{
    int qtd, TABLE_SIZE;
    struct aluno **itens; // a ideia aqui é alocar um array de pontiros de tamanho TABLE_SIZE no campo itens para armazenar os elementos inseridos na tabela.
}hash;

//cria tabela
Hash *criaHash(int TABLE_SIZE){
    Hash *ha = (Hash *)malloc(sizeof(Hash));
    if(ha !=NULL){
        int i;
        ha -> TABLE_SIZE = TABLE_SIZE; // ha = (*ha).TABLE_SIZE
        ha -> itens = (struct aluno**)malloc(TABLE_SIZE*sizeof(struct aluno*));

        if(ha -> itens == NULL){
            free(ha);
            return NULL;
        }else{
            ha -> qtd = 0;
            for(i = 0; i < ha->TABLE_SIZE; i++){
            ha -> itens[i] = NULL;}
        }
        
    }
    return ha;
}

//apagar tabela

void liberaHash(Hash *ha){
    if(ha != NULL){
        int i;
        for(i = 0; i< ha->TABLE_SIZE; i++){
            if(ha ->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}