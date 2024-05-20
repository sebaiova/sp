
#include <stdlib.h>
#include <stdio.h>

#define N 10000000

float cmp_sum(float* vecn, unsigned n)
{
    float x = 0;
    for(unsigned i=0; i<n; i++)
        x+=vecn[i];

    return x;
}

int main()
{
    float* vecn;
    posix_memalign((void**)&vecn, 32, sizeof(float)*N);
    
    for(unsigned i=0; i<N; i++)
        vecn[i] = i*0.37f; 

    printf("Sumatoria: %f\n", cmp_sum(vecn, N));

    free(vecn);

    return 0;
}
