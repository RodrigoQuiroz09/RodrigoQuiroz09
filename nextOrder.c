/**
* Rodrigo Quiroz Reyes - A01026546
* Problem 1 - Mechanic Program
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
               long mtype;      
               char mtext[6];   
};


int main(){
	key_t key=ftok("./file1", 10);
	int queue=msgget(key, 0666|IPC_CREAT);
	struct message m;
	msgrcv(queue, &m, sizeof(m), 1,IPC_NOWAIT);

	if(m.mtype==1){ // Since we declared as our message type 1 in the administrative program that is my parameter to indicate which message is an order
		printf("The next order to attend is: %s\n", m.mtext);
	} else{
		printf("There are not any more orders. You can take a break.\n");
	}
	

}
