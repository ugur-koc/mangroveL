#include "std_testcase.h"
#define FILENAME "/tmp/file.txt"
static void goodG2B()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        char * data = *dataPtr1;
        strcpy(data, "fixedstringtest");
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        fprintf(stdout, data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_file_fprintf_32_good();
    printLine("Finished good()");
     0;
}
92:9:format not a string literal and no format arguments [-Wformat-security]------         fprintf(stdout, data);
---tp-reduced---