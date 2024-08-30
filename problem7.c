/*
name: problem7.c
author: SHAIK  MOHAMMAD IRFAN 
description: Write a program to copy file1 into file2 ($cp file1 file2).   

date:20th august 2024
*/
#include<stdio.h>
#include<stdlib.h>
int main(int nums,char *args[]){
char ch;
FILE *sourcefile, *targetfile;
if(nums!=3){
fprintf(stderr,"no sufficient arguments");
exit(1);
}
sourcefile=fopen(args[1],"r");
if(sourcefile == NULL){
printf("cannot open the source file %s ",args[1]);
exit(1);
}
targetfile=fopen(args[2],"w");
if(targetfile== NULL){
printf("cannot open the Target File %s",args[2]);
fclose(sourcefile);
exit(1);
}
while((ch=fgetc(sourcefile))!= EOF){
fputc(ch,targetfile);
}
fclose(sourcefile);
fclose(targetfile);
printf("contents copied from File:%s to File:%s successfully\n",args[1],args[2]);
return 0;
}

/*
OUTPUT:
contents copied from File1:pr71.txt to File : pr72.txt successfullty
*/