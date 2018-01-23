void PP1(const int *A, const int *B, int *C, int G1, int G2, int *G3){
    int i, j;
    *G3 = G1+G2;
    for(i = 0; i<(*G3); i++) *(C+i) = 0;
    for(i = 0; i < G1; i++)
        for(j = 0; j < G2; j++)
            *(C+i+j) += ((*(A+i)) * (*(B+j)));

    return;
        
}
