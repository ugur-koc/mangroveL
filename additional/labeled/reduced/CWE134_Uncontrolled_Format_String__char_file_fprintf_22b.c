#include "std_testcase.h"
extern int CWE134_Uncontrolled_Format_String__char_file_fprintf_22_goodG2BGlobal;
void CWE134_Uncontrolled_Format_String__char_file_fprintf_22_goodG2BSink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_file_fprintf_22_goodG2BGlobal)
    {
        fprintf(stdout, data);
    }
}
78:9:format not a string literal and no format arguments [-Wformat-security]------         fprintf(stdout, data);
---tp-reduced---