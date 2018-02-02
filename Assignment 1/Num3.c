//Nicholas Bohay
//Homework 1 Problem 3
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>			//necessary for exit command
#include <ctype.h>			//for islower, toupper, tolower commands
#include <sys/wait.h>			//necessary for wait command

int id, fd[2],pfd[2];			//ints for process id, and pipes either 0 or 1 
char word[] = "Hello\n";		//initial message from child to parent
char readbuf[10];			//buffer string for parent reading
char cread[10];				//buffer string for child reading

int main(void){
    pipe(fd);				//pipe1
    pipe(pfd);				//pipe2
    id = fork();				//forks process

    if (id==-1){
        printf("Fork Failed");
    }

    if(id==0){
        close(fd[0]);			 //closes reading in pipe1
        write(fd[1], word, (sizeof(word)));	//sends string to parent
        printf("Child wrote: %s", word);	//prints what was sent to parent
        close(pfd[1]);			//closes writing in pipe2
        read(pfd[0], cread, sizeof(cread));	//reads what was sent from parent
        printf("Child received: %s", cread);	//confirms the parent message
        exit(0);
    }

    else{
        close(fd[1]); 			//closes writing in pipe1
        read(fd[0], readbuf, sizeof(readbuf));	//receiving info from child		
        printf("Parent received: %s",readbuf);  //confirm what was sent from parent

        for(int i=0; i<sizeof(readbuf); i++){	//changes the cases of the transmitted letters

	        if (islower(readbuf[i])){
		        readbuf[i]=toupper(readbuf[i]);}
	        else{
		        readbuf[i]=tolower(readbuf[i]);}
        }

        close(pfd[0]);			//closes reading in pipe2
        write(pfd[1],readbuf,(sizeof(readbuf))); //sends string to child process
        printf("Parent Wrote: %s", readbuf);	//prints what was sent to child

        wait(NULL);				//wait for child to finish
    }
    return (0);

}
