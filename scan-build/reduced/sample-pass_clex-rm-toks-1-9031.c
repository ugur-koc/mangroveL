#include <stdlib.h>
#include <stdio.h>

foo() {
   int * p = (int *)malloc(10 * sizeof(int));
   int r = rand() % 10;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!\n");
}

bar() {
   ("Done!\n");
}

main() {
   foo();
   //;
}