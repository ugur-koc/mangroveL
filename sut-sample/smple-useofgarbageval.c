#include <stdlib.h>
#include <stdio.h>

#define LB 256



int main() {
   int yy[256];
   int ll_i=0,i;
   for (i=0; i<LB; i++)   yy[i] = (unsigned char) i;
   for (i=0; i<LB; i++) {
      if (yy[0]==ll_i) {
         printf("hi");
      }
   }
   return 0;
}