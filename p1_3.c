#include <stdio.h>
#include <stdlib.h>

void PP1(const int *P1, const int *P2, int *P3, int G1, int G2, int *G3)
{
    int i, j;
    *G3 = G1+G2;

    for(i=0; i<*G3; i++) *(P3+i) = 0;
    for(i=0; i<G1; i++) {
        for(j=0; j<G2; j++)
            *(P3+i+j) += (*(P1+i)*(*(P2+j)));
    }
    return;
}

int main(void)
{
    int i, tam1, tam2, tam3;
    printf("Multiplicação de polinômios: \n");
    printf("Entre com o tamanho do 1o primeiro polinônio: ");
    scanf("%d", &tam1);
    printf("Entre com o tamanho do 2o primeiro polinônio: ");
    scanf("%d", &tam2);
    printf("Entre com os valores do seu 1o vetor: \n");
    int vet1[tam1], vet2[tam2], vet3[tam1+tam2];
    for(i=0; i<tam1; i++) {
        scanf("%d", &vet1[i]);
        fflush(stdin);
    }
    printf("Entre com os valores do seu 2o vetor: \n");
    for(i=0; i<tam2; i++) {
        scanf("%d", &vet2[i]);
        fflush(stdin);
    }
    PP1(vet1, vet2, vet3, tam1, tam2, &tam3);
    for(i=0; i<tam3; i++) printf("%d = %d\n", i, *(vet3+i));

    return 0;
}





