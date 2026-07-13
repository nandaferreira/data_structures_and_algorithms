#include <stdio.h>
#include <string.h>

struct pessoa {
    int matricula;
    char nome[30];
    float nota;
};

int compararPorCampo(const struct pessoa *a, const struct pessoa *b, int campo) {
    switch (campo) {
        case 1: 
            if (a->matricula < b->matricula) return -1;
            if (a->matricula > b->matricula) return 1;
            return 0;
        case 2: 
            return strcmp(a->nome, b->nome);
        case 3:
            if (a->nota < b->nota) return -1;
            if (a->nota > b->nota) return 1;
            return 0;
        default:
            return 0;
    }
}

void trocarPessoa(struct pessoa *a, struct pessoa *b) {
    struct pessoa temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPessoas(struct pessoa vetor[], int n, int campo) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (compararPorCampo(&vetor[j], &vetor[menor], campo) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            trocarPessoa(&vetor[i], &vetor[menor]);
        }
    }
}

void imprimirPessoas(const struct pessoa vetor[], int n) {
    printf("%-10s %-30s %s\n", "matricula", "nome", "nota");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-30s %.2f\n", vetor[i].matricula, vetor[i].nome, vetor[i].nota);
    }
}

int main(void) {
    struct pessoa pessoas[5] = {
        {2023001, "Luisa Silva", 8.5f},
        {2023005, "Janice Ferreira", 7.2f},
        {2023003, "Carlos Melo", 9.1f},
        {2023002, "Aline Santos", 6.8f},
        {2023004, "Luan Santos", 8.9f}
    };
    
    int campo;
    printf("escolha o campo para ordenar:\n");
    printf("1-matricula\n");
    printf("2-nome\n");
    printf("3-nota\n");
    printf("opcao: ");
    scanf("%d", &campo);

    if (campo < 1 || campo > 3) {
        printf("Campo invalido. Use 1, 2 ou 3.\n");
        return 1;
    }

    ordenarPessoas(pessoas, 5, campo);

    printf("\narray ordenado:\n");
    imprimirPessoas(pessoas, 5);

    return 0;
}
