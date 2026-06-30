/*o tipo de dado que será armazenado na tabela: struct aluno
o aluno é representado por matricula, nomes e tres notas*/

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
} aluno;

typedef struct hash Hash;

Hash *criaHash(int tamanho);
void liberaHash(Hash *ha);
int valorString(char *str);
int insereHash_SemColisao(Hash *ha, struct aluno al);
int buscaHash_SemColisao(Hash *ha, int mat, struct aluno *al);
int insereHash_EnderAberto(Hash *ha, struct aluno al);
int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno *al);

