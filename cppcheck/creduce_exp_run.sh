#!/bin/bash

for a in 1 2 3 4 5 6 7 8 9 10
do
   ./creduce_exp.pl CWE401_Memory_Leak__wchar_t_realloc_18.c cppcheck ./test_interest.sh
done