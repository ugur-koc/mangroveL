#include "std_testcase.h"
static int staticTrue = 1; 
static int staticFalse = 0; 
static void goodB2G1()
{
    long * data;
    data = NULL;
    if(staticTrue)
    {
        data = (long *)malloc(100*sizeof(long));
    }
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        free(data);
    }
}
67:9:Potential leak of memory pointed to by 'data'------        printLine(Benign, fixed string);

---fp-reduced---