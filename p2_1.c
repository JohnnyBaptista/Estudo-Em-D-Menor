#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef enum boleano{
    false = 0,
    true = 1,
}Boleano;


short Verifica_Matriz_Permutacao( int *A, int N)
{
    int i, j, somLinhas[N], somCols[N];
    for(i=0; i<N; i++) {
        *(somLinhas+i) = 0;
        *(somCols+i) = 0;
    }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            *(somLinhas+i) += *(A+N*i+j);
            *(somCols+j) += *(A+N*i+j);
        }
        if(*(somLinhas+i)!=1) return 0;
    }
    for(j=0; j<N; j++) {
        if(*(somCols+j) != 1) return 0;
    }
    return 1;
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
    for(i=0; i<dim; i++) {
        for(j=0; j<dim; j++)
            printf("[%2d] ", mat[i][j]);
        printf("\n");
    }
    if(Verifica_Matriz_Permutacao(*mat, dim)) printf("É de permutação!\n");
    else printf("Não é de permutação!\n");

    return 0;
}



