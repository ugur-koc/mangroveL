#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;
use File::Slurp qw(read_file write_file);

my $workDir = $ARGV[0];
my $sbLog = $ARGV[1];
my $testScript_gen = "test_interest_gen.sh";
my $testScript = "test_interest.sh";
my $flags="--no-default-passes --add-pass pass_includes 0 0 --add-pass pass_blank 0 1 --add-pass pass_clang_binsrch remove-unused-function 3 --add-pass pass_clang_binsrch replace-function-def-with-decl 33 --add-pass pass_clang remove-namespace 200 --add-pass pass_clang remove-unused-function 220 --add-pass pass_clang return-void 212 --add-pass pass_clang remove-unused-var 223 --add-pass pass_unifdef 0 450 --add-pass pass_comments 0 451";
my %warnings = ();
my $keepNextLine=0;

open SUMM,"<$workDir/$sbLog" or die $!;
my @locDesPair = ();
while (my $line = <SUMM>){
   chomp $line;
   if ($line =~/: warning:/){
      @locDesPair = split(": warning: ", $line);
      $warnings{$locDesPair[0]}=$locDesPair[1];
      $keepNextLine=1;
      next;
   }
   if($keepNextLine==1){
      $line=~ s/\"/\\\"/g;
      $warnings{$locDesPair[0]}=$warnings{$locDesPair[0]} ."------". $line;
      $keepNextLine=0;
   }
}

while(my($k, $v) = each %warnings) {
   if ($v =~ /is never rea/){ next;}
   
   my @fileLine=split(":",$k);
   my $fileName=$fileLine[0];
   
   my @descriptionLines = split("------",$v);
   
   my $data = read_file $testScript_gen, {binmode => ':utf8'};
   $data =~ s/warning-description-line1/$descriptionLines[0]/g;
   $data =~ s/warning-description-line2/$descriptionLines[1]/g;
   $data =~ s/file-name/$fileName/g;
   write_file "$workDir/000$testScript", {binmode => ':utf8'}, $data;
   
   if (-e "$fileName.orig"){
      `cd $workDir && mv $fileName $fileName.$fileLine[1].c && mv $fileName.orig $fileName`;
   }
   `cd $workDir && chmod +x 000$testScript && creduce $flags ./000$testScript $fileName >> acreduce-runlog.txt 2>&1`;
}