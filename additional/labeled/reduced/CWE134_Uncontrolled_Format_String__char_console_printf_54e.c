void CWE134_Uncontrolled_Format_String__char_console_printf_54e_goodG2BSink(char * data)
{
    printf(data);
}
40:5:format not a string literal and no format arguments [-Wformat-security]------     printf(data);
---tp-reduced---