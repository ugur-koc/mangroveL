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
      opendir(DIR, "$workDir/$folder") or die $!;
      while (my $subfolder = readdir(DIR)) {
         if($subfolder eq ".." or $subfolder eq "."){ next; }
         #print $folder."/".$subfolder."\n";
         `cd $workDir/$folder/$subfolder && scan-build gcc -c -I ../../../testcasesupport -D OMITBAD *.c`;
      }
   } else {
      #print "$folder\n";
      `cd $workDir/$folder && scan-build gcc -c -I ../../testcasesupport -D OMITBAD *.c`;
   }
}