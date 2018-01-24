#include <stdio.h>
#include <stdlib.h>
#include <math.h>

short buscaBinariaRec( int *A, int ini, int fim, int chave);
short buscaBinariaIte(int *A, int N, int chave);

int main(void)
{
    int tam;
    printf("Entre com o tamanho do seu vetor: ");
    scanf("%d", &tam);
    int vet[tam], i, chave;
    printf("Entre com os valores do seu vetor para encontrar as medias: \n");
    for(i=0; i<tam; i++) {
        scanf("%d", &vet[i]);
        fflush(stdin);
    }
    printf("Que valor deseja encontrar?  ");
    scanf("%d", &chave);

    if(buscaBinariaIte(vet, tam, chave)) printf("Contem!\n");
    else printf("Nao contem!\n");

    //if(buscaBinariaRec(vet, 0, tam-1, chave)) printf("Contem!\n");
    //else printf("Nao contem!\n");
    return 0;
}

short buscaBinariaRec(int *A, int ini, int fim, int chave)
{
    if(ini>fim) return 0;
    else {
        int meio = (fim+ini)/2;
        if(chave==*(A+meio))   return 1;
        if(chave < *(A+meio))
            return buscaBinariaRec(A, ini, meio-1, chave);
        else    return buscaBinariaRec(A, meio+1, fim, chave);
    }
}

short buscaBinariaIte(int *A, int N, int chave)
{
    int ini, meio, fim;
    ini = 0; fim = N-1; 
    while(ini<=fim) {
        meio = (ini+fim)/2;
        if(*(A+meio)==chave) return 1;
        if(*(A+meio)<chave) ini = meio+1;
        else fim = meio-1;
    }
    return 0;
}








