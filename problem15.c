/*
name: SHAIK MOHAMMAD IRFAN
ROLL:MT2024138
problem statement:write a program to display the environmental variables of the user
*/
#include<stdio.h>
extern char **environ;
int main(){
char ** env =  environ;
while(*env){
printf("%s\n",*env);
env++;
}
return 0;
}
