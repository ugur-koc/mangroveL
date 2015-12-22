#include <stdlib.h>
#include <stdio.h>

void foo() {
   int * p = (int *)malloc(sizeof(int));
   int r = rand() % 10;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!\n");
}

void bar() {
   printf("Done!\n");
}

int main() {
   foo();
   ;
}