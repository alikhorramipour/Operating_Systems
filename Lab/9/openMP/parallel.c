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

#define NUM_THREADS 4

void main () {
	int i, nthreads;
	double pi, sum[NUM_THREADS];
	step = 1.0 / (double) num_steps;
	omp_set_num_threads(NUM_THREADS); 

	clock_t t;
	t = clock();
	srand(time(0));

	#pragma omp parallel{
		int id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) nthreads = nthrds;
		for (int i = id, sum[id] = 0.0; i < num_steps; i = i + nthrds){
			x = (i + 0.5) * step;
			sum[id] += 4.0 / (1.0 + x*x); 
		}
	}
	for (int i=0, pi=0.0; i < nthreads; i++){ 
		pi += step * sum[i];
	} 

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf(" Elapsed seconds = %g\n", time_taken);
}