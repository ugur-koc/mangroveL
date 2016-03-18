#include "std_testcase.h"
#define BASEPATH "/tmp/"
#define FOPEN fopen
static char * goodG2BData;
static void goodG2BSink()
{
    char * data = goodG2BData;
    {
        FILE *pFile = NULL;
        pFile = FOPEN(data, "wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}
static void goodG2B()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    strcat(data, "file.txt");
    goodG2BData = data;
    goodG2BSink();
}
void good()
{
    goodG2B();
}
115:5:Address of stack memory associated with local variable 'dataBuffer' is still referred to by the global variable 'goodG2BData' upon returning to the caller.  This will be a dangling reference------    goodG2BSink();
---fp-reduced---