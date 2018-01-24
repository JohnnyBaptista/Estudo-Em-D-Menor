#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int tam;
    printf("Entre com o tamanho do seu vetor: \n");
    scanf("%d", &tam);
    int vet1[tam], i, j, cont;

    printf("Entre com os valores do seu vetor: \n");
    for(i=0; i<tam; i++) scanf("%d", &vet1[i]);
    cont = SeqCrescenteMax(vet1, tam);
    for(i=0; i<tam; i++) printf("vet[%d] = %d\n", i, vet1[i]);
    printf("A sequencia crescente máxima é: %d\n", cont);
    return 0;
}

int SeqCrescenteMax(const int *A, int N)
{
    int tam=1, cont=1, i;
    for(i=0; i<N; i++) {
        if(A[i]<A[i+1]) cont++;
        else if(cont>tam) {
            tam = cont;
            cont=1;
        }
            else cont=1;
    }
    return tam;
}











