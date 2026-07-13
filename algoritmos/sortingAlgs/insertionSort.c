//complexity: 
// - O(n), best case (array is sorted)
//- O(n^2), worst case (array is sorted in inverse way)
// - O(n^2), intermediate case 

/*O algoritmo percorre o array e pra cada posição X ele verifica se aquele elemento está na posição certa. Isso é feito andando para o começo
do array a partir da posição X e movimentando uma posição para frente os valores que são maiores do que o valor da posição X*/

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
