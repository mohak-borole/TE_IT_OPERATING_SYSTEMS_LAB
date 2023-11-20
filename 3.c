#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);
int num[2] = {3,5};

int main()
{
    pthread_t a_thread; //thread is declared
    void *result;

    pthread_create(&a_thread , NULL , thread_function , (void *)num);  //thread is created
    pthread_join(a_thread , &result);  //process waits for thread to finish.
    printf("Inside Main Program\n");
    printf("thread returned: %s\n" , (char *)result);

    /*for(j = 20; j<25 ; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }*/
}

void *thread_function(void *args)
{
    printf("Inside Thread\n");
    int *x = args;
    int sum = x[0] + x[1];
    printf("Sum is %d\n" , sum);
    pthread_exit("sum calculated");

    /*for(i = 0 ; i < 5 ; i++)
    {
        printf("%d\n" , i);
        sleep(1);
    }*/
}