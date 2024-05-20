#include <stdlib.h>
#define X 1000000

int main() {
   int i, j, **m;
   m = malloc(900 * sizeof(int*));
   for (i = 0; i < 900; i++)
      m[i] = malloc(X * sizeof(int));
   for(i = 0; i < 900; i++)
      for(j = 0; j < X; j++)
         switch (i) {
            case 0 ... 299: m[i][j] = 0; break;
            case 300 ... 599: m[i][j] = 1; break;
            default: m[i][j] = 2; break;
         }
   return 0;
}
