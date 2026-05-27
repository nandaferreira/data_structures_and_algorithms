void insertionSort(int *v, int tam);
void insertionSort(int *v, int tam){
    int i, j, aux;

    for(i = 1; i < tam; i++){
        aux = v[i];
        
        for(j = i; j > 0 && aux < v[j-1]; j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}
