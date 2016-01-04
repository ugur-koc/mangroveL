#include <stdlib.h>
#include <stdio.h>





void  main() {
   {
      int * p = (int *)malloc(10 * sizeof(int));
      int r = rand() % 10;
      r>10;
      
      {
         free(p);
     	}
      free(p);
      printf("Done!\n");
   }
   
   ;
   //bar();
    0;
}