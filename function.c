//FUN��ES PARA O EXAME DE ATP II:
//vVedovotto

//==========================================================================================

#include <stdio.h>
#include <stdlib.h>

//==========================================================================================

typedef enum boleano{
    false = 0,
    true = 1
}Booleano;

//==========================================================================================

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

//==========================================================================================

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
        i++; k++;
    }
    while(j<N) {
        *(Uniao+k) = *(Pb+j);
        j++; k++;
    }
    return;
}

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

void Remove_Caractere(char *Str, char ch)
{
    int i, j;
    for(i=0; *(Str+i)!= '\0'; i++) {
        if(*(Str+i) == ch) {
                for(j=i ; *(Str+j) != '\0'; j++) {
                    *(Str+j) = *(Str+j+1);
                }
                i--;
        }

    }
    return;
}

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

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

//==========================================================================================

void Ordena_Linha(int *A, int N)
{
    int i;
    for(i=0; i<=N; i++) {
        Bubble_Sort(A, i*N, (i+1)*N);
    }
    return;
}

//==========================================================================================

void Ordena_Matriz(int *A, int N)
{
    Bubble_Sort(A, 0, N*N);
    return;
}
