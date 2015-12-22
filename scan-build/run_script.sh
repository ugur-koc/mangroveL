#!/bin/bash

rm a.out > tmp 2>&1;
gcc sample.c > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" == *"error: "* ]]; then
#echo "Does not compile";
   exit 1;
fi

./a.out > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" != *"Done!"* ]]; then
#echo "Test Case Failed";
   exit 1;
fi

scan-build gcc -c sample.c > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" == *"warning:"* ]]; then
   if [[ "$var" == *"warning: Attempt to free released memory"* ]]; then
      #echo "Warning went away";
      exit 0;
   else
      #echo "Warning went away";
      exit 101;
   fi
else
   exit 1;
fi