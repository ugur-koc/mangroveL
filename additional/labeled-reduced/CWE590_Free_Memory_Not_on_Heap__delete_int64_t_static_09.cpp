 #include "std_testcase.h"
static void goodG2B2()
{
    int64_t * data;
    data = NULL; 
    if(GLOBAL_CONST_TRUE)
    {
        {
            int64_t * dataBuffer = new int64_t;
            *dataBuffer = 5LL;
            data = dataBuffer;
        }
    }
    printLongLongLine(*data);
    delete data;
}
/* Warning description
Dereference of null pointer (loaded from variable 'data')------    printLongLongLine(*data);
*/

--fp-r--