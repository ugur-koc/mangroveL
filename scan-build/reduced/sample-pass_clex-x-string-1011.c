#include <stdlib.h>
#include <stdio.h>

void foo() {
   int * p = (int *)malloc(10 * sizeof(int));
   int r = rand() % 10;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!xx");
}

void bar() {
   printf("xxxxxxx");
}

int main() {
   foo();
   //bar();
   return 0;
}