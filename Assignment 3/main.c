//Nicholas Bohay
// Homework 3 Operating Systems
//4-12-2017
/**
 * Script  for testing the barrier implementation.
 *
 * Usage:
 *	./testbarrier <number of threads>
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "barrier.h"

pthread_barrier_t barrier; //initialize the barrier t

void *worker(){ //created the worker class for the threads that prints out a waits for all the threads to finish printing a then prints B.
    printf("A\n");
    pthread_barrier_wait(&barrier); //the barrier is waiting until they all finish and then go on to the next lines
    printf("B\n");
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i;
	static int ret;
    ret=pthread_barrier_init(&barrier, NULL, 5); //initialize the barrier with the 5 threads

	pthread_t workers[number];

	if (ret)
		return -1;

	for (i = 0; i < number; i++) {
		pthread_create(&workers[i], 0, worker, 0);
	}

	for (i = 0; i < number; i++)
		pthread_join(workers[i], 0);

	return 0;
}

