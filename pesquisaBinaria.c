int busca_binaria_iterativa(int A[], int size, int chave){
    int ini = 0, fin = size - 1, meio;

    while(ini <= fin){
        meio = (ini+fin)/2;
        if(chave == A[meio])
            return meio;
        if(chave < A[meio])
            fin = meio - 1;
        else
            ini = meio + 1;
    }
    return -1;

}

int busca_binaria_recursiva(int *A, int ini, int fin, int chave){
    int meio = (ini+fin)/2;
    if(*(A+meio) == chave)
        return meio;
    if(ini>=fin)
        return -1;
    if(*(A+meio) < chave)
        return busca_binaria_recursiva(A, meio+1, fin, chave);
    else
        return busca_binaria_recursiva(A, ini, meio-1, chave);

}
