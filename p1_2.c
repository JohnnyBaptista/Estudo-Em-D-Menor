#include <stdio.h>
#include <stdlib.h>

void Uniao(int Pa[], int Pb[], int M, int N, int Uniao[], int *Qu);
void bubbleSort(int A[], int N);

int main(void)
{
    int tam1, tam2, tam3;
    printf("Entre com o tamanho do seu vetor1: \n");
    scanf("%d", &tam1);
    fflush(stdin);
    printf("Entre com o tamanho do seu vetor2: \n");
    scanf("%d", &tam2);
    fflush(stdin);
    tam3 = tam1+tam2;
    int vet1[tam1], vet2[tam2], uniao[tam3], i;

    printf("Entre com os valores do seu 1o vetor: \n");
    for(i=0; i<tam1; i++) {
        scanf("%d", &vet1[i]);
        fflush(stdin);
    }
    printf("Entre com os valores do seu 2o vetor: \n");
    for(i=0; i<tam2; i++) {
        scanf("%d", &vet2[i]);
        fflush(stdin);
    }
    bubbleSort(vet1, tam1);
    bubbleSort(vet2, tam2);

    Uniao(vet1, vet2, tam1, tam2, uniao, &tam3);

    for(i=0; i<tam3; i++) printf("uniao[%d] = %d\n", i, uniao[i]);

    return 0;
}

void Uniao(int Pa[], int Pb[], int M, int N, int Uniao[], int *Qu)
{
    *Qu = M+N;
    int i=0, j=0, k=0;

    while(k<*Qu && j<N && i<M) {
        if(*(Pa+i) >= *(Pb+j)) {
            *(Uniao+k) = *(Pb+j);
            j++;
        } else {
            *(Uniao+k) = *(Pa+i);
            i++;
        }
        k++;
    }
    while(i<M) {
        *(Uniao+k) = *(Pa+i);
        i++;
    }
    while(j<N) {
        *(Uniao+k) = *(Pb+j);
        j++;
    }
    return;
}

void bubbleSort(int A[], int N)
{
    int i, j, aux;
    for(i=1; i<N; i++) {
        for(j=0; j<N-i; j++) {
            if(A[j]>A[j+1]) {
                aux = A[j+1];
                A[j+1] = A[j];
                A[j] = aux;
            }
        }
    }
    return;
}







