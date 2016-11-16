#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MUTEX
#define TIME_DIFF

int max = 1000000000;
int sharedResource = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* fooAPI(void* param)
{
	int i;
#ifdef MUTEX
	pthread_mutex_lock(&mutex);
#endif
	printf("Changing the shared resource now.\n");
	for(i = 0; i < max; i++){
		sharedResource += 1;
	}
#ifdef MUTEX
	pthread_mutex_unlock(&mutex);
#endif
	return 0;
}

int main()
{
#ifdef TIME_DIFF
	struct timespec ts, te;
	clock_gettime(CLOCK_REALTIME, &ts);
#endif

	pthread_t thread, thread2;

	pthread_create(&thread, NULL, fooAPI, NULL);
	pthread_create(&thread2, NULL, fooAPI, NULL);

	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);

	printf("loop should run %d ,real run %d\n",max*2, sharedResource);
#ifdef TIME_DIFF
	clock_gettime(CLOCK_REALTIME, &te);
	printf("use time %lu.%09lu\n", te.tv_sec - ts.tv_sec, te.tv_nsec - ts.tv_nsec);
#endif

	return 0;
}
