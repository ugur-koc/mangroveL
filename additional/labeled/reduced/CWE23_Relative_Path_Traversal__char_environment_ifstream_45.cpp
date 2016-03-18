#include "std_testcase.h"
#define BASEPATH "/tmp/"
#define ENV_VARIABLE "ADD"
#define GETENV getenv
#include <fstream>
using namespace std;
static char * goodG2BData;
static void goodG2BSink()
{
    char * data = goodG2BData;
    {
        ifstream inputFile;
        inputFile.open((char *)data);
        inputFile.close();
    }
}
static void goodG2B()
{
    char * data;
    char dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    strcat(data, "file.txt");
    goodG2BData = data;
    goodG2BSink();
}
void good()
{
    goodG2B();
}
100:5:Address of stack memory associated with local variable 'dataBuffer' is still referred to by the global variable 'goodG2BData' upon returning to the caller.  This will be a dangling reference------    goodG2BSink();
---fp-reduced---