#include <stdio.h>
#include <stdlib.h>


void Bubble_Sort(int *A, int ini, int N)
{
    int i, j, aux;
    for(i=ini; i<N; i++) {
        for(j=i+1; j<N; j++) {
            if(*(A+j)<*(A+i)) {
                aux = *(A+j);
                *(A+j) = *(A+i);
                *(A+i) = aux;
            }
        }
    }
}


void Ordena_Linha(int *A, int N)
{
    int i;
    for(i=0; i<=N; i++) {
        Bubble_Sort(A, i*N, (i+1)*N);
    }
    return;
//    Bubble_Sort(A, 0*N, 1*N);
//    Bubble_Sort(A, 1*N, 2*N);
//    Bubble_Sort(A, 2*N, 3*N);
}


void Ordena_Matriz(int *A, int N)
{
    Bubble_Sort(A, 0, N*N);
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
    Ordena_Linha(*mat, dim);
    printf("\nA matriz com as linhas ordenadas eh: \n");
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












