#include "std_testcase.h"
static void goodG2B1()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int *)malloc(100*sizeof(int));
    }
    if(GLOBAL_CONST_TRUE)
    {
        free(data);
    }
}
110:1:Potential leak of memory pointed to by 'data'------}

---fp-reduced---