#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define tam 100000

struct hash
{
    int chave;
    struct hash* proximo;
};

int funcao_hash(int chave);
int inserir(struct hash* tabela[], int n);
struct hash *buscar(struct hash* tabela[], int valor);
void inicializarAleatoriamente(int v[], int n);


void main(){
    srand(time(NULL));
    struct hash* tabela[tam];
    double start, stop, elapsed;
    int i, A[tam];

    inicializarAleatoriamente(A, 95000);

    // ========================== INSERCAO - INICIO  ==========================//
    start = (double)clock() / CLOCKS_PER_SEC;
    for (i = 0; i < tam; i++)
        inserir(tabela,A[i]);

    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nHash lista encadeada: Tempo de insercao = %f\n", elapsed);
    // ========================== INSERCAO - FIM  ==========================//



    // ========================== BUSCA - INICIO  ==========================//
    start = 0;
    stop = 0;

    start = (double)clock() / CLOCKS_PER_SEC;
    for (i = 0; i < 95000; i++)
        buscar(tabela,A[i]);

    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nHash lista encadeada: Tempo de busca = %f\n", elapsed);
	// ========================== Busca - FIM  ==========================//

    printf("\n\n");
}


int funcao_hash(int chave){
    return chave % tam;
}

int inserir(struct hash* tabela[], int n){
    int pos = funcao_hash(n);
    struct hash* novo;
    novo = (struct hash*) malloc(sizeof(struct hash));;
    novo->proximo = tabela[pos];
    novo->chave = n;
    tabela[pos] = novo;

    return 1;
}

struct hash *buscar(struct hash* tabela[], int valor)
{
    int pos = funcao_hash(valor);
    struct hash* aux;
    aux = tabela[pos];
    while (aux != NULL)
    {
        if(aux->chave == valor)
        {
            //printf("Elemento: %d Posicao: %d \n", aux->chave, pos);
            return aux;
        }
        else
            aux=aux->proximo;
    }
    //printf("Nao encontrado \n");
    return aux;

}


void inicializarAleatoriamente(int v[], int n){
    int i;
    for (i = 0; i < n; i++)
        v[i] = rand();
}
