#include "std_testcase.h"
void CWE124_Buffer_Underwrite__malloc_char_memmove_41_goodG2BSink(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        memmove(data, source, 100*sizeof(char));
        data[100-1] = '\0';
        printLine(data);
    }
}
static void goodG2B()
{
    char * data;
    data = NULL;
    {
        char * dataBuffer = (char *)malloc(100*sizeof(char));
        memset(dataBuffer, 'A', 100-1);
        dataBuffer[100-1] = '\0';
        data = dataBuffer;
    }
    CWE124_Buffer_Underwrite__malloc_char_memmove_41_goodG2BSink(data);
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE124_Buffer_Underwrite__malloc_char_memmove_41_good();
    printLine("Finished good()");
     0;
}
/* Warning description
Potential leak of memory pointed to by 'data'------}
*/
