
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
#define CHUNK 1024 /* read 1024 bytes at a time */
	char buf[CHUNK];
	FILE *file;
	char fn[256];
	char *dupstr;
	char *substr = NULL;
	char *saveptr = NULL;
	const char * const delim = " ";

	// Path
	//snprintf(fn, sizeof(fn), "/etc/firmware/tef6638_init.txt");
	snprintf(fn, sizeof(fn), "tef6638_init.txt");

	file = fopen(fn, "r");
	if (file) {
		while (!feof(file)) 
		{
			// buf -> F2 02 9F 00 15 D8
			fgets(buf, sizeof(buf), file);  
			//printf("%s", buf); //F2 02 9F 00 15 D8

			dupstr = strdup(buf);
			substr = strtok_r(dupstr, delim, &saveptr);// split " "
			//printf("strlen=%d \n", strlen(buf)/3 ); // array size

			int array_length = (strlen(buf) / 3) ;
			char tef6638_i2c_cmd[array_length];
			int array_count = 0;
			do {
				if(strncmp(substr, "\n", 2)){
					//printf("%s\n", substr);

					char dst[sizeof(substr)];
					strncpy(dst, substr, sizeof(substr));
					int value = atoi(dst);

					tef6638_i2c_cmd[array_count++] = value;
					//printf("%x\n", tef6638_i2c_cmd[array_count++]);
				}
				substr = strtok_r(NULL, delim, &saveptr);
			} while (substr);

			//printf("%s\n", tef6638_i2c_cmd[0]);
#if 0
			int i = 0;
			for(i = 0 ; i < array_length ; i++){
				printf("%x\n", tef6638_i2c_cmd[i]);
			}
#endif

		} 
		fclose(file);
	}
	return 0;
}

