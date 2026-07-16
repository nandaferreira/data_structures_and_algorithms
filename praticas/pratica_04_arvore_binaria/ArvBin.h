typedef struct NO* ArvBin; //estrutura de NOs

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin* raiz); //apaga estrutura da arvore
int insere_ArvBin(ArvBin* raiz, int valor); //insere elemento
int remove_ArvBin(ArvBin* raiz, int valor);
int estaVazia_ArvBin(ArvBin* raiz); //remove um elemento
int totalNO_ArvBin(ArvBin* raiz); //contagem de total de NOs da arvore
int altura_ArvBin(ArvBin* raiz); //qual a altura
int consulta_ArvBin(ArvBin* raiz, int valor); //consulta se um elemento X pertence a arvore
void preOrdem_ArvBin(ArvBin* raiz);
void emOrdem_ArvBin(ArvBin* raiz);
void posOrdem_ArvBin(ArvBin* raiz);

