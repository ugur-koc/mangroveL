 #include "std_testcase.h"
void goodB2GSink(void * dataVoidPtr);
static void goodB2G()
{
    char * data;
    char * dataBadBuffer = (char *)malloc(sizeof(OneIntClass));
    data = dataBadBuffer;
    goodB2GSink(&data);
}
/* Warning description
Result of 'malloc' is converted to a pointer of type 'char', which is incompatible with sizeof operand type 'class OneIntClass'------    char * dataBadBuffer = (char *)malloc(sizeof(OneIntClass));
*/
/* Warning description
Result of 'malloc' is converted to a pointer of type 'char', which is incompatible with sizeof operand type 'class TwoIntsClass'------    char * dataGoodBuffer = (char *)malloc(sizeof(TwoIntsClass));
*/
/* Warning description
Potential leak of memory pointed to by 'dataBadBuffer'------    char * dataGoodBuffer = (char *)malloc(sizeof(TwoIntsClass));
*/
