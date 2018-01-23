#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef enum boleano{
    false = 0,
    true = 1,
}Boleano;


short Verifica_Matriz_Permutacao(const int *A, int N)
{
    int i, j, somLinhas[N], somCols[N];
    for(i=0; i<N; i++) {
        *(somLinhas+i) = 0;
        *(somCols+i) = 0;
    }
    for(j=0; j<N; j++) {
        for(i=0; i<N; i++) {
            *(somLinhas+j) += *(A+N*j+i);
            *(somCols+i) += *(A+N*j+i);
        }
        if(*(somLinhas+j)!=1) return 0;
    }
    for(j=0; j<N; j++) {
        if(*(A+j) != 1) return 0;
    }
    return 1;

}


int main(void)
{
    int dim, i, j;
    printf("Entre com o tamanho do seu vetor: ");
    scanf("%d", &dim);
    printf("Entre com os valores da matriz: \n");
    int mat[dim][dim];
    for(j=0; j<dim; j++) 
        for(i=0; i<dim; i++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    if(Verifica_Matriz_Permutacao(mat, dim)) printf("É de permutação!\n");
    else printf("Não é de permutação!\n");

    return 0;
}



