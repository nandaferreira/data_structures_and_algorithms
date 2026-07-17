## Prática de Laboratório - Árvores Binárias em C
***
### Atividade 1 - Construção e percursos recursivos

**Pré-ordem**
```
void preOrdem(No* raiz){
    if(raiz == NULL){
        return 1;
    }
    printf("\n%d", raiz->info);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
}
```
***
**Em ordem**
```
void emOrdem(No* raiz){
    if(raiz == NULL){
        return 1;
    }

    emOrdem(raiz->esquerdo);
    printf("\n%d", raiz->info);
    emOrdem(raiz->direito);
}
```
***
**Pos Ordem**
```
void posOrdem(No* raiz){
    if(raiz == NULL){
        return 1;
    }

    posOrdem(raiz->esquerdo);
    posOrdem(raiz->direito);
    printf("\n%d", raiz->info);
}
***
```
**Contagem de total de Nos**
```
int contaNos(No* raiz){
    if(raiz == NULL){
        return 1;}

    int total_esq = contaNos(raiz->esquerdo);
    int total_dir = contaNos(raiz->direito);
    return ((total_esq + total_dir)+ 1);
}
```
***
**Altura da arvore**
```
int altura(No* raiz){
    if(raiz == NULL){
        return 1;
    }

    int alt_esq = altura(raiz->esquerdo);
    int alt_dir = altura(raiz->direito);

    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir +1);
    }
}
```

