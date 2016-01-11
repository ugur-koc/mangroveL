#!/bin/bash

gcc -c bzip2.c > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" == *"error: "* ]]; then
   #echo "Does not compile!";
   exit 1;
fi

scan-build gcc -c bzip2.c > tmp 2>&1;
var=$(cat tmp);
if [[ "$var" != *": warning: Value stored to 'zPend' is never read"* ]]; then
   #echo "Warning went away!";
   exit 1;
fi

exit 0;
