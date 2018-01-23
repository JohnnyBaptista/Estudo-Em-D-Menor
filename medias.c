void medias(const int *A, int n, double *Ma, double *Mg, double *Mrq, double *Mh, double *Dp){
    int i;
    *Ma = *Mrq = *Mh = *Dp = 0;
    *Mg = 1; 
    for(i = 0; i < n; i++){
        *Ma += *(A+i);
        *Mg *= *(A+i);
        *Mrq += pow(*(A+i), 2);
        *Mh += 1/(*(A+i)); 
    }
    *Ma = *Ma/n;
    *Mg = pow((*Mg), 1/n);
    *Mrq = pow((*Mrq)/n, 1/2);
    *Mh = n/(*Mrq);
    *Dp = pow((n*(*Mrq) - (*Ma*(*Ma)/(n*(n-1)))), 1/2);
    
    return;

}
