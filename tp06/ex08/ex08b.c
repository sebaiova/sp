#include <omp.h>
int main()
{
   int i, j;
   #pragma omp parallel
   {
      int a = 0;
      #pragma omp for schedule(static) private(j)
      for (i = 0; i < 100000000; i++) {
         if (i % 2 == 0)
            for(j = 0; j < 100; j++)
               a = a + j/4;
      }
   }
}
