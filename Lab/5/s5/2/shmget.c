

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, const char *argv[]) {
  int shmid;
  key_t key = 0x01020304;

  // create 4096 bytes of shared memory
  shmid = shmget(key, 4096, IPC_CREAT);
  if (shmid < 0) {
    fprintf(stderr, "failed to create shm segment\n");
    perror("shmget");
    return -1;
  }

  printf("created %d\n", shmid);
  return 0;
}
