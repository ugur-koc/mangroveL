#include "std_testcase.h"
#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
static int staticFive = 5;
static void goodG2B1()
{
    void * data;
    data = NULL;
    if(staticFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (void *)CHAR_STRING;
    }
    if(staticFive==5)
    {
        {
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)calloc(dataLen+1, 1);
            memcpy(dest, data, (dataLen+1));
            printLine((char *)dest);
            free(dest);
        }
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE135_07_good();
    printLine("Finished good()");
     0;
}
128:30:Null pointer passed as an argument to a 'nonnull' parameter------            size_t dataLen = strlen((char *)data);

---fp-reduced---