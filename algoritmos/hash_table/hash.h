
typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
}Aluno;

Hash* criaHash (int TABLE_SIZE);
void liberaHash(Hash* ha);
