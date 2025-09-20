#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void* worker1(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Woker1: %d \n", i);
        sleep(1);
    }
    return NULL;
}

void* worker2(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Woker2: %d \n", i);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t t1, t2;

    if(pthread_create(&t1, NULL, worker1, NULL) != 0)
    {
        perror("Error creating worker1 thread");
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&t2, NULL, worker2, NULL) != 0)
    {
        perror("Error creating worker1 thread");
        exit(EXIT_FAILURE);
    }
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished");

    return 0;
}