//Nicholas Bohay
//Operating Systems
//May 2,2017
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>	//needed to make suresame values are not constantly used in random generations
#include "fifo.h"	//has the fifo function
#include "opt.h"	//has the opt function
#include "lru.h"	//has the lru function

void *fifo();
void *opt();
void *lru();

int main(){
	pageframe=7;	//3 5 7 //changed manually for testing  page reference FRAMES
	srand(time(NULL));	//instatiates the random number
	pgsize=rand()%10;	//creates the random number from 0-9 (page numbers)
	printf("Page Numbers:");
	for (int i;i<pgsize;i++){			
		rmpage[i]=rand()%7+1;	//creates number of random (pages frames random 1-7)		
		printf("%d",rmpage[i]);	//prints the numbers that were generated
	}
	printf("\n");	//move to next line
	printf("\nFifo:\n");
	fifo();	//comment out if dont want any
	printf("\nOptimal:\n"); 
	opt();
	printf("\nLast recently used:\n");
	lru();
}

