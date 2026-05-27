
int buscaOrdenada (int *v, int tamanho, int elemento){
    int i;
    for (i = 0; i < tamanho; i++){
        if(elemento == v[i]){
            return i;
        }else{
            if(elemento < v[i]){
                return -1;
            }
            printf("elemento nao encontrado. \n");
            return -1;
        }
    }
}