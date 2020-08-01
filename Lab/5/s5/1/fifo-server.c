#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

/*
 * This program builds a fifo in /tmp then open it and waits for data on it.
 * When data available this program reads it as a number n and calculates n * (n + 1) / 2
 */

int main(int argc, char *argv[]) {
  int n;
  FILE *server;

  mkfifo("/tmp/mamad_fifo_sv", S_IRUSR | S_IWUSR | S_IWGRP);

  for (;;) {
    printf("Waiting for client to connect\n");
    server = fopen("/tmp/mamad_fifo_sv", "r"); // The fifo is ready for read when there is a program that opens it for write.

    for (;;) {
      printf("Waiting for client data\n");
      int status = fscanf(server, "%d", &n); // blocking operation
      if (status != 1) { // handles the fifo error
        break;
      }
      printf("You answer is: %d\n", (n * (n + 1)) / 2);
    }
  }
}
