 #include "std_testcase.h"
static void goodG2B2()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    if(globalFive==5)
    {
        data = dataBuffer;
    }
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        strcpy(data, source);
        printLine(data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE124_Buffer_Underwrite__char_alloca_cpy_14_good();
    printLine("Finished good()");
     0;
}
/* Warning description
Function call argument is an uninitialized value------        strcpy(data, source);
*/
