#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;

my $n =$ARGV[0];

sub selectNSnippets($$){
   my $n =shift;
   my $cmd =shift;
   
   my @snippetList=();
   my $grep_resultStr=$cmd;
   my $find="/home/ukoc/juliet/testcases";
   $find = quotemeta $find;
   my $replace="/Users/ugurmeryem/Juliet/r-testcases";
   $grep_resultStr =~ s/$find/$replace/g;
   #print $grep_resultStr;
   my @grep_result = split("\n", $grep_resultStr);
   foreach (@grep_result) {
      my @lineArr=split("'",$_);
      push(@snippetList, $lineArr[1]);
   }
   
   my $len=scalar @snippetList;
   
   my %selectedLines = ();
   while(keys %selectedLines < $n){
      my $randLine = int(rand($len));
      $selectedLines{$randLine}=$snippetList[$randLine];
   }
   
   foreach (sort keys %selectedLines) {
      my $fileName=$selectedLines{$_};
      `cp $fileName labeled-to-be/`;
      $find="t-testcases";
      $find = quotemeta $find;
      $replace="testcases";
      $fileName =~ s/$find/$replace/g;
      my $destFileName=$fileName;
      $find=".c";
      $find = quotemeta $find;
      $replace="_orig.c";
      $$destFileName =~ s/$find/$replace/g;
      print $fileName."\n";
      `cp $fileName .`;
      #print "$_ : $selectedLines{$_}\n";
   }
   return %selectedLines;
}


selectNSnippets($n, `grep "reduced to:" /Users/ugurmeryem/juliet-logs/*`);