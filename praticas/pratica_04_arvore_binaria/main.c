#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

int main(){
    No* raiz = NULL;

    int valor, op = 0;
            while(op != 5){
                printf("\n===arvore binaria===\n");
                printf("01 - inserir valor\n");
                printf("02 - total de nos\n");
                printf("03 - altura da arvore\n");
                printf("04 - percorrer arvore\n");
                printf("05 - sair\n");
                printf("digite a operacao desejada: ");
                scanf("%d", &op);

                switch(op){
                    case 1:{
                        printf("\ninserir valor: ");
                        scanf("%d", &valor);
                        raiz = inserirNo(raiz, valor);
                        break;
                    }
                    
                    case 2:{
                        printf("\ntotal de nos da arvore: %d\n", contarNos(raiz));
                        break;
                    }

                    case 3:{printf("\naltura da arvore: %d\n", alturaArvore(raiz));}
                    

                    case 4:{
                        int metodo;
                        printf("\npercorrer: \n1 - preOrdem \n2- emOrdem \n3- posOrdem \n");
                        scanf("%d", &metodo);
                        if(metodo != 1 && metodo != 2 && metodo != 3){
                            printf("\nopcao invalida!\n");
                        }else if(metodo == 1){
                            preOrdem(raiz);
                        }else if(metodo == 2){
                            emOrdem(raiz);
                        }else if(metodo == 3){
                            posOrdem(raiz);
                        }
                        break;
                    }

                    case 5:{
                        printf("\n...saindo\n");
                        break;   
                    }

                    default: 
                        printf("\nopcao invalida!\n");

                }
            }
        return 0;      
}