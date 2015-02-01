#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <tareador_hooks.h>

void dot_product (long N, double A[N], double B[N], double *acc){
	double prod;
	tareador_disable_object(&*acc);
	*acc=0.0;
      	int i;
 	for (i=0; i<N; i++) {
		tareador_start_task("loop_dot");
		prod = my_func(A[i], B[i]);
		*acc += prod;
		tareador_end_task("loop_dot");
	}
	tareador_enable_object(&*acc);
}
