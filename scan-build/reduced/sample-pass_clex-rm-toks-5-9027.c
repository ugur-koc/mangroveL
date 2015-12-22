#include <stdlib.h>
#include <stdio.h>

void foo() {
   int * p = (int *)malloc(10 );
   int r = rand() % 10;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!\n");
}

void bar() {
   }

int main() {
   foo();
   ;
   return 0;
}