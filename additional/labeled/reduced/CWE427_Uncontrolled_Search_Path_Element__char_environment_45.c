#include "std_testcase.h"
#define NEW_PATH "/bin"
#define PUTENV putenv
#define ENV_VARIABLE "ADD"
#define GETENV getenv
static char * CWE427_Uncontrolled_Search_Path_Element__char_environment_45_goodG2BData;
static void goodG2BSink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_environment_45_goodG2BData;
    PUTENV(data);
}
static void goodG2B()
{
    char * data;
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    strcat(data, NEW_PATH);
    CWE427_Uncontrolled_Search_Path_Element__char_environment_45_goodG2BData = data;
    goodG2BSink();
}
void CWE427_Uncontrolled_Search_Path_Element__char_environment_45_good()
{
    goodG2B();
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE427_Uncontrolled_Search_Path_Element__char_environment_45_good();
    printLine("Finished good()");
     0;
}
88:5:Address of stack memory associated with local variable 'dataBuffer' is still referred to by the global variable 'CWE427_Uncontrolled_Search_Path_Element__char_environment_45_goodG2BData' upon returning to the caller.  This will be a dangling reference------    goodG2BSink();

---fp-reduced---