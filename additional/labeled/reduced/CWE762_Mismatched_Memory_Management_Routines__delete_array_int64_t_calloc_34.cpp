#include "std_testcase.h"
typedef union
{
    int64_t * unionFirst;
    int64_t * unionSecond;
} unionType;
static void goodB2G()
{
    int64_t * data;
    unionType myUnion;
    data = NULL;
    data = (int64_t *)calloc(100, sizeof(int64_t));
    myUnion.unionFirst = data;
    {
        int64_t * data = myUnion.unionSecond;
        free(data);
    }
}
81:9:Potential leak of memory pointed to by 'myUnion.unionFirst'------        int64_t * data = myUnion.unionSecond;
---fp-reduced---