 #include <wchar.h>
static int staticFive = 5;
static void goodG2B2()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if(staticFive==5)
    {
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    {
        char dest[50] = "";
        size_t i, dataLen;
        dataLen = strlen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = '\0'; 
        printLine(data);
        free(data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_07_good();
    printLine("Finished good()");
     0;
}
/* Warning description
Assigned value is garbage or undefined------            dest[i] = data[i];
*/

--fp-r--