 #include "std_testcase.h"
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(globalFive==5)
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            data = dataBuffer;
        }
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        strncpy(data, source, 100-1);
        data[100-1] = '\0';
        printLine(data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE124_Buffer_Underwrite__malloc_char_ncpy_14_good();
    printLine("Finished good()");
     0;
}
/* Warning description
Null pointer passed as an argument to a 'nonnull' parameter------        strncpy(data, source, 100-1);
*/
