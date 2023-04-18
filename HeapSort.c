#include <stdlib.h>
#include "Sort.h"

static void swap(int *a, int *b){
int k;
k=*a;
*a=*b;
*b=k;
}

static void Max_Heapify(int *A, size_t n, size_t i){
size_t largest=i;
size_t l=2*i;
size_t r=2*i+1;
if(l<n && A[l]>A[i])
    largest=l;
if(r<n && A[r]>A[largest])
    largest=r;
if(largest!=i){
    swap(&A[i],&A[largest]);
    Max_Heapify(A,n,largest);
}
}

static void HeapSort(int *A,int n){
int i;
for(i=(n-2)/2;i>=0;i--)
    Max_Heapify(A,n,i);
for(i=n-1;i>=1;i--){
    swap(&A[i],&A[0]);
    n--;
    Max_Heapify(A,n,0);
}
}

void sort(int *A, size_t n){
HeapSort(A,n);
}
