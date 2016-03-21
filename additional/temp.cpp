#include <stdio.h>
#include <string.h>

static int globalFive=5;
int main()
{
   char * data;
   data = NULL;
   if(globalFive==5)
   {
      {
         char * dataBuffer = new char[100];
         memset(dataBuffer, 'A', 100-1);
         dataBuffer[100-1] = '\0';
         data = dataBuffer;
      }
   }
   {
      char dest[100];
      memset(dest, 'C', 100-1);
      dest[100-1] = '\0';
      strncpy(dest, data, strlen(dest));
      dest[100-1] = '\0';
      printf("%s",dest);
   }
}