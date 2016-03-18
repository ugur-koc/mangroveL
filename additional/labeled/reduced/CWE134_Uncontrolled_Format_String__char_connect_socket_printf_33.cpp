#include "std_testcase.h"
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"
static void goodG2B()
{
    char * data;
    char * &dataRef = data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    strcpy(data, "fixedstringtest");
    {
        char * data = dataRef;
        printf(data);
    }
}
using namespace CWE134_Uncontrolled_Format_String__char_connect_socket_printf_33; 
int main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    return 0;
}
146:20:format not a string literal and no format arguments [-Wformat-security]------         printf(data);
---tp-reduced---