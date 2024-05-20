#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main () 
{
    long num_steps = 800000000;
    double x, pi;
    double step = 1.0/(double) num_steps;

    int max_threads = omp_get_max_threads();
    printf("Max threads: %d\n", max_threads);

    double acc = 0;
    double sum = 0;

    #pragma omp parallel reduction(+:sum)
    {
        int id = omp_get_thread_num();
        for(int i = 0; i < num_steps; i+=max_threads)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
    }

    pi = step * sum;
    printf("PI: %f\n", pi);
}