#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define NAMELEN 16

#define errExitEN(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); \
	} while (0)

threadfunc(void *parm)
{
	sleep(5);          // allow main program to set the thread name
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int s = 0;
	char thread_name[NAMELEN];

	s = pthread_create(&thread, NULL, threadfunc, NULL);
	if(s != 0)
		errExitEN(s, "pthread_create");

	s = pthread_getname_np(thread, thread_name, NAMELEN);
	if(s != 0)
		errExitEN(s, "pthread_getname_np");

	printf("Created a thread. Default name is: %s\n", thread_name);
	s = pthread_setname_np(thread, (argc > 1) ? argv[1] : "THREADFOO");
	if(s != 0)
		errExitEN(s, "pthread_setname_np");

	sleep(2);

	s = pthread_getname_np(thread, thread_name, (argc > 2) ? atoi(argv[1]) : NAMELEN);
	if (s != 0)
		errExitEN(s, "pthread_getname_np");
	printf("The thread name after setting it is %s.\n", thread_name);

	pthread_join(thread, NULL);
	if (s != 0)
		errExitEN(s, "pthread_join");
	printf("Done\n");
	exit(EXIT_SUCCESS);
}

