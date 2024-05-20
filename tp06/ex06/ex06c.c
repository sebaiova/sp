#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> 

struct timeval t1, t2;

void trabajo(int id)
{
    printf("%d: Trabajo muy duro...\n", id);
    sleep(1);
    printf("%d: como un esclavo!\n", id);
    sleep(1);
}

int main()
{
    gettimeofday(&t1, NULL);

    int i;
    #pragma omp parallel for
    for(i=0; i<8; i=i+1)
        trabajo(i);

    gettimeofday(&t2, NULL);
    double elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0 + ((t2.tv_usec - t1.tv_usec) / 1000.0);
    printf("%f ms.\n", elapsedTime);

    return 0;
}
