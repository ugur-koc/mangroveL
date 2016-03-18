#include "std_testcase.h"
void goodG2BSource(char * &data);
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    goodG2BSource(data);
    fprintf(stdout, data);
}
using namespace CWE134_Uncontrolled_Format_String__char_file_fprintf_62; 
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    return 0;
}
56:25:format not a string literal and no format arguments [-Wformat-security]------     fprintf(stdout, data);
---tp-reduced---