
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <linux/ioctl.h>

#define TEF6638_IOC_MAGIC     'k'
#define TEF6638_IOCSETCMD     _IOW(TEF6638_IOC_MAGIC,  1, int)
#define TEF6638_IOCGETNUM     _IOR(TEF6638_IOC_MAGIC,  2, int)
#define TEF6638_IOCCMDSIZE    _IOWR(TEF6638_IOC_MAGIC, 3, int)
#define TEF6638_IOC_MAXNR     3


static unsigned char str2hexnum(unsigned char c)
{
	if(c >= '0' && c <= '9')
		return c - '0';
	if(c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if(c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return 0; /* foo */
}

static unsigned long str2hex(unsigned char *str)
{

	int value = 0;
	while (*str) {
		value = value << 4;
		value |= str2hexnum(*str++);
	}
	return value;
}

static int tef6638_send_cmd(char i2c_cmd[], int array_size){
	int fd, ret;
	char fn[256];

	printf("[Antec] tef6638_send_cmd()\n");

	snprintf(fn, sizeof(fn), "/proc/tef6638_dev");

	fd = open(fn, O_RDWR);
	if (fd < 0) {
		printf("[Antec] open %s failed\n", fn);
		close(fd);
		return -1;
	}

	// 0xF24300 -> Vol_ScalSwR
	// set cmd size
	// set val -> 07EF
	ret = array_size;// size 5
	if (ioctl(fd, TEF6638_IOCCMDSIZE, &ret) < 0) {
		printf("[Antec] send command size %d failed\n", ret);
		close(fd);
		return -1;
	}

#if 0
	char i2c_cmd[5];
	i2c_cmd[0] = 0xF2;
	i2c_cmd[1] = 0x43;
	i2c_cmd[2] = 0x00;
	i2c_cmd[3] = 0x07;
	i2c_cmd[4] = 0xEF;
#ifdef ANTEC_IOCTL_DEBUG
	printf("[Antec] send command:\n");
	int i = 0;
	for (i = 0 ; i < sizeof(i2c_cmd) ; i++)
		printf("0x%02x", i2c_cmd[i]);
#endif

	if (ioctl(fd, TEF6638_IOCSETCMD, &i2c_cmd) < 0) {
		printf("[Antec] send command %s failed\n", i2c_cmd);
		//close(fd);
		//return -1;
	}

	/*
	char tmp[128];
	snprintf(tmp, sizeof(tmp), "0xF2430007EF");
	//printf("[Antec] send command %s \n", tmp);
	if (ioctl(fd, TEF6638_IOCSETCMD, &tmp) < 0) {
		printf("[Antec] send command %s failed\n", tmp);
		//close(fd);
		//return -1;
	}
	*/

	/* get 
	ret = 0;
	if (ioctl(fd, TEF6638_IOCGETNUM, &ret) < 0) {
		printf("[Antec] get num failed\n");
		//close(fd);
		//return -1;
	}
	printf("[Antec] get num =%d\n", ret);
	*/
#else
	if (ioctl(fd, TEF6638_IOCSETCMD, &i2c_cmd) < 0) {
		printf("[Antec] send command %s failed\n", i2c_cmd);
		//close(fd);
		//return -1;
	}

#endif

	close(fd);
	return 0;
}

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
	snprintf(fn, sizeof(fn), "/etc/firmware/tef6638_init.txt");
	//snprintf(fn, sizeof(fn), "tef6638_init.txt");

	file = fopen(fn, "r");
	if (file) {
		//while (!feof(file)) 
		while (fgets(buf, sizeof(buf), file)) 
		{
			// buf -> F2 02 9F 00 15 D8
			//fgets(buf, sizeof(buf), file);  
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

					char dst[2];
					strncpy(dst, substr, 2);
					//printf("%s\n", dst);

					unsigned int uisize=0;
					uisize = str2hex(dst);
					//printf("0x%02x\n", uisize);

					array_count++;
					tef6638_i2c_cmd[array_count] = uisize;
					printf("0x%02x\n", (unsigned char)tef6638_i2c_cmd[array_count]);
				}
				substr = strtok_r(NULL, delim, &saveptr);
			} while (substr);

			tef6638_send_cmd(tef6638_i2c_cmd, array_length);
#if 0
			int i = 0;
			for(i = 0 ; i <= array_length ; i++){
				printf("0x%02x\n", (unsigned char)tef6638_i2c_cmd[i]);
			}
#endif

		} 
		fclose(file);
	}
	return 0;
}

