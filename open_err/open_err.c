#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
#define USE_PERROR
//#define USE_STRERROR
#ifdef USE_PERROR
	void perror(const char *msg);
	int fd;  
	fd=open("/dev/tty_hci", O_RDWR);  
	if(fd==-1)  
	{  
		// if opne is fail, will print a message
		perror("open fail\n");  
		exit(EXIT_FAILURE);  
	}  
#endif
#ifdef USE_STRERROR
	char *strerror(int errnum);
	int fd;  
	fd=open("/dev/tty_hci", O_RDWR);  
	if(fd==-1)  
	{  
		printf( "Error Value is : %s\n", strerror(errno) );
		exit(EXIT_FAILURE);  
	}else // if open file success, will return a message 
		printf( "Error Value is : %s\n", strerror(errno) );
#endif
}

