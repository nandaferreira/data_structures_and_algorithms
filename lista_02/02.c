#include <stdio.h>
#include <string.h>

#define M 10
#define VAZIO -1
#define CHAVES_CONT 6

int chaves[] = {371, 121, 173, 203, 11, 24};

void cria_tabela(int tabela[]) {
    for (int i = 0; i < M; i++)
        tabela[i] = VAZIO;
}

void imprime_tabela(int tabela[]) {
    printf("indice | chave\n");
    for (int i = 0; i < M; i++) {
        if (tabela[i] == VAZIO)
            printf("%2d |---\n", i);
        else
            printf("%2d | %d\n", i, tabela[i]);
    }
    printf("\n");
}

// a)
void insere_linear(int tabela[], int k) {
    printf("inserindo %d:\n", k);
    for (int i = 0; i < M; i++) {
        int pos = (k + i) % M;
        printf("    i=%d -> posicao %d", i, pos);
        if (tabela[pos] == VAZIO) {
            tabela[pos] = k;
            printf(" [inserido]\n");
            return;
        } else {
            printf(" [ %d]\n", tabela[pos]);
        }
    }
    printf("tabela cheia %d.\n", k);
}

void sondagem_linear() {
    printf("sondagem linear\n");
    printf("\n");

    int tabela[M];
    cria_tabela(tabela);

    for (int j = 0; j < CHAVES_CONT; j++)
        insere_linear(tabela, chaves[j]);

    printf("\nestado final da tabela:\n");
    imprime_tabela(tabela);
}

//b)
void insercao_quadratica(int tabela[], int k) {
    printf("inserindo %d:\n", k);
    for (int i = 0; i < M; i++) {
        int pos = (k + i * i) % M;
        printf("    i=%d -> posicao %d", i, pos);
        if (tabela[pos] == VAZIO) {
            tabela[pos] = k;
            printf(" [inserido]\n");
            return;
        } else {
            printf(" [ %d]\n", tabela[pos]);
        }
    }
    printf("tabela cheia %d.\n", k);
}

void sondagem_quad() {
    
    printf("\nsondagem quadratica\n");

    int tabela[M];
    cria_tabela(tabela);

    for (int j = 0; j < CHAVES_CONT; j++)
        insercao_quadratica(tabela, chaves[j]);

    printf("\nestado final da tabela:\n");
    imprime_tabela(tabela);
}

//c)
void insere_quadratico(int tabela[], int k) {
    printf("  inserindo %d:\n", k);
    for (int i = 0; i < M; i++) {
        int pos = (k + 2 * i + i * i) % M;
        printf("    i=%d -> posicao %d", i, pos);
        if (tabela[pos] == VAZIO) {
            tabela[pos] = k;
            printf(" [inserido]\n");
            return;
        } else {
            printf(" [ %d]\n", tabela[pos]);
        }
    }
    printf("tabela cheia %d.\n", k);
}

void sondagem_quadratica() {
    
    printf("sondagem quadratica\n");
    

    int tabela[M];
    cria_tabela(tabela);

    for (int j = 0; j < CHAVES_CONT; j++)
        insere_quadratico(tabela, chaves[j]);

    printf("\nestado final da tabela:\n");
    imprime_tabela(tabela);
}

//d)
   
void insere_hashDuplo(int tabela[], int k) {
    int h1 = k % M;
    int h2 = 7 - (k % 7);
    printf("  inserindo %d: h1=%d, h2=%d\n", k, h1, h2);
    for (int i = 0; i < M; i++) {
        int pos = (h1 + i * h2) % M;
        printf("    i=%d -> posicao %d", i, pos);
        if (tabela[pos] == VAZIO) {
            tabela[pos] = k;
            printf(" [inserido]\n");
            return;
        } else {
            printf(" [ %d]\n", tabela[pos]);
        }
    }
    printf(" tabela %d.\n", k);
}

void hashing_duplo() {
   
    printf("\nhash duplo\n");
    printf("h1(k) = k %% M\n");
    printf("h2(k) = 7 - (k %% 7)\n");
    printf("h(k,i) = (h1(k) + i * h2(k)) %% M\n");
    printf("\n");

    int tabela[M];
    cria_tabela(tabela);

    for (int j = 0; j < CHAVES_CONT; j++)
        insere_hashDuplo(tabela, chaves[j]);

    printf("\nestado final da tabela:\n");
    imprime_tabela(tabela);
}

int main() {
    printf("tabela hash - M = %d\n", M);
    printf("chaves a inserir: ");
    for (int i = 0; i < CHAVES_CONT; i++)
        printf("%d%s", chaves[i], i < CHAVES_CONT - 1 ? ", " : "\n");
    printf("\n");

    sondagem_linear();
    sondagem_quad();
    sondagem_quadratica();
    hashing_duplo();

    return 0;
}