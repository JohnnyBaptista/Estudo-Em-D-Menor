void medias(const int *A, int n, double *Ma, double *Mg, double *Mrq, double *Mh, double *Dp){
    int i;
    double mult = 1;
    *Ma = *Mrq = *Mh = *Dp = 0;
    *Mg = 1.0; 
    for(i = 0; i < n; i++){
        *Ma += *(A+i);
        *Mg *= *(A+i);
        *Mrq += (*(A+i)* (*(A+i)));
        *Mh += ((1.0)/(*(A+i)));
    }
    *Ma = *Ma/n;
    *Mg = pow(*Mg, (1.0/n));
    *Mrq = pow((*Mrq)/n, 1.0/2.0);
    *Mh = n/(*Mh);
    *Dp = sqrt((n*(*Mrq)) - (*Ma *(*Ma))/n*(n-1));
    
    return;

}
