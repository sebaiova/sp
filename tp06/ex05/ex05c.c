#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double sum_array(double arr[][8], size_t n)
{
    double sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i][0];
    return sum;
}

void main () 
{
    long num_steps = 800000000;
    double x, pi;
    double step = 1.0/(double) num_steps;

    int max_threads = omp_get_max_threads();
    printf("Max threads: %d\n", max_threads);

    double arr[max_threads][8];
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for(int i = 0; i < num_steps; i+=max_threads)
        {
            x = (i + 0.5) * step;
            arr[id][0] += 4.0 / (1.0 + x * x);
        }
    }

    double sum = sum_array(arr, max_threads);
    pi = step * sum;

    printf("PI: %f\n", pi);
}