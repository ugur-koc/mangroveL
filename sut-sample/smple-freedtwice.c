#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
   int z=atoi(argv[1]);
   int * p = (int *)malloc(10 * sizeof(int));
   if ((z % 10) >= 11){ free(p); }
   free(p);
   printf("Done!\n");
   return 0;
}