#!/bin/bash
# this script will be run by creduce in order to determine interestingness
# of reduced programs. it should not take any argument and it should only
# return 0 (interesting) or 1 (not interesting)

# Step 1 of interestingness; we are enforcing creduce to always produce compilable programs
# This step is optional
#update according to your enviroment.
cp /Users/ugurmeryem/Dropbox/mangroveL/sut-juilet/std_testcase_io.h . > tmp 2>&1;
cp /Users/ugurmeryem/Dropbox/mangroveL/sut-juilet/std_testcase.h . > tmp 2>&1;
gcc -c CWE401_Memory_Leak__wchar_t_realloc_18.c > tmp 2>&1;

var=$(cat tmp);
if [[ "$var" == *"error: "* ]]; then
#echo "Does not compile!";
   exit 1;
fi

# Step 2 of interestingness; here we perform our interestingness test
# which is calling the SCA to check the warning under consideration.
# This step is essential
cppcheck CWE401_Memory_Leak__wchar_t_realloc_18.c > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" != *"Common realloc mistake: 'd' nulled but not freed upon failure"* ]]; then
#echo "Warning went away!";
   exit 1;
fi

exit 0;