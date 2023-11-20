#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t q;
    q = fork();
    if(q = 0)
    {
        printf("I am child process having ID: %d\n" , getpid());
        execl("/bin/ps" , "ps" , NULL);
    }
    else
     {
        wait(NULL);
        printf("I am parent process having ID: %d\n" , getpid());
    }
}