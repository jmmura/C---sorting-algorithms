#include <stdlib.h>
#include "Sort.h"

static void swap(int *a,int *b){
int k;
k=*a;
*a=*b;
*b=k;
}

static void OtherSort(int *A, size_t p, size_t r){
size_t n=r-p+1;
if(n>1){
    if(A[p]>A[r])
        swap(&A[p],&A[r]);
    if(n>=3){
        int x=n/3;
        OtherSort(A,p,r-x);
        OtherSort(A,p+x,r);
        OtherSort(A,p,r-x);
    }
}
}

void sort(int *A, size_t n){
OtherSort(A,0,n-1);
}
