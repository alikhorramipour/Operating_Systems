#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
	int n;
	FILE *server;

	mkfifo(".sv", S_IRUSER | S_IWUSER | S_IWGRP);

	for(;;){
		printf("waiting for client to connect\n");
		server = fopen(".sv", "r");
	}

	for(;;){
		printf("waiting for client data\n");
		int status = fscanf(server, "%d", &n); // blocking operation
		if (status != 1){ // handles the fifo error
			break;
		}
		printf("answer is %d\n", (n * (n+1)) / 2);
	}

	return 0;
}