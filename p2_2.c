#include <stdio.h>
#include <stdlib.h>

typedef enum boleano{
    false = 0,
    true = 1
}Booleano;


Booleano Verifica_Matriz_Magica(const int *A, int N, int K)
{
    int SL[N], SC[N], SDP=0, SDS=0, i, j;
    for(i=0; i<N; i++) {
        SL[i] = 0; SC[i] = 0;
    }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            SL[i] += *(A+N*i+j);
            SC[j] += *(A+N*i+j);
            if(i==j) SDP += *(A+N*i+j);
            if(i+j == N-1) SDS += *(A+N*i+j);
        }
        if(SL[i] != K) return false;
    }
    if(SDP != K || SDS != K) return false;
    for(i=0; i<N; i++)
        if(SC[i] != K) return false;
    return true;
}


int main(void)
{
    int dim, i, j;
    printf("Entre com a dimensão da sua matriz quadrada: ");
    scanf("%d", &dim);
    printf("Entre com os valores da matriz: \n");
    int mat[dim][dim];
    for(i=0; i<dim; i++)
        for(j=0; j<dim; j++) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    printf("A matriz digitada foi: \n");
    for(i=0; i<dim; i++) {
        for(j=0; j<dim; j++)
            printf("[%2d] ", mat[i][j]);
        printf("\n");
    }
    if(Verifica_Matriz_Magica(*mat, dim, 3)) printf("Eh magica!\n");
    else printf("Nao eh magica!\n");
    return 0;
}









