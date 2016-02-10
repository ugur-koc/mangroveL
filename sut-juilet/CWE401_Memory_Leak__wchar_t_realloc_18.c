#include <wchar.h>
static void goodB2G()
{
    wchar_t * d;
    d = NULL;
    goto source;
source:
    d = (wchar_t *)realloc(d, 100 * sizeof(wchar_t));
    wcscpy(d, L"A String");
    printWLine(d);
    goto sink;
sink:
    free(d);
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE401_Memory_Leak__wchar_t_realloc_18_good();
    printLine("Finished good()");
     0;
}
