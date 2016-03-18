#include "std_testcase.h"
static int staticTrue = 1; 
static int staticFalse = 0; 
static void goodB2G1()
{
    int64_t * data;
    data = NULL;
    if(staticTrue)
    {
        data = (int64_t *)calloc(100, sizeof(int64_t));
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