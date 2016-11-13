/*
 * This example copy from stackoverflow
 * http://stackoverflow.com/questions/1865501/c-program-on-linux-to-exhaust-memory
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SZ (1<<12)

int main() {
	int i;
	int gb = 2; // memory to consume in GB

	for (i = 0; i < ((unsigned long)gb<<30)/PAGE_SZ ; ++i) {
		void *m = malloc(PAGE_SZ);
		if (!m)
			break;
		memset(m, 0, 1);
	}
	printf("allocated %lu MB\n", ((unsigned long)i*PAGE_SZ)>>20);
	getchar();
	return 0;
}
