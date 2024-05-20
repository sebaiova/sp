#include <omp.h>

int main()
{
    int i, j, A[1000];
    j = 5;

    for(i = 0; i < 1000; i++) 
    {
        j = 5 + (i*2);
        A[i] = 3 * j * j * j + 2 * j * j + 10 * j + 2;
    }


}

