#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;
use Math::BigFloat;

my $program=$ARGV[0];
my $tool=$ARGV[1]; #"cppcheck";
my $interestingness=$ARGV[2];#"./test_interest.sh";
my $id=Time::HiRes::time();

my @passes = ();
my $passesStr = "";
my $runId = "";

`rm -fr /tmp/scan-build-2016-*`;
`mkdir runs/run-$id`;
`cp $program runs/run-$id/$program`;
`cp $interestingness runs/run-$id/$interestingness`;

open ALL_PASSES,"<all_passes.txt" or die $!;
while (my $line = <ALL_PASSES>){
   $line=~ s/\n//g;
   push(@passes, $line);
   my $prob=int(rand(10));
   #print $prob."\n";
   if ($prob > 5) {
      $passesStr = $passesStr." --add-pass $line";
      $runId=$runId."1";
   }else{      $runId=$runId."0"; }
}

$passesStr=~s/^\s+|\s+$//g;

close ALL_PASSES;

my $logFile="runlog.txt";
#`cd runs/run-$id && echo "$runId" > runlog.txt 2>&1`;
#`cd runs/run-$id && echo "$passesStr" >> runlog.txt 2>&1`;
`cd runs/run-$id && time creduce $interestingness $program >> runlog.txt 2>&1`;
#--no-default-passes $passesStr
