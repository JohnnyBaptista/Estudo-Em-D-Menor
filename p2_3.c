#include <stdio.h>
#include <stdlib.h>


void Ordena_Matriz(int *A, int N)
{
    int i, j, aux, lim=N*N;
    for(i=0; i<lim; i++) {
        for(j=i+1; j<lim; j++) {
            if(*(A+j)<*(A+i)) {
                aux = *(A+j);
                *(A+j) = *(A+i);
                *(A+i) = aux;
            }
        }
    }
    return;
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
    printf("\nA matriz digitada foi: \n");
    for(i=0; i<dim; i++) {
        for(j=0; j<dim; j++)
            printf("[%2d] ", mat[i][j]);
        printf("\n");

    }
    Ordena_Matriz(*mat, dim);
    printf("\nA matriz ordenada eh: \n");
    for(i=0; i<dim; i++) {
        for(j=0; j<dim; j++)
            printf("[%2d] ", mat[i][j]);
        printf("\n");
    }
    return 0;
}













