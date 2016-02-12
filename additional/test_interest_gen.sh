#!/bin/bash

cp /Users/ugurmeryem/Juliet/testcasesupport/std_testcase_io.h . > tmp 2>&1;
cp /Users/ugurmeryem/Juliet/testcasesupport/std_testcase.h . > tmp 2>&1;

gcc -c -I ../../testcasesupport -D OMITBAD file-name > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" == *"error: "* ]]; then
#echo "Does not compile!";
   exit 1;
fi

scan-build gcc -c -I ../../testcasesupport -D OMITBAD file-name > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" != *"warning-description-line1"* ]]; then
   exit 1;
fi

if [[ "$var" != *"warning-description-line2"* ]]; then
exit 1;
fi

exit 0;