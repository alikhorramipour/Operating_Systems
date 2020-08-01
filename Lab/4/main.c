#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

int main() {
	//serialExample();
	forkRandom();
	return 0;
}

void forkRandom() {
	int hist[25] = {0};
	int counter = 0;
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(NULL));
	start = clock();
	pid_t pid;	
	
	for (int i = 0 ; i < 5000 ; i++) {
		pid = fork();
		
		if (pid == 0) {
			counter = 0;
			int tmp;		
			for (int j = 0 ; j < 12 ; j++) {
				tmp = rand() % 101;
				if ( tmp >= 49 ) {
					counter++;
				}else {
					counter--;
				}			

			}
		exit(counter);
		}else{
			int sts;
			wait(&sts);
			int result = WEXITSTATUS(sts);	
			
			result += 12;
			hist[result]++;
		}


	}
	
	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

	//for (int i = 0 ; i < 25 ; i++) {
	//	for (int j = 0 ; j < hist[i] ; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	
	printf("%lf\n", cpu_time_used);


}

void forkExample() {
	pid_t pid;
	int x = 1;

	pid = fork();

	if (pid < 0) {
		perror("fork()");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		printf("chile has x = %d\n", ++x);
		exit(10);
	} else {
		printf("parent has x = %d\n", --x);
		int sts;
		wait(&sts);
		printf("child is dead (%d)\n", WEXITSTATUS(sts));		
	}
	exit(EXIT_SUCCESS);
}

int serialExample() {
	
	int hist[25] = {0};
	int counter = 0;
	clock_t start, end;
	double cpu_time_used;
	
	srand(time(NULL));
	start = clock();
	
	for (int i = 0 ; i < 500000 ; i++) {
		counter = 0;
		int tmp;		
		for (int j = 0 ; j < 12 ; j++) {
			tmp = rand() % 101;
			if ( tmp >= 49 ) {
				counter++;
			}else {
				counter--;
			}			

		}
		
		counter += 12;
		hist[counter]++;
			

	}
	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

	//for (int i = 0 ; i < 25 ; i++) {
	//	for (int j = 0 ; j < hist[i] ; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	
	printf("%lf\n", cpu_time_used);
	
	return 0;
}
