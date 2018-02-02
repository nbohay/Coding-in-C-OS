//Nicholas Bohay
//Homework #1 Problem 2

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int id;

int main(int argx, char *list[]){               //pointers

	id=fork();                                      //creates fork

	if (id == -1){

		printf("Fork failed!");
	}

	if (id == 0){                                   //child process is created and prints out respective id information
		printf("In child: ");
		printf("My PID = %d ,", getpid());
		printf("my parent PID = %d\n", getppid());

		execv("/bin/ps", list);                         //creates a list of runnning processes 
		printf("%d",list[0][0]);                        //prints list of processes
	}

	else{
		wait(NULL);                                     //waits for child to finish executing
		printf("Child process has completed!\n");       //prints respective id information
		printf("In parent: ");
		printf("Child PID = %d, ", id);
		printf("My PID = %d, ", getpid());
		printf("my parent PID = %d\n", getppid());
	}
	return 0;
}   
