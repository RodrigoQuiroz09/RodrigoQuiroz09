/**
* Rodrigo Quiroz Reyes - A01026546
* Problem 1 - Administrative Personnel Program
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
               long mtype;       
               char mtext[6];
			   /*As given in the examples the orders did not pass of 5 chars,  
			   so thats the reason of the limited chars
			   */  
};


int main(){
	key_t key=ftok("./file1", 10);
	int queue=msgget(key, 0666|IPC_CREAT);
	struct message m;
	char str[6]; //String length of the order
	m.mtype=1;
	printf("Order to add: ");
	scanf("%s",str); //Inserts the orders
	strcpy(m.mtext, str);
	msgsnd(queue, &m, sizeof(m), 1);

}
