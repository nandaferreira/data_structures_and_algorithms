#include <stdio.h>

int main(){
    int num, i, fatorial = 1;
    
    printf("digite o numero para calcular o fatorial: ");
    scanf("%d", &num);

    for(i = 1; i <= num ; i++){
        fatorial = fatorial*i;
    }
    printf("fatorial de %d eh %d", num, fatorial);
    return 0;
}