#include <omp.h>
int main()
{
   int i, j;
   #pragma omp parallel
   {
      int a = 0;
      int t = omp_get_thread_num();
      if (t > 10) sleep(1);
      #pragma omp for schedule(guided) private(j)
      for (i = 0; i < 100000000; i++) {
         for(j = 0; j < 100; j++)
            a = a + j/4;
      }
   }
}
