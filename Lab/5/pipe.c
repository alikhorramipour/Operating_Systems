#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int file_des[2];
	int n;

	scanf("%d", &n);

	if(pipe(file_des) == -1){// handles file error
		perror("pipe()");
		exit("EXIT_FAILURE");
	}

	switch(fork()){
		case -1: // jamd;es fprl errpr
			perror("fork()");
		case 0: // child
			if(close(file_des[0] == -1)){ // close reading side of pipe
				perror("close()");
				exit("EXIT_FAILURE");
			}

		/* child writes to pipe */
		FILE *fw;

		fw = fdopen(file_des[1], "w"); // IMPORTANT convert file descriptor to FILE handler
		fscanf(fr, "%d", &answer);

	}

	/*key_t key = 0x00304340;

	// create 4096 bytes of shared memory
	if (shmid < 0){
		fprintf(stderr, "failed to create shm argument\n");
		perror("shmget");
		return -1;
	}

	printf("created %d\n", shmid);
	return 0;*/
}