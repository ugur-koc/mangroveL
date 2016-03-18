static void goodG2B()
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char * dataBadBuffer = (char *)ALLOCA(50*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA(100*sizeof(char));
    memset(dataBadBuffer, 'A', 50-1); 
    dataBadBuffer[50-1] = '\0'; 
    memset(dataGoodBuffer, 'A', 100-1); 
    dataGoodBuffer[100-1] = '\0'; 
    {
        char * data = *dataPtr1;
        data = dataGoodBuffer;
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            char dest[100];
            memset(dest, 'C', 100-1);
            dest[100-1] = '\0'; 
            memcpy(dest, data, strlen(dest)*sizeof(char));
            dest[100-1] = '\0';
            printLine(dest);
        }
    }
}
72:9:Assigned value is garbage or undefined------        char * data = *dataPtr1;
---tp-reduced---