#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main()

{

  int i=0,n=1;
#pragma omp parallel  private(i, n)

{
 #if defined (_OPENMP)
	n= omp_get_num_threads();
	i = omp_get_thread_num();
 #endif

printf("Hello World from thread %dout of %d\n",i,n);

}
return 0;

}

/* COMPILATION

cc hello.c
export OMP_NUM_THREADS=8
cc -fopenmp hello.c
./a.out

*/

/* OUTPUT

Hello World from thread 2 out of 8
Hello World from thread 3 out of 8
Hello World from thread 6 out of 8
Hello World from thread 4 out of 8
Hello World from thread 5 out of 8
Hello World from thread 0 out of 8
Hello World from thread 1 out of 8
Hello World from thread 7 out of 8

*/

