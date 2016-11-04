#include <pthread.h>
#include <errno.h>
#include "error_functions.h"


static void *threadfunc(void *parm)
{
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread;

#ifdef NOT_SUGGEST
	errno = pthread_create(&thread, NULL, threadfunc, &argv);
	if(errno != 0)
		errExit("pthread_create");
#else// book suggest
	int s = 0;
	s = pthread_create(&thread, NULL, threadfunc, &argv);
	if(s != 0)
		errExitEN(s, "pthread_create");
#endif
	pthread_join(thread, NULL);
	return 0;

}

