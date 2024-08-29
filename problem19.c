#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
static inline uint64_t rdtsc(){
unsigned int lo,hi;
asm volatile ("rdtsc": "=a"(lo), "=d"(hi));
return ((unsigned long long)hi <<32) |lo;
}
int main(){
unsigned long long start,end;
pid_t pid;
start=rdtsc();
pid=getpid();
end=rdtsc();
printf("pID : %d\n",pid);
printf("time taken by getpid() is :%llu \n",(end-start));
return 0;
ll;
}

