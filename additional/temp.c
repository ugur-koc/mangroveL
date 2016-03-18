#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include "std_testcase.h"

#define BASEPATH "/tmp/"
#define ENV_VARIABLE "ADD"
#define GETENV getenv

#include <iostream>
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
void main()
{
   goodG2B();
}