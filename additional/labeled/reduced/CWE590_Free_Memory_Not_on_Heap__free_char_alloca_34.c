#include "std_testcase.h"
typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE590_Free_Memory_Not_on_Heap__free_char_alloca_34_unionType;
static void goodG2B()
{
    char * data;
    CWE590_Free_Memory_Not_on_Heap__free_char_alloca_34_unionType myUnion;
    data = NULL; 
    {
        char * dataBuffer = (char *)malloc(100*sizeof(char));
        if (dataBuffer == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        memset(dataBuffer, 'A', 100-1); 
        dataBuffer[100-1] = '\0'; 
        data = dataBuffer;
    }
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        printLine(data);
        free(data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE590_Free_Memory_Not_on_Heap__free_char_alloca_34_good();
    printLine("Finished good()");
     0;
}
74:9:Potential leak of memory pointed to by 'myUnion.unionFirst'------        char * data = myUnion.unionSecond;
---fp-reduced---