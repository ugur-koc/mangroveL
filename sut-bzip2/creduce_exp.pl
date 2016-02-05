#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;

my $program=$ARGV[0]; # bzip2.c
my $interestingness=$ARGV[1];#"./test_interest.sh";

for (1..10) {
    my $id=Time::HiRes::time();
    my $runDir="runs/run-$id";

    `mkdir $runDir`;
    `cp $program $runDir/$program`;
    `cp $interestingness $runDir/$interestingness`;

    `cd $runDir && time creduce --print-diff $interestingness $program >> runlog.txt 2>&1`;
    `cd $runDir && rm -f $program.orig $interestingness`;

    `rm -fr /tmp/scan-build-2016-*`;
    `rm -fr /tmp/cc*`;
}
