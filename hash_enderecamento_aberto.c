#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define tam 100000

struct hash{
    int key;
    char f; // L = livre, O = ocupado, R = removido
};

int funcao_hashing(int num);
void mostrar_hash(struct hash tabela[]);
void inserir(struct hash tabela[], int n);
int buscar(struct hash tabela[], int n);
void remover(struct hash tabela[], int n);
void inicializarAleatoriamente(int v[], int n);

void main(){
    srand(time(NULL));
    struct hash tabela[tam];

    double start, stop, elapsed;
    int pos;
    int i, A[tam];

    inicializarAleatoriamente(A, tam);


    for (i = 0; i < tam; i++)
        tabela[i].f = 'L';


    // ========================== INSERCAO - INICIO  ==========================//
    start = (double)clock() / CLOCKS_PER_SEC;
    for (i = 0; i < tam; i++)
        inserir(tabela, A[i]);

    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nHash enderecamento aberto: Tempo de insercao = %f\n", elapsed);
    // ========================== INSERCAO - FIM  ==========================//

    //printf("\nElementos inseridos na tabela Hash:\n");
    //mostrar_hash(tabela);

    // ========================== BUSCA - INICIO  ==========================//
    start = 0;
    stop = 0;

    start = (double)clock() / CLOCKS_PER_SEC;
    for (i = 0; i < tam; i++)
        buscar(tabela,A[i]);

    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;

    printf("\n\nHash enderecamento aberto: Tempo de busca = %f\n", elapsed);
	// ========================== Busca - FIM  ==========================//

    printf("\n\n");
}



int funcao_hashing(int num){
    return num % tam;
}

void mostrar_hash(struct hash tabela[]){
    int i;
    for (i = 0; i < tam; i++)
        if (tabela[i].f == 'O')
            printf("\nEntrada: %i, chave: %i", i, tabela[i].key);
}

void inserir(struct hash tabela[], int n){
    int i = 0, pos = funcao_hashing(n);
    while ((i < tam) && (tabela[(pos + i) % tam].f != 'L'))
        i += 1;
    
    if (i < tam){
        tabela[(pos + i) % tam].key = n;
        tabela[(pos + i) % tam].f = 'O';
    }
    else
        printf("\nTABELA CHEIA!\n");
}

int buscar(struct hash tabela[], int n)
{
    int i = 0;
    int pos = funcao_hashing(n);

    while (i < tam && tabela[(pos + i) % tam].f != 'L' && tabela[(pos + i) % tam].key != n)
        i += 1;
    
    if (tabela[(pos + i) % tam].key == n && tabela[(pos + i) % tam].f != 'R')
        return (pos + i) % tam;
    else
        return tam;
}

void remover(struct hash tabela[], int n){
    int posicao = buscar(tabela, n);
    if (posicao < tam)
        tabela[posicao].f = 'R';
    else
        printf("\nElemento não presente.\n");
}

void inicializarAleatoriamente(int v[], int n){
    int i;
    for (i = 0; i < n; i++)
        v[i] = rand();
}
