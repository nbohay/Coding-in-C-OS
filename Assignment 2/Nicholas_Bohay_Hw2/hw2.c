//Nicholas Bohay
//2-23-2017
//Homework 2 C-Code

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>		//needed for the use of threads
#include <math.h>		//needed to use sqrt function in the Sieve	

int num;
void *PrimeNumbers(){
	int array[num];					//instantiates an array of number provided
	int ch;
	ch= (sizeof(array)/sizeof(int))+1;		//needed to find the size of the array in bytes over the size of the integer in bytes
	
	for (int i=2; i <= sqrt(num); i++){		//implements the Sieve of Eratosthenes 
		for(int j=i*i; j<=num; j+=i){
			array[j]=1;			//tags value of 1 if multiple of number 
		}	
		
	}	
	
	printf("The prime numbers lower than %d are: \n", num);
	for (int k=2; k< ch; k++){				//prints out values in array that are not flagged as 1
		if (array[k]!=1){	
			printf("%d\n", k);
		}
	}
	pthread_exit(NULL);					//exits thread

}
int main(){
	
	pthread_t thread1;
	printf("Enter a number: ");					//asks user for input 
	scanf("%d", &num);						//assigns an int num to number provided
	
	
	int rc=pthread_create(&thread1, NULL, PrimeNumbers, NULL);	//creates the thread with thread id thread1 and its running the PrimeNumbers function
	if (rc){							//ascertains if it is created or not
		printf("Error");
		exit(-1);
	}
	pthread_join(thread1,NULL);					//waits for user input thread to finish
	pthread_exit(NULL);						//exits this thread
}


