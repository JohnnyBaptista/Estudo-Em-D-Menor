#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Medias(const int *A, int N, double *Ma, double *Mg, double *Mrq, double *Mh, double *Dp)
{
    int i;
    double soma=0, somaQuad=0, somaH=0, mult=1;
    float div = (1.0)/N;

    for( i=0; i<N; i++) {soma += *(A+i); somaQuad += (*(A+i)*(*(A+i))); somaH += ((1.0)/(*(A+i))); mult *= *(A+i);}
    *Ma = div*soma;
    *Mg = pow(mult, div);
    *Mrq = sqrt(div*somaQuad);
    *Mh = N/somaH;
    *Dp = sqrt( (N*somaQuad - (somaQuad*somaQuad))/((N*N)-N));

    return;
}

int main(void)
{
    int tam, i;
    double ma, mg, mrq, mh, dp;
    printf("Entre com o tamanho do seu vetor: ");
    scanf("%d", &tam);
    int vet[tam];
    printf("Entre com os valores do seu vetor para encontrar as médias: \n");
    for(i=0; i<tam; i++) {
        scanf("%d", &vet[i]);
        fflush(stdin);
    }
    Medias(vet, tam, &ma, &mg, &mrq, &mh, &dp);
    printf(" Ma = %f \n Mg = %f \n Mrq = %f \n Mh = %f \n Dp = %f \n ", ma, mg, mrq, mh);

    return 0;
}










