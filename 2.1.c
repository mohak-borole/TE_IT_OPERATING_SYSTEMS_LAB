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
        sleep(10);   
        /*  the process sleeps for 3 seconds so that next process is executed.
            It does not wait for the child process to finish. It exits after 3 Sec
            
            We Add sleep in child so that the parent terminates first and thus forming a ORPHAN process*/
        printf("Child Process having id: %d\n" , getpid());
        printf("My parent process' id is: %d\n", getppid());
    }
    else    //Parent process
    {
        //wait(NULL); 
        /*  the parent process waits for the child process to execute its code.
            The wait call waits till the state of child process is not changed.
            
            */

        sleep(10);
        /*  the sleep in parent process ends the child process thus creating a ZOMBIE PROCESS*/
        printf("Parent process having id: %d\n" , getpid());
        printf("My Child process' id is: %d\n" , q);
    }
    printf("Common Part\n");
}