#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char *strerror(int errnum);
	int fd;  
	fd=open("/dev/tty_hci", O_RDWR);  
	if(fd==-1)  
	{  
		perror("open\n");  
		exit(EXIT_FAILURE);  
	}  
}

