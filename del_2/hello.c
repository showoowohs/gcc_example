
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

#include "ioc_brook.h"

#if 0
uint8_t* hex_decode(char *in, size_t len, uint8_t *out)
{
	unsigned int i, t, hn, ln;

	for (t = 0,i = 0; i < len; i+=2,++t) {

		hn = in[i] > '9' ? (in[i]|32) - 'a' + 10 : in[i] - '0';
		ln = in[i+1] > '9' ? (in[i+1]|32) - 'a' + 10 : in[i+1] - '0';

		out[t] = (hn << 4 ) | ln;
		printf("%s",out[t]);
	}
	return out;
}
#endif

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

	return value;
}	

int main(int argc, char *argv[])
{
	char array[3];
	array[0] = 0x00;
	array[1] = 0xEF;
	array[2] = 0x22;

	char array2[3];
	array2[0] = "00";
	array2[1] = "EF";
	array2[2] = "0x22";

	//char arry3[3];
	//hex_decode(array2[0], 2, arry3[0]);

	printf("array[0]=0x%x\n", array[0]);
	printf("array[1]=0x%x\n", array[1]);
	printf("array[2]=0x%x\n", array[2]);

	printf("array2[0]=0x%x\n", array2[0]);
	printf("array2[1]=0x%x\n", array2[1]);
	printf("array2[2]=0x%x\n", array2[2]);

	unsigned int uisize=0;
	uisize = str2hex(array2[2]);

	printf("0x%x\n", uisize);

	//https://github.com/houwentaoff/powerpc_i2c_temp/blob/master/fun_test/str2hex.c
}

