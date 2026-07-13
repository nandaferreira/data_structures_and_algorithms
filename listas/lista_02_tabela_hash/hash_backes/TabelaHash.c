/*por questão de desempenho, a tabela Hash irá armazenar só o endereço para a estrutura que contém os dados, e não os dados em si.
Isso evita o gasto excessivo de memória, pois na tabela os elementos ficam dispersos, então várias posições do array podem não possuir
nenhum dado. Assim, se armazenasse uma struct teríamos uma grande quantidade de memória desperdiçada. Para evitar isso, usamos um array
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
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    if(ha !=NULL){ // se a alocação funcionar
        int i;
        ha -> TABLE_SIZE = TABLE_SIZE; // ha = (*ha).TABLE_SIZE
        ha -> itens = (struct aluno**)malloc(TABLE_SIZE*sizeof(struct aluno*)); 

        if(ha -> itens == NULL){
            free(ha);
            return NULL;
        }else{
            ha -> qtd = 0; //indica que nenhum elemento foi inserido na tabela; tem-se apenas o espaço alocado aguardando inserção
            for(i = 0; i < ha->TABLE_SIZE; i++){
            ha -> itens[i] = NULL;}
        }
        
    }
    return ha;
}   //então se 
//===========================================================================================================================================

//apagar tabela
void liberaHash(Hash *ha){
    if(ha != NULL){ //se for diferente de nulo significa que existem elementos; a partir disso segue pra remoção (liberação da memória alocada)
        int i;
        for(i = 0; i< ha->TABLE_SIZE; i++){
            if(ha ->itens[i] != NULL){ //se não estiver nulo significa que tem itens
                free(ha->itens[i]); //libera a memória de cada posição pra apagar o elemento 
            }
        }
        free(ha->itens); //libera o espaço alocado pra estrutura de itens
        free(ha); //libera o espaço pra estrutura da tabela
    }
}
/* Sobre liberaHash
se repararmos, parece que a liberação é feita "de dentro para fora": isso porque primeiro acessamos cada item alocado da estrutura dos alunos
e liberamos esse espaço pra "apagar" os itens. Depois é feita a liberação da memória alocada para armazenar a esrtutura "maior" de itens. E, por fim,
liberou-se o espaço alocado para a própria tabelaHash. */

//===========================================================================================================================================

/*OBS: as operações de inserção e busca requerem o cálculo da posição: para isso usar uma função de Hashing
a função hashing recebe como parâmetro um valor dado (chave). Ela precisa:
- ser simples e barata de se calcular
- garantir que valores diferentes representem posições distintas da tabela

Tipos de método:
- Divisão
- Multiplicação
- Sobra

*/

int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE; // 0x7FFFFFFF é a representação de um inteiro de 32 bits em hexadecimal
}

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}
