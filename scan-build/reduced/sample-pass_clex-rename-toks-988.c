#include <stdlib.h>
#include <stdio.h>

void x0() {
   int * x1 = (int *)malloc(10 * sizeof(int));
   int x2 = rand() % 10;
   if (x2>10){
      free(x1);
  	}
   free(x1);
   printf("Done!\n");
}

void x3() {
   printf("Done!\n");
}

int main() {
   x0();
   //x3();
   return 0;
}