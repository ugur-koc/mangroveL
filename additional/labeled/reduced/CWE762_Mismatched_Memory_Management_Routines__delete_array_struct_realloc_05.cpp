#include "std_testcase.h"
static int staticTrue = 1; 
static int staticFalse = 0; 
static void goodB2G1()
{
    twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        data = NULL;
        data = (twoIntsStruct *)realloc(data, 100*sizeof(twoIntsStruct));
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
69:9:Potential leak of memory pointed to by 'data'------        printLine(Benign, fixed string);
---fp-reduced---