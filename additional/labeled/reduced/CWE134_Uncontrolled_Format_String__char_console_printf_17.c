void CWE134_Uncontrolled_Format_String__char_console_printf_17_bad()
{
    int i,j;
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    for(i = 0; i < 1; i++)
    {
        {
            size_t dataLen = strlen(data);
            if (100-dataLen > 1)
            {
                if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
                {
                    dataLen = strlen(data);
                    if (dataLen > 0 && data[dataLen-1] == '\n')
                    {
                        data[dataLen-1] = '\0';
                    }
                }
                else
                {
                    printLine("fgets() failed");
                    data[dataLen] = '\0';
                }
            }
        }
    }
    for(j = 0; j < 1; j++)
    {
        printf(data);
    }
}
static void goodB2G()
{
    int i,k;
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    for(i = 0; i < 1; i++)
    {
        {
            size_t dataLen = strlen(data);
            if (100-dataLen > 1)
            {
                if (fgets(data+dataLen, (int)(100-dataLen), stdin) != NULL)
                {
                    dataLen = strlen(data);
                    if (dataLen > 0 && data[dataLen-1] == '\n')
                    {
                        data[dataLen-1] = '\0';
                    }
                }
                else
                {
                    printLine("fgets() failed");
                    data[dataLen] = '\0';
                }
            }
        }
    }
    for(k = 0; k < 1; k++)
    {
        printf("%s\n", data);
    }
}
static void goodG2B()
{
    int h,j;
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    for(h = 0; h < 1; h++)
    {
        strcpy(data, "fixedstringtest");
    }
    for(j = 0; j < 1; j++)
    {
        printf(data);
    }
}
void CWE134_Uncontrolled_Format_String__char_console_printf_17_good()
{
    goodB2G();
    goodG2B();
}
void  main(int argc, char * argv[])
{
    srand( (unsigned)time(NULL) );
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_console_printf_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_console_printf_17_bad();
    printLine("Finished bad()");
     0;
}
128:9:format not a string literal and no format arguments [-Wformat-security]------         printf(data);
---tp-reduced---