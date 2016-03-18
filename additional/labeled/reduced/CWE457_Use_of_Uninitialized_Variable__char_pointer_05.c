static int staticTrue = 1; 
static int staticFalse = 0; 
static void goodG2B1()
{
    char * data;
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = "string";
    }
    if(staticTrue)
    {
        printLine(data);
    }
}
105:9:Function call argument is an uninitialized value------        printLine(data);
---fp-reduced---