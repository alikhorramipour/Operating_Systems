// gcc -o omp_helloc -fopenmp omp_hello.c
// export OMP_NUM_THREADS=2
// ./omp_helloc
// Hello World from thread = 0
// Hello World from thread = 1
// Number of threads = 2

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>



static long num_steps = 100000;
double step;
void main (){
	int i;
	double x, pi, sum = 0.0;
	step = 1.0/(double) num_steps;

	clock_t t;
	t = clock();
	srand(time(0));


	for (i=0; i<num_steps; i++){
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	pi = step * sum; 

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf(" Elapsed seconds = %g\n", time_taken);
}