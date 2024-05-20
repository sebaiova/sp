#include <stdio.h>
#include <omp.h>

void main () 
{
    long num_steps = 800000000;
    double step;
    int i;
    double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
   
    pi = step * sum;
    printf("%f\n", pi);
}