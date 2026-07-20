## Prática de Laboratório - Árvores Binárias em C
Fernanda Ferreira de Melo - 12211BCC043
***
### Atividade 1 - Construção e percursos recursivos

**Pré-ordem**
```
void preOrdem(No* raiz){
    if(raiz == NULL){return;}
    printf("\n%d", raiz->info);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
}
```
***
**Em ordem**
```
void emOrdem(No* raiz){
    if(raiz == NULL){return;}
    emOrdem(raiz->esquerdo);
    printf("\n%d", raiz->info);
    emOrdem(raiz->direito);
}
```
***
**Pos Ordem**
```
void posOrdem(No* raiz){
    if(raiz == NULL){return;}
    posOrdem(raiz->esquerdo);
    posOrdem(raiz->direito);
    printf("\n%d", raiz->info);
}
***
```
**Contagem de total de Nos**
```
int contarNos(No* raiz){
    if(raiz == NULL){
        return 0;}

    int total_esq = contarNos(raiz->esquerdo);
    int total_dir = contarNos(raiz->direito);
    return ((total_esq + total_dir)+ 1);
}
```
***
**Altura da arvore**
```
int alturaArvore(No* raiz){
    if(raiz == NULL){
        return -1;
    }

    int alt_esq = alturaArvore(raiz->esquerdo);
    int alt_dir = alturaArvore(raiz->direito);

    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir +1);
    }
}
```
***
**_Perguntas_**

1) No percurso em ordem a árvore é percorrida de forma crescente, ou seja, os nós são visitados primeiro à esquerda, em sequência pelo nó pai e, por fim, pelos nós direitos (filho direito). Logo, uma boa aplicação prática sería quando há necessidade de se obter os elementos de uma árvore em ordem crescente.

2) Porque, por meio da recursão, é possível abordar a estrutura complexa maior da árvore, de forma a dividí-la em problemas menores (sub-árvores) de mesma natureza. Sem a recursão, seria necessário um loop tradicional, o qual pode exigir mais recursos de manutenção. Com a recursão, o algoritmo fica seguro e otimizado.

3) Ele poderia entender que a função chegou ao fim, já que se o No == NULL, então ele retorna ao caso base (é um nó folha).

***
### Atividade 2 - Árvore Binária de Busca (ABB): Inserção


**Inserir ABB**

```
No* inserirABB(No* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->info){
        raiz->esq = inserirABB(raiz->esq, valor);
    } else if(valor > raiz->info){
        raiz->dir = inserirABB(raiz->dir, valor);
    }
    return raiz;
}
```
***
**Buscar ABB**
```
bool buscarABB(No* raiz, int alvo){
    No* atual = raiz;
    while(atual != NULL){
        if(alvo == atual->info) return true;
        if(alvo < atual->info) atual = atual->esq;
        else atual = atual->dir;
    }
    return false;
}
```
***
**Liberar Arvore**
```
void liberarArvore(No* raiz){
    if(raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}
```
***
**_Perguntas_**

1) Resulta em valores ordenados em razão da propriedade da ABB que por definição diz que em uma ABB, para qualquer nó X, todos os nós em sua sub-árvore esquerda possuem valores menores que X, e todos os valores da sub-árvore da direita possuem valores maiores que X. Além disos, a lógica do algoritmo em ordem visita os nós, de forma recursiva, na ordem: esquerda -> raiz (ou pai) -> direita.

2) A complexidade de tempo de inserção e busca no pior caso é de O(N). A complexidade no caso médio, de ambas operações, é de O(log N).

3) Se tentasse inserrir 1, 2, 3, 4, 5 nessa ordem resultaria em  1(raiz) -> 2 -> 3 -> 4 -> 5, o que poderia fazer com que a árvore se degenerasse, ou seja, parasse de comportar como uma árvore (lsita encadeada). Ela perderia eficiência por adotar uma esrtutura linear, que faria com que sua altura se igualasse à quantidade de nós, causando um aumento de complexidade computacional.
***




