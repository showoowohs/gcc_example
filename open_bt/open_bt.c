
#define  _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;  
	int i;  
	char data[256];  
	int retval;  
	printf("start\n");
	fd=open("/dev/hci_tty", O_RDWR);  
	if(fd==-1)  
	{  
		perror("error open\n");  
		exit(-1);  
	}  
	printf("open /dev/hci_tty successfully\n");  
	//    retval=write(fd,"fgj",3);  
	//        if(retval==-1)  
	//            {  
	//                    perror("write error\n");  
	//                            exit(-1);  
	//                                }  
	//                                
	printf("end\n");
}

