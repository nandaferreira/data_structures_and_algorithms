//26 65 45 73 10 18 78 93 70 49 23 22
#include <stdio.h>

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int temporario = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temporario;
        }
    }
    int temporario = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temporario;
    return i + 1;
}

int main() {
    int numeros[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    int posicaoPivo = particionar(numeros, 0, 11);

    printf("\nvetor resultante:\n");
    imprimirVetor(numeros, 12);
    printf("\nposicao do pivo = %d\n", posicaoPivo);

    return 0;
}
