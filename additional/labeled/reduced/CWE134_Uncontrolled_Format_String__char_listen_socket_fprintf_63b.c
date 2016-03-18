#include "std_testcase.h"
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
void CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_63b_goodG2BSink(char * * dataPtr)
{
    char * data = *dataPtr;
    fprintf(stdout, data);
}
63:5:format not a string literal and no format arguments [-Wformat-security]------     fprintf(stdout, data);
---tp-reduced---