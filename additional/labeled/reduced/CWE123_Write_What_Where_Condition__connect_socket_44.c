typedef struct _linkedList
{
    struct _linkedList *next;
    struct _linkedList *prev;
} linkedList;
typedef struct _badStruct
{
    linkedList list;
} badStruct;
static linkedList *linkedListPrev, *linkedListNext;
static void goodG2BSink(badStruct data)
{
    linkedListPrev = data.list.prev;
    linkedListNext = data.list.next;
    linkedListPrev->next = linkedListNext;
    linkedListNext->prev = linkedListPrev;
}
static void goodG2B()
{
    badStruct data;
    void (*funcPtr) (badStruct) = goodG2BSink;
    linkedList head = { &head, &head };
    data.list.next = head.next;
    data.list.prev = head.prev;
    head.next = &data.list;
    head.prev = &data.list;
    ; 
    funcPtr(data);
}
void CWE123_Write_What_Where_Condition__connect_socket_44_good()
{
    goodG2B();
}
182:5:Address of stack memory associated with local variable 'head' is still referred to by the global variable 'linkedListPrev' upon returning to the caller.  This will be a dangling reference------    funcPtr(data);
---TODO---