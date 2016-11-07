#include <stdio.h>
#include <time.h>
void main(void)
{
	struct timespec ts, te;
	int i = 0;
	time_t all_time=0;
	time_t all_time2=0;
	clock_gettime(CLOCK_REALTIME, &ts);
	while(i++ < 100000000){
		struct timespec ts2, te2;
		clock_gettime(CLOCK_REALTIME, &ts2);
		int j = 0;
		//while(j++ < 10000000)
		clock_gettime(CLOCK_REALTIME, &te2);
		all_time += te2.tv_nsec - ts2.tv_nsec;


		struct timespec ts3, te3;
		clock_gettime(CLOCK_REALTIME, &ts3);
		clock_gettime(CLOCK_REALTIME, &te3);
		all_time2 += te3.tv_nsec - ts3.tv_nsec;
	}
	clock_gettime(CLOCK_REALTIME, &te);
	printf("diff=%lu.%09lu\n", te.tv_sec - ts.tv_sec, te.tv_nsec - ts.tv_nsec);
	printf("all_time=%lu.%09lu\n", all_time/1000000000, all_time%1000000000);
	printf("all_time2=%lu.%09lu\n", all_time2/1000000000, all_time2%1000000000);
}

