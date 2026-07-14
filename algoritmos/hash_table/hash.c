#include "hash.h"
#include <stdlib.h>
#include <string.h>

typedef struct hash{
    int qtd;
    int TABLE_SIZE;
    Aluno **itens; 
}Hash;

Hash* criaHash(int TABLE_SIZE){
    Hash* ha;
    
    ha = (Hash*)malloc(sizeof(Hash));
    if(ha != NULL){
        int i;

        ha->TABLE_SIZE = TABLE_SIZE; // (*ha).TABLE_SIZE = TABLE_SIZE;
        ha -> itens = (Aluno**);
            malloc(TABLE_SIZE*(sizeof(struct aluno*)));

            if(ha-> itens == NULL){
                free(ha);
                printf("\n====memoria liberada======\n");
                return NULL;
            }

            ha -> qtd = 0;

            for(i = 0; i < ha -> TABLE_SIZE; i++){
                ha-> itens[i] = NULL;
            }
    }

    return ha;
}

void liberaHash(Hash* ha){
    if(ha != NULL){
        int i;

        for(i = 0; i < ha -> TABLE_SIZE; i++){
            if(ha -> itens[i] != NULL){
                free(ha -> itens[i]);
            }
        }
        free(ha -> itens);
        free(ha);
    }
}