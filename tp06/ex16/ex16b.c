#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

const long TOTAL_STEPS = 800000000;
const double DELTA_STEP = 1.0/(double) TOTAL_STEPS;

long min_task = 1000000;

double calc(long from, long to)
{
    const long range = to - from;
    double sum = 0;

    if(range < min_task)
    {
        for (int i = from; i < to; i++)
        {
            const double x = (i + 0.5) * DELTA_STEP;
            sum = sum + 4.0 / (1.0 + x * x);
        }
    }
    else 
    {
        long h = range/2;
        double s1, s2;

        #pragma omp task shared(s1)
        s1 = calc(from, from+h);
        
        #pragma omp task shared(s2)
        s2 = calc(from + h, to);
        
        #pragma omp taskwait
        sum = s1 + s2;
    }

    return sum;
}

void main (int argc, char** argv) 
{
    if(argc>1)
        min_task = strtol(argv[1], NULL, 10);

    printf("En max %d threads, con tarea mínima de %li...\n", omp_get_max_threads(), min_task);

    double sum, tiempoIni, tiempoFin;
    tiempoIni = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        sum = calc(0, TOTAL_STEPS);
    }
    
    double pi = DELTA_STEP * sum;
    tiempoFin = omp_get_wtime();
    printf("PI: %f - Tiempo: %fs\n", pi, tiempoFin - tiempoIni);
}
