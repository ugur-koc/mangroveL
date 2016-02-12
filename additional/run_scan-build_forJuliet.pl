#!/usr/bin/perl

use strict;
use 5.014;
use warnings;
use Time::HiRes;

my $workDir ="/Users/ugurmeryem/Juliet/testcases"; #$ARGV[0];
my @CWEFolders = ();

opendir(DIR, $workDir) or die $!;
while (my $folder = readdir(DIR)) {
   if($folder eq ".." or $folder eq "."){ next; }
   push(@CWEFolders, $folder);
}

foreach my $folder (@CWEFolders){
   if (-d "$workDir/$folder/s01") {
      next;
      opendir(DIR, "$workDir/$folder") or die $!;
      while (my $subfolder = readdir(DIR)) {
         if($subfolder eq ".." or $subfolder eq "."){ next; }
         `cd $workDir/$folder/$subfolder && scan-build gcc -c -I ../../../testcasesupport -D OMITBAD *1.c > 000-scan-build.log 2>&1`;
         `./run_creduce_forJuliet.pl $workDir/$folder 000-scan-build.log`;
         `cd $workDir/$folder/$subfolder && rm -fr *.o *.orig`;
      }
   } elsif (-e "$workDir/$folder/Makefile"){
      `cd $workDir/$folder && scan-build gcc -c -I ../../testcasesupport -D OMITBAD *1.c > 000-scan-build.log 2>&1`;
      `./run_creduce_forJuliet.pl $workDir/$folder 000-scan-build.log`;
      `cd $workDir/$folder && rm -fr *.o *.orig`;
      exit;
   }
}