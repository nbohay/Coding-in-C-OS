#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int num;
void *PrimeNumbers(){
	int array[num];
	int ch;
	ch= (sizeof(array)/sizeof(int))+1;	//needed to find the size of the array over 4
	int j,k;
	
	for (int i=2; i <= sqrt(num); i++){
		if(array[i]==0){
			for(int j=i*i; j<=num; j+=i){
				array[j]=1;
			}	
		}
	}	
	
	printf("The prime numbers are:");
	for (int k=2; k< ch; k++){
		if (array[k]==0){	
			printf("%d", k);
	}}
	printf("You entered: %d\n", num);
	pthread_exit(NULL);

}
int main(){
	
	pthread_t thread1;
	int rc;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	
	rc=pthread_create(&thread1, NULL, PrimeNumbers, NULL);
	if (rc){
		printf("Error");
		exit(-1);
	}
	pthread_join(thread1,NULL);
	return 0;
	pthread_exit(NULL);
}


