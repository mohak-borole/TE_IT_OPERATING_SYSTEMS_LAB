#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    pid_t q;
    printf("Before Fork \n");
    q = fork();

    if(q == 0)  //Child Process
    {
        printf("Child Process having id: %d\n" , getpid());
        printf("My parent process' id is: %d\n", getppid());
    }
    else    //Parent process
    {
        wait(NULL); //the parent process waits for the child process to execute its code.
        printf("Parent process having id: %d\n" , getpid());
        printf("My Child process' id is: %d\n" , q);
    }
    printf("Common Part\n");
}