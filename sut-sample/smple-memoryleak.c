#include <stdio.h>
#include <stdlib.h>

int main()
{
   char * data;
   data = (char *)realloc(data, 100*sizeof(char));
   return 0;
}
