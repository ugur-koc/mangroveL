 #include <stdlib.h>
#include <stdio.h>

 foo() {
   int * p = (int *)malloc( sizeof(0));
   int r = rand() % 10;
   if (r>10){
      free(p);
  	}
   free(p);
   printf("Done!\n");
}

 bar() {
   ;
}

 main() {
   foo();
   //bar();
    ;
} 