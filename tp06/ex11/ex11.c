#include <omp.h>
#include <stdio.h>
#include <sys/time.h> 

int primo(int n)
{
   int i,res,mitad;
   i = 2;
   res = 1;
   mitad = n / 2;
   while(res != 0 && i <= mitad) {
      res = n % i;
    	 i++;
   }  
   return res;
}


int main()
{
    const int from = 1000;
    const int to = 200000;
    int count = 0;

    #pragma omp parallel
    {
        struct timeval t1, t2;
        gettimeofday(&t1, NULL);

        #pragma omp for reduction(+:count) nowait schedule(guided)
        for(int i=from; i<to; i++)
        {
            count = count + primo(i);
        }

        gettimeofday(&t2, NULL);
        double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0 + ((t2.tv_usec - t1.tv_usec) / 1000.0);
        printf("Thread terminó en %f ms.\n", elapsedTime);
    }
    printf("Entre %d y %d hay %d números primos.\n", from, to, count);
}