## Prática de Laboratório - Árvores Binárias em C
***
### Atividade 1 - Construção e percursos recursivos

**Pré-ordem**

```
void preOrdem_NO(NO* raiz){
    if(raiz == NULL){
        return 1;}

    printf("\n%d", raiz->info);
    preOrdem_NO(&((raiz)->esq));
    preOrdem_NO(&((raiz)->dir));
}
```

**Em ordem**

```
void emOrdem_NO(NO* raiz){
    if(raiz == NULL){
        return 1;
    }
    
    emOrdem_NO(&((raiz)->esq));
    printf("\n%d", raiz->info);
    emOrdem_NO(&((raiz)->dir));
}
```

**Pos Ordem**

```
void posOrdem_NO(NO* raiz){
    if(raiz == NULL){
        return 1;
    }

    posOrdem_NO(&((raiz)->esq));
    posOrdem_NO(&((raiz)->dir));
    printf("\n%d", raiz->info);
}

```

```


```

