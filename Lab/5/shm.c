#include <stdio.h>
#include <cstdint.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	int shmid;
	key_t key = 0x00304340;

	// create 4096 bytes of shared memory
	if (shmid < 0){
		fprintf(stderr, "failed to create shm argument\n");
		perror("shmget");
		return -1;
	}

	printf("created %d\n", shmid);
	return 0;
}