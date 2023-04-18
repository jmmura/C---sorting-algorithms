#include <stdlib.h>
#include <limits.h>
#include "Sort.h"

static void merge(int *A,size_t p,size_t q,size_t r){
size_t n1=q-p+1;
size_t n2=r-q;
int L[n1+1], R[n2+1];
size_t i,j;
for(i=0;i<n1;i++){
    L[i]=A[p+i];
}
for(j=0;j<n2;j++){
    R[j]=A[q+j+1];
}
L[n1]=INT_MAX;
R[n2]=INT_MAX;
i=j=0;
for(size_t k=p;k<=r;k++){
    if(L[i]<=R[j]){
        A[k]=L[i];
        i++;
    }
    else{
        A[k]=R[j];
        j++;
    }
}
}

static void MergeSort(int *A,size_t p,size_t r){
if(p<r){
    size_t q = (p+r)/2;
    MergeSort(A,p,q);
    MergeSort(A,q+1,r);
    merge(A,p,q,r);
}
}

void sort(int *A, size_t n){
MergeSort(A,0,n-1);
}
