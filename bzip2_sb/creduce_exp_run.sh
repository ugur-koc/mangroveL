#!/bin/bash

for a in 1 2 #3 4 5 6 7 8 9 10
do
   ./creduce_exp.pl bzip2.c scan-build ./test_interest.sh $a
done