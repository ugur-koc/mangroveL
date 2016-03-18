static int staticTrue = 1; 
static int staticFalse = 0; 
static void goodB2G1()
{
    char data;
    if(staticTrue)
    {
        data = 'C';
    }
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        printHexCharLine(data);
    }
}
67:9:Function call argument is an uninitialized value------        printHexCharLine(data);
---fp-reduced---