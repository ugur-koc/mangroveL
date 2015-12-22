#include <stdlib.h>
#include <stdio.h>

void foo() {
   int * p = malloc(10 * sizeof(int));
   int r = rand;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!\n");
}

void bar() {
   ;
}

int main() {
   foo();
   ;
}