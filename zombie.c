#include<stdio.h>
#include<unistd.h>
int main()
{
 int status;
 pid_t pid;
 pid=fork();
 if(pid==0)
 {
  printf("I am child of my id is %d of my parent id is %d",getpid(),getppid()); 
 }
 return 0;
}
