#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 200000000

void vector_add(int *A, int *B, int *C, int n) 
{
   int i;
   for (i = 0; i < n; i++)
      C[i] = A[i] + B[i];
}

void rec_vector_add(int *A, int *B, int *C, int n) 
{
    if(n<=1000000)
        vector_add(A, B, C, n);
    else 
    {
        int h = n/2;
        #pragma omp task
        rec_vector_add(A, B, C, h);
        
        #pragma omp task
        rec_vector_add(A+(n/2), B+h, C+h, n-h);

        #pragma omp taskwait
    }
}

int main() 
{
    int* a = malloc(sizeof(int)*N);
    int* b = malloc(sizeof(int)*N);
    int* c = malloc(sizeof(int)*N);

    for(int i=0; i<N; i++)
    {
        a[i] = 3;
        b[i] = 4;
    }

    #pragma omp parallel
    {
        #pragma omp single
        rec_vector_add(a, b, c, N);
    }

    printf("c[4]=%d\nc[N-1]=%d\n", c[4], c[N-1]);
}