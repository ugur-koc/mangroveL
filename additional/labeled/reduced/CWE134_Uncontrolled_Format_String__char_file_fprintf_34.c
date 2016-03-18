#include "std_testcase.h"
#define FILENAME "/tmp/file.txt"
typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE134_Uncontrolled_Format_String__char_file_fprintf_34_unionType;
static void goodG2B()
{
    char * data;
    CWE134_Uncontrolled_Format_String__char_file_fprintf_34_unionType myUnion;
    char dataBuffer[100] = "";
    data = dataBuffer;
    strcpy(data, "fixedstringtest");
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        fprintf(stdout, data);
    }
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_file_fprintf_34_good();
    printLine("Finished good()");
     0;
}
90:9:format not a string literal and no format arguments [-Wformat-security]------         fprintf(stdout, data);
---tp-reduced---