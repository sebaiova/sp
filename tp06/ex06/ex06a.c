#include <stdio.h>
#include <unistd.h>

void trabajo(int id)
{
    printf("%d: Trabajo muy duro...\n", id);
    sleep(1);
    printf("%d: como un esclavo!\n", id);
    sleep(1);
}

int main()
{
    trabajo(0);
    trabajo(1);
    trabajo(2);
    trabajo(3);
    trabajo(4);
    trabajo(5);
    trabajo(6);
    trabajo(7);
    return 0;
}
