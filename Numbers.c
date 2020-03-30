/**
* Rodrigo Quiroz Reyes - A01026546
* Problem 2 - Random Numbers Parent-Child
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){


	int f=open("./file.txt", O_RDWR| O_CREAT, 0666); //Generic Path

	ftruncate(f,20);
	int *arrayNumbers=(int *)mmap(NULL, 5*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED , f, 0);

	

	pid_t pid=fork();
	if(pid==0){//child code (Generate the random numbers 1-100)
		srand(time(NULL));
		int numbers[5];

		for(int i=0;i<5;i++){
			numbers[i]=rand()%100+1;
		}

		memcpy(arrayNumbers, numbers, 5*sizeof(int));
		
	}else{//parent code (Recieves the numbers and print them)
		wait(NULL);
		printf("The numbers are: ");

		for(int i =0 ; i < 5; i++){
			if(i==0){
				printf("%d",arrayNumbers[i]);
			} else{
				printf(", %d",arrayNumbers[i]);
			}
			
		}
		printf("\n");
	}
	close(f);
	
}