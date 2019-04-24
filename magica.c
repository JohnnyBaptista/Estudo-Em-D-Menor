int verificaMagica(int *A, int n, int k){

    int i, j, somaLin, somaCol, somaDiagPrinc, somaDiagSec,  aux = (2*n) + 2;
    
    for(i = 0; i < n; i++){
        somaLin = 0;
        somaCol = 0;
        for(j = 0; j < n; j++){
            somaLin += *(A+i*n+j);
            somaCol += *(A+j*n+i);
            if((i+j) == n-1)
                somaDiagSec += *(A+i*n+j);
            if(i == j)
                somaDiagPrinc += *(A+i*n+j);
        }
    }

    printf("Lin %d\nCol %d\nDiagP %d\nDiagSec %d\n", somaLin, somaCol, somaDiagPrinc, somaDiagSec);

    if(somaLin == k && somaCol == k && somaDiagPrinc == k && somaDiagSec == k)
        return 1;
    else
        return 0;

}

void printar(){
    printf("deu bom");
    
}
