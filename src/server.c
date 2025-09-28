#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ITERATIONS 1000000

int counter = 0;                 // shared counter
pthread_mutex_t counter_lock;    // mutex to protect counter

void *increment(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        //pthread_mutex_lock(&counter_lock);   // enter critical section
        counter++;
        //pthread_mutex_unlock(&counter_lock); // leave critical section
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // initialize mutex
    // if (pthread_mutex_init(&counter_lock, NULL) != 0) {
    //     perror("Mutex init failed");
    //     exit(EXIT_FAILURE);
    // }

    // create two threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);

    // destroy mutex
    pthread_mutex_destroy(&counter_lock);

    return 0;
}
