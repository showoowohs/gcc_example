#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "errExit.h" 

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{
	/* increment x to 100 */
	int *x_ptr = (int *)x_void_ptr;
	while(++(*x_ptr) < 100);

	printf("x increment finished\n");

	/* the function must return something - NULL will do */
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int x = 0;

	/* show the initial values of x and y */
	printf("x: %d\n", x);
	/* show the default errno */
	printf( "errno is %d\n", errno);

	/* create a thread which executes inc_x(&x)*/
	errno = pthread_create(&thread, NULL, inc_x, &x);
	if(errno != 0)
		errExit("pthread_create");

	pthread_join(thread, NULL);
	printf("x: %d\n", x);
	printf( "errno is %d\n", errno);
}

