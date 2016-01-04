#include <stdlib.h>
#include <stdio.h>

void foo() {
   int * p = (int *)malloc(10 * sizeof(int));
   int r = rand() % 10;
   r>10;
   
   {
      free(p);
  	}
   free(p);
   (0,0);
}



void  main() {
   ;
   //bar();
    0;
}