#include <stdlib.h>
#include "Sort.h"

static void swap(int *a, int *b){
int k;
k=*a;
*a=*b;
*b=k;
}


static int partition(int *A,int p,int r){
int pivot=A[r];
int i=p-1;
for(int j=p; j<r;j++){
    if(A[j]<=pivot){
        i++;
        swap(&A[i],&A[j]);
    }
}
swap(&A[i+1],&A[r]);
return i+1;
}


static void QuickSort(int *A,int p,int r){
if(p<r){
    int q=partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
}
}

void sort(int *A, size_t n){
QuickSort(A,0,n-1);
}
