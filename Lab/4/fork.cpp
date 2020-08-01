#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

/*void forkexample() {
	int x = 1;
	if (fork() == 0)
	printf("Child has x = %d\n", ++x); else
	printf("Parent has x = %d\n", --x);
}*/


int hist[25] = {0}; // used to store results
void createCurve(){
	srand(time(NULL));

	//int hist[25] = {0}; // used to store results
	int counter = 0;
	int rnd = 0;

	for(int i = 0; i < 5000; i++){
		for (int j = 0; j < 12; j++) {
			rnd = rand() % 101;
			//cout << "Generated number is: " << rnd << endl;
			if(rnd >= 49)
				counter++;
			else
				counter--;
			//cout << "Counter number is: " << counter << " and the pointer would be: " << counter + 12 << endl;
		}

		hist[counter + 12]++;
		counter = 0;
	}
}

void printHistogram(int *hist){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < hist[i]; j++)
            cout << "*";
        cout << endl;
    }
}

void forkExample(){
        pid_t pid;
        int x = 1;

        pid = fork();

		if(pid < 0){ // handles fork error
			perror("fork()");
			exit(EXIT_FAILURE);
		} else if (pid == 0){ // child process
			printf("child has x = %d\n", ++x);
			exit(10);
		} else{ // parent process
			printf("parent has x = %d\n", --x);
			int sts;
			wait(&sts);
			printf("child is dead (%d)\n", WEXITSTATUS(sts));
		}
		exit(EXIT_SUCCESS);
}

int main(){
	//forkexample();

	forkExample();
	/*for(int i = 0, sts = 666; i < 5000; i++){
        createCurve();

	}*/
	return 0;
}
