#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;
use Math::BigFloat;

my $program=$ARGV[0];
my $tool=$ARGV[1]; #"cppcheck";
my $interestingness=$ARGV[2];#"./test_interest.sh";
my $fileId=$ARGV[2];#"./test_interest.sh";

my @passes = ();
my $passesStr = "";
my $runId = "";

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
#print "$passesStr,$runId,$fileId\n";
`creduce --no-default-passes $passesStr $interestingness $program > log/runlog-$runId.txt`;
if(-e "$program.orig") {
   `mv $program reduced/$program-$runId.c`;
   `mv $program.orig $program`;
}